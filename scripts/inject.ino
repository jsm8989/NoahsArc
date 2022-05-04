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

class StepperMotor : public Stepper
{
public:

  StepperMotor(unsigned int stepsPerRevolution,
    unsigned int inPin0, unsigned int inPin1, unsigned int inPin2, unsigned int inPin3)
    : Stepper(stepsPerRevolution, inPin0, inPin1, inPin2, inPin3)
    , _stepsPerRevolution(stepsPerRevolution)
  {
    _inPins[0] = inPin0;
    _inPins[1] = inPin1;
    _inPins[2] = inPin2;
    _inPins[3] = inPin3;
  }

  void setupMotor(unsigned int speed)
  {
    pinMode(_inPins[0], OUTPUT);
    pinMode(_inPins[1], OUTPUT);
    pinMode(_inPins[2], OUTPUT);
    pinMode(_inPins[3], OUTPUT);

    setSpeed(speed);
  }

private:
  unsigned int _inPins[4];
  unsigned int _stepsPerRevolution;
};


// check order (as of 5.2.22 it was 2,3,5,4) - however it seems 2,5,3,4 is working
// (cable dependent obviously, and with opposite permutation giving opposite motion)
StepperMotor motor(512, 2, 5, 3, 4);

// Another motor is made like (using pins 6,7,8,9 and the same 512 steps per revolution):
StepperMotor anotherMotor(512, 6, 7, 8, 9);


/**
 * Matches a motor number to one of the above motors.
 * @return a pointer to the motor if found, otherwise nullptr.
 */
StepperMotor* SelectMotor(unsigned int motorNumber)
{
  if (motorNumber == 1)
  {
    return &motor;
  }
  else if (motorNumber == 2)
  {
    return &anotherMotor;
    // return nullptr; // change this to the above line if anotherMotor is made above.
  }
  // else if (motorNumber == 3)
  // {
  //   return &yetAnotherMotor;
  // }
  else
  {
    // always have this final else
    return nullptr; // did not find motor
  }
}

void setup()
{
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  //while (!Serial);
  Serial.begin(9600);

  // might need to adjust this if not working
  // 10 seems like a reasonable (and working) default value; will need to
  // check flow rates etc.
  // NB 5-20 seems like a working range
  motor.setupMotor(5);

  anotherMotor.setupMotor(10);
}

StepperMotor* selectedMotor = nullptr;
bool printInstruction = true;

void loop()
{
  if (!Serial.available() && !selectedMotor)
  {
    if (printInstruction)
    {
      Serial.println("Enter motor number:");
      printInstruction = false;
    }
  }
  else if (!Serial.available()
  {
    if (printInstruction)
    {
      Serial.println("Enter number of steps to turn the motor:");
      printInstruction = false;
    }
  }
  else if (Serial.available() && !selectedMotor)
  {
      int motorNumber = Serial.parseInt();

      selectedMotor = SelectMotor(motorNumber);
      if (selectedMotor == nullptr)
      {
        Serial.print("Did not find motor for motor number entered:");
        Serial.println(motorNumber);
      }
      else
      {
        Serial.print("Found motor for motor number:");
        Serial.println(motorNumber);
      }

      printInstruction = true;
  }
  else if (Serial.available())
  {
      int steps = Serial.parseInt();

      if (selectedMotor)
      {
        Serial.print("Moving this many steps:");
        Serial.println(steps);

        selectedMotor->step(steps);

        Serial.print("Motor moved by this many steps:");
        Serial.println(steps);
      }

      selectedMotor = nullptr;
      printInstruction = true;
  }
}
