// board B
#include <SoftwareSerial.h>
#define ECHOPIN 9
#define TRIGPIN 8


void setup()
{
  Serial1.begin(9600);///1ser
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop()
{
// put your main code here, to run repeatedly: 
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW); 
 float distance = pulseIn(ECHOPIN, HIGH)/58; // return 0 if no high pulse in 1sec
 //Serial.print(distance);
// Serial.println("cm");
 delay(100);

if(distance <= 10)
{
  Serial1.write('e'); // 'i' for intruder
 // delay(1000);
  delay(100);
}
else if(distance > 10 && distance<=20)
 {
  Serial1.write('a'); // amber
  delay(100);
 // delay(1000);
 
}
else
{
Serial1.write('n'); //normal
}
}



