#include <Servo.h> 
#include <Brain.h>

  Brain brain(Serial1); //Se le asigna a la banda mental un puerto serial

  Servo rotacion;  // Se nombran los servos
  Servo codo;
  Servo muneca;
  Servo pinza; 
   
  int pos = 0;// Almacena posicion servos
  int attValue; //Crea variable valores atencion
  
  int switch1 = 10; //Se colocan los switches de los pines (13-10)
  int switch2 = 11;
  int switch3 = 12;
  int switch4 = 13;
  
  int switch1s; //Variable para conocer el estado del switch (HIGH o LOW)
  int switch2s;
  int switch3s;
  int switch4s;

  byte readAttention();

 
  void setup() 
  {
    Serial1.begin(9600); //Inicializa puerto serial de la banda mental
    Serial.begin(9600);

    delay(2000); //Tiempo para dar estabilidad
    Serial.println("Iniciando programa Mindflex-Servogarra");
    
    rotacion.attach(5);  // Se colocan los servos en los pines del 2-5
    codo.attach(4);
    muneca.attach(3);
    pinza.attach(2); 

    Serial.print(".");   //Marcador
    delay(1000);
    
    pinMode(switch1, INPUT);   //Se configuran los pines de los switches como entradas
    pinMode(switch2, INPUT);
    pinMode(switch3, INPUT);
    pinMode(switch4, INPUT);
 

    Serial.print(".");     //Marcador
    delay(1000);
    
    rotacion.write(0);     //Se llevan los servos a 0 grados
    codo.write(0);
    muneca.write(0);
    pinza.write(0);
    
    Serial.println(".");
    delay(1000);
    Serial.println("Listo.");   //Marcador fin setup
  } 
 
 
  void loop() { 

    if (brain.update()) {               //Verifica que la banda mental envie informacion
     Serial.println(brain.readCSV());   //Te muestra la lectura completa de la banda mental
    }
    
     //NOTA: la banda mental actualiza aprox. cada segundo
                                        
  if(brain.readSignalQuality() == 0) {  //Comprueba que haya buena conexión con la banda mental
    
    switch1s = digitalRead(switch1);    //Se lee el valor de los switches
    switch2s = digitalRead(switch2);
    switch3s = digitalRead(switch3);
    switch4s = digitalRead(switch4);
    
 byte   attValue = brain.readAttention();  //Se asigna el valor a la variable de atencion
        attValue = map(attValue, 0, 100, 0, 180); // Regla de tres entre el valor de atención y la posicion de un servo
    
    if (switch1s == HIGH && switch2s == LOW && switch3s == LOW && switch4s == LOW) // Si el switch 1 está encendido y los demás apagados...
    {
      Serial.print("Atencion igual a      "); 
      Serial.println(brain.readAttention()); //Nivel atención
      Serial.print("Rotacion a ("); //Marcador para saber qué movimiento está haciendo la garra
      Serial.print(attValue); //Imprime la posicion a alcanzar
      Serial.println("o)");
      rotacion.write(attValue);  //se lleva el servo a la posición del nivel de atencion
      //delay(100);      //Tiempo para esperar nueva informacion de la banda mental
    }
    else if(switch2s == HIGH && switch1s == LOW && switch3s == LOW && switch4s == LOW) //Lo mismo que arriba pero con el switch 2
    {
      Serial.print("Atencion igual a      ");
      Serial.println(brain.readAttention());
      Serial.print("Codo a (");
      Serial.print(attValue);
      Serial.println("o)");
      codo.write(attValue);
      //delay(100);
    }
    else if(switch3s == HIGH && switch1s == LOW && switch2s == LOW && switch4s == LOW) //Con el switch 3
    {
      Serial.print("Atencion igual a      ");
      Serial.println(brain.readAttention());
      Serial.print("Muneca a (");
      Serial.print(attValue);
      Serial.println("o)");
      muneca.write(attValue);
      //delay(100);
    }
    else if(switch4s == HIGH && switch1s == LOW && switch2s == LOW && switch3s == LOW) //Con el switch 4
    {
      Serial.print("Atencion igual a      ");
      Serial.println(brain.readAttention());      
      Serial.print("Pinza a (");
      Serial.print(attValue);
      Serial.println("o)");
      pinza.write(attValue);
      //delay(100);
    }
    else {
      Serial.print("Move OFF, attValue =    ");
      Serial.println(brain.readAttention());
      Serial.print("Servo se moveria a (");
      Serial.print(attValue);
      Serial.println("o)");
      //delay(100);
    }
      
  } //Acaba if Signal Quality
 } //Aqui se repite void loop
