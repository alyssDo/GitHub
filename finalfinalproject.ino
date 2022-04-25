/*
 * Final Project Robotics - Alyssa Do & Alpha Diallo
 * Moves when exposed to light and turns away from shade.
 */
 
#include <Servo.h>          // Include servo library

Servo servoLeft;            // Declare left and right servo
Servo servoRight;


void setup() 
{
 
  servoLeft.attach(13);     // Attach left signal to pin 13
  servoRight.attach(12);    // Attach right signal to pin 12
}

void loop() 
{
  float tLeft = float(rcTime(8));     // Get left light & make float
  float tRight = float(rcTime(6));    // Get right light & make float

  float ndShade;                      // Difference between tLeft and tRight
  ndShade = tRight / (tLeft + tRight) - 0.5;    // Calcuation and subtraction

  int speedLeft, speedRight;          // Declare speed variables
  
  if ((tLeft + tRight) > 150000)      // If the photoreceptors are in complete darkness
  {
   speedLeft = 0;                       // Left wheel stops
   speedRight = 0;                      // Right wheel stops 
  }
  else                        // If photoreceptors are exposed to light
  {
    if (ndShade > 0.0)        // More shade on right compared to left
    {
      speedLeft = int(200.0 - (ndShade * 1100.0));   // Slows down left wheel
      speedLeft = constrain(speedLeft, -200, 200); // Keeps left wheel within range of -200 to 200
      speedRight = 200;    // Right wheel goes full speed
    }
    else    // More shade on left compared to right
    {
      speedRight = int(200.0 + (ndShade * 1100.0)); // Slows down right wheel
      speedRight = constrain(speedRight, -200, 200); // Keeps right wheel within range of -200 to 200
      speedLeft = 200; // Left wheel goes full speed
    }
  }
  maneuver(speedLeft, speedRight, 20); // Set wheel speeds
}
long rcTime(int pin)                         // rcTime measures decay at pin
{
  pinMode(pin, OUTPUT);                      // Charge capacitor
  digitalWrite(pin, HIGH);                   // ..by setting pin ouput-high
  delay(5);                                  // ..for 5 ms
  pinMode(pin, INPUT);                       // Set pin to input
  digitalWrite(pin, LOW);                    // ..with no pullup
  long time  = micros();                     // Mark the time
  while(digitalRead(pin));                   // Wait for voltage < threshold
  time = micros() - time;                    // Calculate decay time
  return time;                               // Returns decay time
}

void maneuver(int speedLeft, int speedRight, int msTime) // Maneuver function for movement
{
  servoLeft.writeMicroseconds(1500 + speedLeft); // Left servo speed set
  servoRight.writeMicroseconds(1500 - speedRight); // Right servo speed set
  if (msTime == -1)     // if msTime = -1
  {
    servoLeft.detach();     // Stop servo signal
    servoRight.detach();
  }
  delay(msTime);      // Delay for msTime
}
