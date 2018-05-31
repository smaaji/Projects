#define ECHOPIN 4
#define TRIGPIN 5
int LED_YEL = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  //pinMode(LED, OUTPUT);

}

 /// this is a comment
void loop()
{
  
  // put your main code here, to run repeatedly:
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  float distance = pulseIn(ECHOPIN, HIGH)/58.; //  devide by 58 to convert to cm
  Serial.print(distance);
  Serial.println("cm");

  for (int x = 0; x < 10; x++) {
    
  if (distance <= 10){
    digitalWrite(LED_YEL, HIGH);
    //delayMicroseconds(10);
    delay(100);

    digitalWrite(LED_YEL, LOW);
    delay(100);
    } else {
    digitalWrite(LED_YEL, LOW); 
     //delayMicroseconds(2);
    }
  }
  digitalWrite(LED_YEL, LOW);

  delay(1000);
  //digitalWrite(LED_YEL, LOW);
  //Serial.print("dd");

  

}
