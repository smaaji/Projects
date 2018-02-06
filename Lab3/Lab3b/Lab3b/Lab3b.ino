#define LED 9
int sensorPin = A0;            
unsigned int sensorValue = 0;  

void setup()
{

  Serial.begin(9600); 
  pinMode(sensorPin, INPUT);
  pinMode(sensorValue, OUTPUT);       
}

void loop(){

  int x;
  // serail monitor display codes 
  //digitalWrite(sensorValue, LOW);
  //delayMicroseconds(2);
 // digitalWrite(sensorValue,HIGH);
 // delayMicroseconds(10);
 // digitalWrite(sensorValue,LOW);
 
 // LDR value conversion to LUX
  sensorValue = (250.000000/analogRead(sensorPin)*analogRead(sensorPin))-50.000000;     

 Serial.print(sensorValue);
 Serial.println(" lm/sr");

 for (x = 0; x < 5; x++) {
    
  if (sensorValue <= 100){
    digitalWrite(LED, HIGH);
    //delayMicroseconds(10);
    delay(100);

    digitalWrite(LED, LOW);
    delay(100);
    } else {
    digitalWrite(LED, LOW); 
     //delayMicroseconds(2);
    }
  }
  digitalWrite(LED, LOW);
 delay(100);
}
