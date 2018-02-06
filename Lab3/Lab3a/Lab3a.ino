#define ECHOPIN 3
#define TRIGPIN 2
#define LED 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LED, OUTPUT);

}

 /// this is a comment
void loop()
{
  int x;
  
  // put your main code here, to run repeatedly:
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  float distance = pulseIn(ECHOPIN, HIGH)/58.; //  devide by 58 to convert to cm
  Serial.print(distance);
  Serial.println("cm");

  for (x = 0; x < 5; x++) {
    
  if (distance <= 10){
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

  delay(1000);
  //digitalWrite(LED, LOW);
  //Serial.print("dd");

  

}
