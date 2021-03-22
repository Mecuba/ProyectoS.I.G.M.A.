#include <Servo.h>

  Servo rotacion;  // Se nombran los servos
  Servo codo;
  Servo muneca;
  Servo pinza30;
  Servo pinza150;


  
int pos = 0;    // variable to store the servo position

void setup() {

    rotacion.attach(2);  // Se colocan los servos en los pines del 2-5
    codo.attach(3);
    muneca.attach(4);
    pinza30.attach(7);
    pinza150.attach(5);

    delay(1500);

    codo.write(55);
    delay(500);
    muneca.write(120);
    delay(500);
    rotacion.write(40);     //Se llevan los servos a 0 grados
    delay(500);
    pinza150.write(180);
    delay(500);
    pinza30.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
