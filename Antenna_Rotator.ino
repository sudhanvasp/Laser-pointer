#include <Coordinates.h>

#include <Servo.h>

Servo elevationservo;
Servo azimuthservo;

float defaultele = 45;
float defaultaz = 45;
float readazimuth;
float readelevation;
float distance(1); //distance to the screen in m

void az() {
  //azimuthservo.attach(9);
  azimuthservo.write(readazimuth);
  //delay(1000);
  //azimuthservo.detach();
}
void ele() {
  //elevationservo.attach(10);
  elevationservo.write(readelevation);
  //delay(1000);
  ///elevationservo.detach();
}
void setup() {
  Serial.begin(9600);
  azimuthservo.attach(9);
  elevationservo.attach(10);
  azimuthservo.write(defaultaz);
  elevationservo.write(defaultele);
  digitalWrite(12,HIGH);
  //delay(1000);
  //azimuthservo.detach();
  //elevationservo.detach();
  Serial.println("Begin");
  Serial.println("Enter the coordinates");
}
void loop() {
  

  while (Serial.available() > 0) {
    if (Serial.read() == 'a') {
      readazimuth = Serial.parseInt();
      readelevation = Serial.parseInt();
      
      if (Serial.read() == '\n') {
        r

        
        az();
        ele();
        Serial.println(readazimuth);
        Serial.println(readelevation);
        point.fromCartesian(x, y);
        Serial.print("r: ");
        Serial.println(point.getR());
        Serial.print("φ: ");
        Serial.print(point.getAngle());
        Serial.println(" rad");
        
        Serial.println("Enter the new coordinates");
      }
    }
  }
}
