#include <Servo.h> 
#include <Brain.h>

  Brain brain(Serial1); //Se le asigna a la banda mental un puerto serial

  Servo rotacion;  // Se nombran los servos
  Servo codo;
  Servo muneca;
  Servo pinza30;
  Servo pinza150;
   
  int pos = 0;// Almacena posicion servos
  int attValue; //Crea variable valores atencion
  int codAttValue;
  int munAttValue;
  int attValue30;
  int attValue150;
  int valorAtencion;
  
  int switch1 = 10; //Se colocan los switches de los pines (13-10)
  int switch2 = 11;
  int switch3 = 12;
  int switch4 = 13;
  
  int switch1s; //Variable para conocer el estado del switch (HIGH o LOW)
  int switch2s;
  int switch3s;
  int switch4s;

  String text;

 
  void setup() 
  {
    Serial1.begin(9600); //Inicializa puerto serial de la banda mental
    Serial.begin(9600);

    delay(2000); //Tiempo para dar estabilidad
    Serial.println("Iniciando programa Mindflex-Servogarra");
    
    rotacion.attach(5);  // Se colocan los servos en los pines del 2-5
    codo.attach(4);
    muneca.attach(3);
    pinza30.attach(2);
    pinza150.attach(7);

    Serial.print(".");   //Marcador
    delay(1000);
    
    pinMode(switch1, INPUT);   //Se configuran los pines de los switches como entradas
    pinMode(switch2, INPUT);
    pinMode(switch3, INPUT);
    pinMode(switch4, INPUT);
 

    Serial.print(".");     //Marcador
    delay(1000);
    
    rotacion.write(57);     //Se llevan los servos a 0 grados
    codo.write(90);
    muneca.write(90);
    pinza150.write(180);
    pinza30.write(0);
    
    Serial.println(".");
    delay(1000);
    Serial.println("Listo.");   //Marcador fin setup
  } 
 
 
  void loop() { 
    
    valorAtencion= brain.readAttention();
    codAttValue = brain.readAttention();
    munAttValue = brain.readAttention();
    attValue = brain.readAttention();
    attValue30 = brain.readAttention();
    attValue150=brain.readAttention();//Se asigna el valor a la variable de atencion
    
    if (brain.update()) {               //Verifica que la banda mental envie informacion
      
    if(brain.readSignalQuality() != 0) { 
    Serial.println(brain.readCSV());
      }
    }

     //NOTA: la banda mental actualiza aprox. cada segundo
                                        
  if(brain.readSignalQuality() == 0) {  //Comprueba que haya buena conexión con la banda mental
    
    switch1s = digitalRead(switch1);    //Se lee el valor de los switches
    switch2s = digitalRead(switch2);
    switch3s = digitalRead(switch3);
    switch4s = digitalRead(switch4);
    
    codAttValue = map(attValue, 0, 100, 35, 150);
    munAttValue = map(attValue, 0, 100, 90, 150);
    attValue30 = map(attValue, 0, 100, 45, 180);
    attValue150 = map(attValue, 0,100,130, 0);
    attValue = map(attValue, 0, 100, 0, 180); // Regla de tres entre el valor de atención y la posicion de un servo
    
    if (switch1s == HIGH && switch2s == LOW && switch3s == LOW && switch4s == LOW) // Si el switch 1 está encendido y los demás apagados...
    {
      text="Rotacion"; //Marcador para conocer el movimiento a realizar
      rotacion.write(attValue);  //se lleva el servo a la posición del nivel de atencion
    }
    
    else if(switch2s == HIGH && switch1s == LOW && switch3s == LOW && switch4s == LOW) //Lo mismo que arriba pero con el switch 2
    {
       text="Codo";
       codo.write(codAttValue);
    }
    
    else if(switch3s == HIGH && switch1s == LOW && switch2s == LOW && switch4s == LOW) //Con el switch 3
    {
      text="Muneca";
      muneca.write(munAttValue);
    }
    
    else if(switch4s == HIGH && switch1s == LOW && switch2s == LOW && switch3s == LOW) //Con el switch 4
    {
      text="Pinzas";
      pinza30.write(attValue30);
      pinza150.write(attValue150);
      
    }
    
    else {
      text="OFF"; //Cuando el switch esté en modo apagado
    }
    
    if (valorAtencion != brain.readAttention()) //Cuando el valor de atencion haya cambiado se imprimirán los nuevos resultados
    {
     Serial.print("Atencion igual a        > "); 
     Serial.println(brain.readAttention()); //Nivel atención
     Serial.print(text); //Movimiento en curso
     Serial.print(" posicion: (");
     Serial.print(attValue); //Grados del Servo
     Serial.println("o)");
    }
    
  } //Acaba if Signal Quality
 } //Aqui se repite void loop
