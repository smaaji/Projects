//pin assifgnment 

#define ECHOPIN 4
#define TRIGPIN 5
int LED_RED = 1;
int LED_GRN = 3;
int sensorPin = 6; 
unsigned int sensorValue = 0; 

void setup() {
  // put your setup code here, to run once:
   
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GRN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  float distance = pulseIn(ECHOPIN, HIGH)/58.; //  devide by 58 to convert to cm
  Serial.print(distance);
  Serial.println("cm");
 
  sensorValue = analogRead(sensorPin);

// the point at which the state of LEDs changes
 
for (sensorValue <= 150; distance <= 10;){
  digitalWrite(LED_GRN, HIGH);

  if (distance >10){
    digitalWrite(LED_RED, HIGH);
  }
 }
  
}
    //if (sensor_value < 150){ 

     // if (distance <= 10){
     // digitalWrite(LED_GRN, HIGH);  //sets LEDs ON
   // }
  //else
   // {
     // digitalWrite(LED_RED,HIGH);  //Sets LEDs OFF
    //}
//}


// if(count2<10){
  //   count++;
 //} else if (count2==18){
   //  count =0;
    // count2 =0;
 //} else{
    // count--;
 //}
