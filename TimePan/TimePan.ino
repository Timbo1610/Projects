#include <Stepper.h>

const int stepsPerRevolution = 2048;  // here go the 2048 steps
const double stepMultiplieer = 30.6; // 1 step = 1 degree

Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);

int currentPosition;
long lastStepTime = 0;

int captures = 300;
int range = 180; //in degrees
int duration = 3600;


int stepLength = 1;
float secondsPerStep = 1;

boolean enabled = false;

void setup() {
  // set the speed at 10 rpm:
  myStepper.setSpeed(10);
  // initialize the serial port:
  Serial.begin(57600);
}

void loop() {

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

  case 'c': // number of Captures
    captures = Serial.parseInt();  
    break;

  case 'h': // home
    panStep(-currentPosition); 
    Serial.println("Home");
    break;

  case 'e'://enable
    if (Serial.parseInt() == 1){

      stepLength = range / captures;
      secondsPerStep = (float)duration / (float)abs(range);

      Serial.print("Starting.....");
      Serial.print(" range: ");
      Serial.print(range);
      Serial.print(" Seconds per step: ");
      Serial.print (secondsPerStep);
      Serial.print("  Step length:");
      Serial.println(stepLength);
      
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

  
  if(enabled)
  {
      
      if(millis() > lastStepTime + secondsPerStep*1000)
      {
        panStep(stepLength);
        lastStepTime = millis();
      }
      
      if(abs(currentPosition) >= abs(range))
      {
        enabled = false;
        Serial.print("finish");
      }
  }
  
}

  void panStep(int steps)
{
  myStepper.step(steps * stepMultiplieer);
  currentPosition = currentPosition + steps;
  Serial.print(" Current Pos: ");
  Serial.println(currentPosition);
  
}
