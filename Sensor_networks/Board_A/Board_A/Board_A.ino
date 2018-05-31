//board A
int DIG1 = 1;
//int DIG2 = 2;
//int DIG3 = 3;
//int DIG4 = 4;

//7 segments pin assignments 
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 13;

int buzzer = 8;
int LED_Yellow = 9;
int LED_Red = 10;
int LED_Green = 11;

const int sensorPin = 12;
//unsigned int sensorValue = 0;

void setup()
{
   pinMode(LED_Red, OUTPUT);
   pinMode(LED_Green, OUTPUT);
   pinMode(LED_Yellow, OUTPUT);
   pinMode(buzzer, OUTPUT);
   pinMode(DIG1, OUTPUT);
//pinMode(DIG2, OUTPUT);
//pinMode(DIG3, OUTPUT);
//pinMode(DIG4, OUTPUT);

pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(pinC, OUTPUT);
pinMode(pinD, OUTPUT);
pinMode(pinE, OUTPUT);
pinMode(pinF, OUTPUT);
pinMode(pinG, OUTPUT);
   
  Serial.begin(9600);
  Serial1.begin(9600);
  while (!Serial1);
}

char fred;
int count = 0;
int count2 = 9;
void loop()
{ 
int sensorValue = analogRead(sensorPin);


  if (Serial1.available())
  {
    fred = Serial1.read();
    
if(fred == 'n')
{
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_Yellow, HIGH);
}

else if (fred == 'e')
{
  digitalWrite(LED_Green, HIGH);
  digitalWrite(LED_Red, LOW);
digitalWrite(LED_Yellow, HIGH);
  
}
// Night Mode
else if (fred == 'i' && sensorValue <= 150)
{
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_Yellow, LOW);
  tone(buzzer,500,500);
 // LDR();
  delay(100);

//------------------------------&segment


// Energy source initiated to the segmenen:
   digitalWrite(DIG1, HIGH);
   //digitalWrite(DIG2, HIGH);
   //digitalWrite(DIG3, HIGH);
  // digitalWrite(DIG4, HIGH);
 
  if(count == 0)
  {
    // Pins assigned with LOW will have complete circuit to lightup:
     digitalWrite(pinA, LOW); 
     digitalWrite(pinB, LOW); 
     digitalWrite(pinC, LOW); 
     digitalWrite(pinD, LOW); 
     digitalWrite(pinE, LOW); 
     digitalWrite(pinF, LOW); 
     digitalWrite(pinG, HIGH); 

  }
  
 else if(count == 1){
     digitalWrite(pinA, HIGH); 
     digitalWrite(pinB, LOW); 
     digitalWrite(pinC, LOW); 
     digitalWrite(pinD, HIGH); 
     digitalWrite(pinE, HIGH); 
     digitalWrite(pinF, HIGH); 
     digitalWrite(pinG, HIGH); 
  }
  
 else if(count == 2){
   digitalWrite(pinA, LOW); 
   digitalWrite(pinB, LOW); 
   digitalWrite(pinC, HIGH); 
   digitalWrite(pinD, LOW); 
   digitalWrite(pinE, LOW); 
   digitalWrite(pinF, HIGH); 
   digitalWrite(pinG, LOW); 
  }

else if(count == 3){
  digitalWrite(pinA, LOW); 
  digitalWrite(pinB, LOW); 
  digitalWrite(pinC, LOW); 
  digitalWrite(pinD, LOW); 
  digitalWrite(pinE, HIGH); 
  digitalWrite(pinF, HIGH); 
  digitalWrite(pinG, LOW); 
  }

 else if(count == 4){
   digitalWrite(pinA, HIGH); 
   digitalWrite(pinB, LOW); 
   digitalWrite(pinC, LOW); 
   digitalWrite(pinD, HIGH); 
   digitalWrite(pinE, HIGH); 
   digitalWrite(pinF, LOW); 
   digitalWrite(pinG, LOW); 
  }
  
 else if(count == 5){
   digitalWrite(pinA, LOW); 
   digitalWrite(pinB, HIGH); 
   digitalWrite(pinC, LOW); 
   digitalWrite(pinD, LOW); 
   digitalWrite(pinE, HIGH); 
   digitalWrite(pinF, LOW); 
   digitalWrite(pinG, LOW); 
  }
  
 else if(count == 6){
   digitalWrite(pinA, LOW); 
   digitalWrite(pinB, HIGH); 
   digitalWrite(pinC, LOW); 
   digitalWrite(pinD, LOW); 
   digitalWrite(pinE, LOW); 
   digitalWrite(pinF, LOW); 
   digitalWrite(pinG, LOW); 
  }
  
 else if(count == 7){
   digitalWrite(pinA, LOW); 
   digitalWrite(pinB, LOW); 
   digitalWrite(pinC, LOW); 
   digitalWrite(pinD, HIGH); 
   digitalWrite(pinE, HIGH); 
   digitalWrite(pinF, HIGH); 
   digitalWrite(pinG, HIGH); 
  }

 else if(count == 8){
  digitalWrite(pinA, LOW); 
  digitalWrite(pinB, LOW); 
  digitalWrite(pinC, LOW); 
  digitalWrite(pinD, LOW); 
  digitalWrite(pinE, LOW); 
  digitalWrite(pinF, LOW); 
  digitalWrite(pinG, LOW); 
  }

 else if(count == 9){
  digitalWrite(pinA, LOW); 
  digitalWrite(pinB, LOW); 
  digitalWrite(pinC, LOW); 
  digitalWrite(pinD, LOW); 
  digitalWrite(pinE, HIGH); 
  digitalWrite(pinF, LOW); 
  digitalWrite(pinG, LOW); 
  }
  count2--;

  //condition to make 7 segments count  9 down to 0 repeatedly.
 // if(count2<10){
   //count++;
 // } else { 
  //count-- ;
  //}

// to reset all the counters to 0 and start again
//if(count2==18){
  //count =0;
  //count2 =0;
 // }

 if(count2>0){
     count--;
 } 
 //else if (count2==18){
//     count =0;
//     count2 =0;
// } else{
//     count--;
}
  
delay(1000);



//--------------------------


  
  noTone(buzzer);
  
}
else
{
digitalWrite(LED_Green, HIGH);
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_Yellow, LOW);
}
//}
    Serial.write(fred);
  }

////}
