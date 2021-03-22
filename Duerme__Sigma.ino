

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
    rotacion.write(40);
    delay(1000);
    codo.write(90);
        delay(1000);
    codo.write(130);
            delay(1000);
    muneca.write(90);
                delay(1000);
    muneca.write(50);
    delay(500);   
    pinza150.write(180);
    pinza30.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
