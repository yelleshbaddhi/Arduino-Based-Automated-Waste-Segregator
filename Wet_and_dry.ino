#include <Servo.h>
int moisture=A0;
int touch=2;
Servo servo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo.attach(6);
servo.write(90);
pinMode(moisture,INPUT);  
pinMode(touch,INPUT);
Serial.println("Your Smart Segregator is ready to Segregate!");
}

void loop() {
  // put your main code here, to run repeatedly:
int detect_moisture=analogRead(moisture);
//Serial.println(detect_moisture);
int out=map(detect_moisture,0,1023,0,100);
Serial.println(out);
int detect_touch=digitalRead(touch);
Serial.println(detect_touch);
delay(200);

if (out>85 && detect_touch==1)
{
  servo.write(160);
  delay(25);
  Serial.println("Dry Detected");
  delay(1000);
  }
 else if (out<=85 && detect_touch==1)
 {
servo.write(15);
delay(25);
Serial.println("Wet Detected");
  delay(1000);

}
else {
servo.write(90);
delay(25);
Serial.println("Nutral Detected");
  delay(1000);

}
}
