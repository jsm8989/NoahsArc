/*
 * Can either run in Arduino Serial monitor or through
 * the script stepper.py
 * 
 * this script is inspired by 
 * https://learn.adafruit.com/adafruit-arduino-lesson-16-stepper-motors/arduino-code.
 *
 *
 * Currently, this works with an arudino uno (https://store.arduino.cc/products/arduino-uno-rev3/)
 * and controls a single stepper motor (specifically 28BYJ-48 5V Stepper Motor + ULN2003 Motor Driver Board)
 * via the pins below.
 *
 * This motor controls a syringe pump, the best way to describe it is through a video here:
 * https://drive.google.com/file/d/1NBVGI3rdMyDDZzPux7d7JAyAq1FNVAgx/view?usp=sharing
 *
 * We would like to control more syringe pumps from the same arduino, ie connect multiple stepper motors to a single arduino
 * and be able to control them independently in the same way as the current one is.
 * 
 * To anyone looking at this willing to help out, thank you!
*/

#include <Stepper.h>

int in1Pin = 2;
int in2Pin = 5;
int in3Pin = 3; // check order of 
int in4Pin = 4; // these two (as of 5.2.22 it was 2,3,5,4) - however it seems 2,5,3,4 is working
// (cable dependent obviously, and with opposite permutation giving opposite motion)

Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);  

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  //while (!Serial);
  
  Serial.begin(9600);
  motor.setSpeed(5); // might need to adjust this if not working
  // 10 seems like a reasonable (and working) default value; will need to 
  // check flow rates etc.
  // NB 5-20 seems like a working range
}

void loop()
{
  if (Serial.available())
  {
    int steps = Serial.parseInt();
    Serial.print("Moving this many steps: ");
    Serial.println(steps);
    motor.step(steps);
    Serial.print("Motor moved by this many steps: ");
    Serial.println(steps);
  }
}
