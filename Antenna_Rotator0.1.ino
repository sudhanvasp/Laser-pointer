#include <Coordinates.h>
#include <math.h>
#include <Servo.h>

Servo elevationservo;
Servo azimuthservo;
float r;
float defaultele = 45;
float defaultaz = 45;
float readazimuth;
float readelevation;
float x;
float y;
float distance(90); //distance to the screen in cm
double xdeg;
double xrad;
double ydeg;
double yrad;
void az() {
  //azimuthservo.attach(9);
  azimuthservo.write(xdeg);
  Serial.print("x moving to ");
  Serial.println(xdeg);
  //delay(1000);
  //azimuthservo.detach();
}
void ele() {
  //elevationservo.attach(10);
  elevationservo.write(ydeg);
  Serial.print("y moving to ");
  Serial.println(ydeg);
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
      x = Serial.parseInt();
      y = Serial.parseInt();
      
      if (Serial.read() == '\n') {
        Serial.println(x);
        Serial.println(y);
//        r=sqrt(x*x + y*y);
//        Serial.print("r=");
//        Serial.println(r);
        
        xrad = atan2(x,distance);
        float xideg = xrad * 57296 / 1000; //convert rad to degree
        xdeg= 45-xideg;
        //Serial.print("xideg=");
        //Serial.println(xideg);
        //Serial.print("xdeg=");
        //Serial.println(xdeg);
        
        yrad = atan2(y,distance);
        float yideg = yrad * 57296 / 1000; //convert rad to degree
        ydeg= 45+yideg;
//        Serial.print("yideg=");
//        Serial.println(yideg);
//        Serial.print("ydeg=");
//        Serial.println(ydeg);
        
        az();
        ele();
//        Serial.println(readazimuth);
//        Serial.println(readelevation);
//        point.fromCartesian(x, y);
//        Serial.print("r: ");
//        Serial.println(point.getR());
//        Serial.print("φ: ");
//        Serial.print(point.getAngle());
//        Serial.println(" rad");
        
        Serial.println("Enter the new coordinates");
      }
    }
  }
}
