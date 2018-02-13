
/* It has internal resistors, no need to connec!
                A
             ________
            |        |
         F  |        |  B
            |   G    |
            |________|
            |        |
            |        |  C
        E   |        |
            |________|            
                D

*/ 


//pin assignments 

int DIG1 = 1;
//int DIG2 = 2;
//int DIG3 = 3;
//int DIG4 = 4;

//7 segments pin assignments 
int pinA = 5;
int pinB = 6;
int pinC = 7;
int pinD = 8;
int pinE = 9;
int pinF = 10;
int pinG = 11;


void setup() {
  // put your setup code here, to run once:
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
}

int count = 0;
int count2 = 0;

void loop() {

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
  count2++;

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

 if(count2<10){
     count++;
 } else if (count2==18){
     count =0;
     count2 =0;
 } else{
     count--;
 }
  
delay(1000);
}
