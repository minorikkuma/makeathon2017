#include<Servo.h>

Servo Vert_Angle;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
    Vert_Angle.attach(10);
    Vert_Angle.write(0);
    delay(1);
 
}

void loop() {
  for (pos = 0; pos <= 45; pos += 1) { // goes from 0 degrees to 45 degrees
    // in steps of 1 degree
    Vert_Angle.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 45; pos >= 0; pos -= 1) { // goes from 45 degrees to 0 degrees
    Vert_Angle.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  
}


