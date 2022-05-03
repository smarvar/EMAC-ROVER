
// Servo.h is a default library for Servos in arduino

#include <Servo.h>
Servo myservo;  // create servo object to control a servo
  int pos = 0;    // variable to store the servo position

void turn_servo(int min_angle, int max_angle, int step_angle) {
    if (pos >= min_angle){
      pos +=step_angle;
      myservo.write(pos);
    }   
     
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
}
