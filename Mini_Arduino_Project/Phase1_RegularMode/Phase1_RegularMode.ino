
//pin assignments

int LED_RED = 1;
int LED_YEL = 2;
int LED_GRN = 3;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YEL, OUTPUT);
  pinMode(LED_GRN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LED_RED, HIGH);
  delay(2000);
  digitalWrite(LED_RED, LOW);
  delayMicroseconds(10);
  
  digitalWrite(LED_YEL, HIGH);
  delay(1000);
  digitalWrite(LED_YEL, LOW);
  delayMicroseconds(10);
  
  digitalWrite(LED_GRN, HIGH);
  delay(2000);
  digitalWrite(LED_GRN, LOW);
  delayMicroseconds(10);

}
