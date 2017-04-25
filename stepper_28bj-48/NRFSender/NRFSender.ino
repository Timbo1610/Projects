#include <SPI.h>
#include "RF24.h"

bool radioNumber = 0;
byte addresses[][6] = {"1Node","2Node"};

long lastmillis = 0;
long refreshrate = 1000;
RF24 radio(6,7);

void setup() {
  // put your setup code here, to run once:
  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_MAX);

  // Open a writing and reading pipe on each radio, with opposite addresses
  if(radioNumber){
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
  }else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
  
  // Start the radio listening for data
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() > lastmillis + refreshrate)
  {
    
    radio.write(millis(), sizeof(unsigned long));
    
    lastmillis = millis();
  }

  
  
  
}
