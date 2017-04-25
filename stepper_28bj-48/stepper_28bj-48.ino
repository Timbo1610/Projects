
/*
 Stepper Motor Control - one revolution
 This is the examply by Tom Igoe delivered with th Arduino IDE.

 Adapted by Stefan Thesen for 28BYJ-48 stepper motor
 https://blog.thesen.eu
 */

#include <Stepper.h>

// Get steps per turn and RPM out of datasheet:
// ============================================
// 5.625/64 deg per step --> 4096 steps for 360 deg
// step relates to half-step sequencing, which means 8 steps
// We use 4 full steps ==> 2048 steps per turn
//
// recommended frequency range 600-1000Hz for 8 half-steps
// 1000Hz/4096 half-steps --> approx 4sec per turn is max speed 
// ==> 15rpm
// Note: actually we will use ~500Hz using the 4 step approach
// but motor will not be able to turn faster.

// Get stepping sequence out of datasheet:
// =======================================
// Stepping sequence as given in datasheet
// this is an 8-step half-step approach
//         Steps
// Wire  1  2  3  4  5  6  7  8
// 1                    x  x  x
// 2              x  x  x 
// 3        x  x  x
// 4     x  x                 x
// 
// We use only even / full steps thus:
//         Steps
// Wire  2  4  6  8
//   1         x  x
//   2      x  x 
//   3   x  x 
//   4   x        x
// 
// Code of Arduino Stepper Lib has implemented:
//         Steps
// Wire  1  2  3  4
//   1         x  x
//   2   x  x      
//   3      x  x 
//   4   x        x
//
// ==> Simple Solution: exchange wire 2&3


const int stepsPerRevolution = 2048;  // here go the 2048 steps
const int stepMultiplieer = 10;
// for your motor

// initialize the stepper library on pins 8 through 11 -> IN1, IN2, IN3, IN4
// as shown above, we need to exchange wire 2&3, which we do in the constructor
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);
int curpos = 0;
int steps;
int duration = 10;
int range = 600;

double secondsPerStep;
long lastStepTime = 0;

boolean enabled = false;

void setup() 
{
  // set the speed at 15 rpm:
  myStepper.setSpeed(10);
  // initialize the serial port:
  Serial.begin(57600);
}

void loop() 
{


  if(enabled)
  {
      
      if(millis() > lastStepTime + secondsPerStep*1000)
      {
        if(range > 0)
          panStep(1);
        else
          panStep(-1);
          
       lastStepTime = millis();
      }
      
      if(abs(curpos) >= abs(range))
      {
        enabled = false;
        Serial.print("finish");
      }
  }


switch (Serial.read()) {

  case 's': //move by x steps
    panStep(Serial.parseInt());
    break;

  case 'd': // duration
    duration = Serial.parseInt();  
    break;

  case 'r': // range
    range = Serial.parseInt();  
    break;

  case 'h': // home
    panStep(-curpos); 
    Serial.println("Home");
    break;

  case 'e'://enable
    if (Serial.parseInt() == 1){
      secondsPerStep = (float)duration / (float)abs(range);

      Serial.print("Starting.....");
      Serial.print(" range: ");
      Serial.print(range);
      Serial.print(" Seconds per step: ");
      Serial.println(secondsPerStep);
      
      enabled = true;
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
      enabled = false;
      digitalWrite(LED_BUILTIN, LOW);
    }
    
    break;
  }

  
}


void panStep(int steps)
{
  myStepper.step(steps * stepMultiplieer);
  curpos = curpos + steps;
  Serial.print(" Current Pos: ");
  Serial.println(curpos);
  
}

