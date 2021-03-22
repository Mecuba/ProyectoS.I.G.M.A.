#include <Brain.h>
Brain brain(Serial1);
int x;
int y;
int h;
int i=0;
int attValue;
int pBState=0;
int ledPin=13;
int j=4;
const int pushButton = 8;
const int derecha=2;
const int izquierda=3;
const int gatDer=4;
const int derecha1=5;
const int izquierda1=9;
const int gatIzq=7;

void setup() {//---------------------------------------------------------------

Serial.begin(9600);
Serial1.begin(9600);
delay(2000);
Serial.println("Iniciando programa Mindflex-K675 v2.0");


pinMode(pushButton,INPUT);
pinMode(ledPin,OUTPUT);

pinMode(derecha, OUTPUT);
pinMode(izquierda, OUTPUT);
pinMode(izquierda1, OUTPUT);
pinMode(derecha1, OUTPUT);
pinMode(gatDer, OUTPUT);
pinMode(gatIzq, OUTPUT);

digitalWrite(derecha, HIGH);
digitalWrite(izquierda, HIGH);
digitalWrite(gatDer, HIGH);
digitalWrite(derecha1, HIGH);
digitalWrite(izquierda1, HIGH);
digitalWrite(gatIzq, HIGH);

digitalWrite(pushButton,LOW);

Serial.print(".");
delay(1000);
Serial.print(".");
delay(1000);
Serial.println(".");
delay(1000);


Serial.println("Listo.");


}

void loop() {//----------------------------------------------------------------
  
  pBState = digitalRead(pushButton);

//////////////////////////////////////////////////
  // Expect packets about once per second.
    if (brain.update()) {
        Serial.println(brain.readCSV());
         attValue = brain.readAttention();
    }
/////////////////////////////////////////////////


//------------------------------------------------------------------------------

    if(brain.readSignalQuality() == 0) {
      
      if (pBState == 0) {
        Serial.println("Boton presionado.");
        h=i++;
        delay(1000);
        Serial.println(h);
      }
      
      if(i==0) {
        digitalWrite(gatDer,1);
        digitalWrite(gatIzq,1);
        x=derecha;
        y=izquierda;
        Serial.println("Steering");
      }
      if(i==1) {
        digitalWrite(gatDer,0);
        digitalWrite(gatIzq,1);
        x=derecha;
        y=derecha1;
        Serial.println("Lifting");
      }
      if(i==2) {
        digitalWrite(gatDer,0);
        digitalWrite(gatIzq,1);
        x=izquierda;
        y=izquierda1;
        Serial.println("Grabbing");
      }
      if(i==3) {
        digitalWrite(gatDer,1);
        digitalWrite(gatIzq,0);
        x=derecha;
        y=derecha1;
        Serial.println("Lifting2");
      }
      if(i==4) {
        digitalWrite(gatDer,1);
        digitalWrite(gatIzq,1);
        h=i=0;
       Serial.println(h);
       Serial.println("Reboot");
      }

      if (attValue>49) {
        digitalWrite(x,0);
        digitalWrite(y,1);
        Serial.println("Concentrado----------------------------");
        Serial.println(attValue);
        
      }
      else {
        digitalWrite(y,0);
        digitalWrite(x,1);
        Serial.println("Relajado0000000000000000000000000000000");
        Serial.println(attValue);
        
      }   
    }
//-----------------------------------------------
    else {
digitalWrite(derecha, 0);
digitalWrite(izquierda, 0);
digitalWrite(gatDer, 0);
digitalWrite(derecha1, 0);
digitalWrite(izquierda1, 0);
digitalWrite(gatIzq, 0);
    }
    
}
