//Código para controlar un vehículo radiocontrol con pinza STEREN a partir de la información recibida por Mindflex.
#include <Brain.h>
Brain brain(Serial1);
const int ledPin = 13;
int pushButton = 8;

void setup() {

pinMode(ledPin, OUTPUT);
pinMode(pushButton, INPUT);
digitalWrite(ledPin, LOW);

Serial.begin(9600);
Serial1.begin(9600);
}

void loop() {

  if (brain.update()) {
    Serial.print(brain.readSignalQuality());
    Serial.print("  |  ");
    Serial.print(brain.readAttention());


    
    //--------------------------------1-Steering
    
 while (pushButton == LOW){
  
    if (brain.readAttention() > 50) {
      digitalWrite(ledPin, HIGH);
      Serial.println("  Derecha.");
      delay(1000);
      }
    else {
      digitalWrite(ledPin, LOW);
      Serial.println("  Izquierda.");
      delay(1000);
      }
    }
    
    Serial.println("Switch!");
    //------------------------------------2-Lifting
    
       while (pushButton == LOW){
      
       if (brain.readAttention() > 50) {
        digitalWrite(ledPin, HIGH);
        Serial.println("  Sube.");
        delay(1000);
        }
       else {
        digitalWrite(ledPin, LOW);
        Serial.println("  Baja.");
        delay(1000);
       }
       }
       
       Serial.println("Switch!");
    //----------------------------------------3-Grabbing
     
       while (pushButton == LOW){

          if (brain.readAttention() > 50) {
            digitalWrite(ledPin, HIGH);
            Serial.println("  Cierra.");
            delay(1000);
           }
          else {
            digitalWrite(ledPin, LOW);
            Serial.println("  Abre.");
            delay(1000);
           }
       }
       
       Serial.println("Switch!");
     //------------------------------------------4-LiftingAgain

             while (pushButton == LOW){
      
            if (brain.readAttention() > 50) {
              digitalWrite(ledPin, HIGH);
              Serial.println("  Sube.");
              delay(1000);
             }
            else {
             digitalWrite(ledPin, LOW);
             Serial.println("  Baja.");
             delay(1000);
             }
            }
            
           Serial.println("Final Switch!"); 
      //-------------------------------------------

//You shall not pass. Acaba if del inicio. [Steering]
    }
    else {
      digitalWrite(ledPin, LOW);
    }
  }
