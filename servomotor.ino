#include<Servo.h>

Servo Vert_Angle;
Servo Hori_Angle;
Servo SHOOT;
int pos;
const int buttonPin = 8;
int buttonState = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){  
  }
  Vert_Angle.attach(10);
    Vert_Angle.write(0);
  Hori_Angle.attach(7);
    Hori_Angle.write(0);
  delay(1);
  SHOOT.attach(12);
  pinMode(buttonPin, INPUT);

}



bool f = false;
bool ff = false;
void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

   for (pos = 10; pos <= 20; pos += 1) { // goes from 0 degrees to valVert
    // in steps of 1 degree
    Vert_Angle.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 15ms for the servo to reach the position
  
    }

    for (pos = 20; pos >= 10; pos -= 1) { // goes from 45 degrees to 0 degrees
      Vert_Angle.write(pos);              // tell servo to go to position in variable 'pos'
      delay(150);                       // waits 15ms for the servo to reach the position

    }  
  


  
   if(Serial.available() >0){
    char valHori = Serial.read();
    char valHori2 = Serial.read();
    //Serial.write(valHori);
    int val = 0;
    if (valHori=='0') {
      val = valHori2 - '0';
    } else {
      val = (valHori - '0') * 10 + (valHori2 - '0');
    }
   for (pos = 0; pos <= val; pos += 1) { // goes from 0 degrees to  valHori degrees
      // in steps of 1 degree
      Hori_Angle.write(pos);              // tell servo to go to position in variable 'pos'
      delay(250);                       // waits 15ms for the servo to reach the position
       if (pos == 30 ){
      SHOOT.write(0);
      delay(50);
      SHOOT.write(0);

    for (pos = val; pos >= 0; pos -= 1) { // goes from valHori degrees to 0 degrees
      Hori_Angle.write(pos);    // tell servo to go to position in variable 'pos'
      delay(250);                       // waits 15ms for the servo to reach the position
     
    }
  }


  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  /*if (buttonState == HIGH && f == false && ff==false) {
    SHOOT.write(0);
    delay(50);
    ff=true;
    SHOOT.write(21);//sec im thinking more
    f = true;
  } else if (buttonState == HIGH && f == true && ff == false) {
    delay(50);
    ff= true;
    SHOOT.write(90);
    f = false;
  }
  if(buttonState == LOW){
    ff=false;
  }
 
*/

   }
   }
}

