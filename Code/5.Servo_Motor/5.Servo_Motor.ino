#include <Servo.h>
Servo myServo;

const int potPin = A0; // Connect the potentiometer to Analog Pin 0
int potVal;
int angle;
void setup() {
  myServo.attach(9); // Connect the servo motor to Digital Pin 9
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin); // Take input from the potentiometer
  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179); // use map function to map [0, 1023] to [0, 179] range
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle); // Move servo meter based on the angle input
  delay(15);
}
