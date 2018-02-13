/*
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
// pin assignments
/* 
specify pins on the 7-seg display that for your Arduino
example you can connect the A segment of the display to the pin 2 on the Arduino.
*/

int counter=0;
int pinDP1 = 1;
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;


void setup() {
  //  initializing all the pins 
  pinMode(pinDP1, OUTPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);

}

void loop() {

    
     //case 0: light the correct segments when you Zero (0)
      
  //case 1: light the correct segments when you One (1)
          
  //case 9: light the correct segments when you One (9)    
        

  delay(2000);
  counter++;
  
  // count from 0 to 9
  if(counter==10)
    counter=0;


}


