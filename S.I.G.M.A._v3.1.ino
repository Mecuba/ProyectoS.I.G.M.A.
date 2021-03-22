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
  String angle;

 
  void setup() 
  {
    Serial1.begin(9600); //Inicializa puerto serial de la banda mental
    Serial.begin(9600);

    delay(2000); //Tiempo para dar estabilidad
    Serial.println("Iniciando programa S.I.G.M.A");
    
    rotacion.attach(2);  // Se colocan los servos en los pines del 2-5
    codo.attach(3);
    muneca.attach(4);
    pinza30.attach(7);
    pinza150.attach(5);

    Serial.print(".");   //Marcador
    delay(1000);
    
    pinMode(switch1, INPUT);   //Se configuran los pines de los switches como entradas
    pinMode(switch2, INPUT);
    pinMode(switch3, INPUT);
    pinMode(switch4, INPUT);
 

    Serial.print(".");     //Marcador
    delay(1000);
    
    rotacion.write(90);     //Se llevan los servos a posición inicial
    codo.write(90);
    muneca.write(80);
    pinza150.write(180);
    pinza30.write(0);
    
    Serial.println(".");
    delay(1000);
    Serial.println("Listo.");   //Marcador fin setup
  } 
 
  void loop() { 
    
    //Se asigna el valor a la variable de atencion
    valorAtencion= brain.readAttention();
    /*
    codAttValue = brain.readAttention();
    munAttValue = brain.readAttention();
    attValue = brain.readAttention();
    attValue30 = brain.readAttention();
    attValue150=brain.readAttention();
    */
    
    if (brain.update()) {               //Verifica que la banda mental envie informacion
      
    if(brain.readSignalQuality() != 0) {  //Mientras no haya una conexión estable, reporta el valor del ruido y las demás ondas mentales
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
    munAttValue = map(attValue, 0, 100, 60, 150);
    attValue150 = map(attValue, 0, 100, 180, 45);
    attValue30 = map(attValue, 0,100, 0, 130);
    attValue = map(attValue, 0, 100, 0, 180); // Regla de tres entre el valor de atención y la posicion de un servo
    
    if (switch1s == HIGH && switch2s == LOW && switch3s == LOW && switch4s == LOW) // Si el switch 1 está encendido y los demás apagados...
    {
      if (codAttValue>=35 && codAttValue<90) { //Para rotar, se necesita estirar la garra
      codo.write(60);
      delay(1000);
      }
      if (codAttValue>90 && codAttValue<=150) { 
      codo.write(120);
      delay(1000);
      }
      codo.write(90);
      muneca.write(90);

      
      text="Rotacion"; //Marcador para conocer el movimiento a realizar
      angle=attValue;
      rotacion.write(attValue);  //se lleva el servo a la posición del nivel de atencion
    }
    
    else if(switch2s == HIGH && switch1s == LOW && switch3s == LOW && switch4s == LOW) //Lo mismo que arriba pero con el switch 2
    {
       text="Codo";
       angle=codAttValue;
       codo.write(codAttValue);
    }
    
    else if(switch3s == HIGH && switch1s == LOW && switch2s == LOW && switch4s == LOW) //Con el switch 3
    {
      text="Muneca";
      angle=munAttValue;
      muneca.write(munAttValue);
    }
    
    else if(switch4s == HIGH && switch1s == LOW && switch2s == LOW && switch3s == LOW) //Con el switch 4
    {
      text="Pinzas";
      angle=attValue;
      pinza30.write(attValue30);
      pinza150.write(attValue150);
      
    }
    
    else {
      text="OFF"; //Cuando el switch esté en modo apagado
    }
    
    if (valorAtencion != brain.readAttention()) //Cuando el valor de atención haya cambiado se imprimirán los nuevos resultados
    {
     Serial.print("Atencion igual a        > "); 
     Serial.println(brain.readAttention()); //Nivel atención
     Serial.print(text); //Movimiento en curso
     Serial.print(" posicion: (");
     Serial.print(angle); //Grados del Servo
     Serial.println("o)");
    }
    
  } //Acaba if Signal Quality
 } //Aqui se repite void loop
