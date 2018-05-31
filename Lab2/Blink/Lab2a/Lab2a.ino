/*
  Serial Blink
  Turns on an LED  when the person enters 1 and off when 0 is entered.

  This is lab2a start-up code.
 */
 
// Pin 9 will be used for the long lead of the LED.
// Pin 8 will be uzed for the buzzer

int led = 9;
int buzzer = 8;

// this is the varable to hold the user serial input
char inVal; 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
  pinMode (buzzer, OUTPUT); 
  Serial.begin(9600); 
  
}

// the loop routine runs over and over again forever:
void loop() {

  if (Serial.available()>0)
  {
    inVal=Serial.read();
    switch(inVal)
    {
      case '0':
        digitalWrite(led, LOW);  
    // Stops the generation of a square wave triggered by tone(). Has no effect if no tone is being generated.
    noTone (buzzer);    
        Serial.print("*");   
        break;
      case '1':
        digitalWrite(led, HIGH);
    /*Tone needs 2 arguments, but can take three
      1) Pin#
      2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
      3) Duration - how long teh tone plays
    */
    tone (buzzer, 500,500);
        Serial.println("+");
        break;
      default:
        digitalWrite(led, LOW);        
        
    }
  }

}
