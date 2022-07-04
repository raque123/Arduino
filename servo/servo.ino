#include <Servo.h>

Servo servo;
int potpin=A0;
int potval;
int x;
int servoval;

void setup() 
{
servo.attach(22);
Serial.begin(9600);
pinMode(potpin,INPUT);
}

void loop() 
{
  
  x=analogRead(potval);
  servoval=map(potval,0,1023,0,180);
 
  servo.write(60);
  delay (5000);
  
  servo.write(92);
  delay (5000);
  
  servo.write(180);
  delay (5000);

  servo.write(92);
  delay (5000);
  
  Serial.print(x);
  Serial.print("\n");
  delay(1000);
}
