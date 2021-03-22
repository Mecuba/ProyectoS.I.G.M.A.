/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

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

    codo.write(90);
    delay(500);
    muneca.write(90);
    delay(500);
    rotacion.write(40);     //Se llevan los servos a 0 grados
    delay(500);
    pinza150.write(180);
    delay(500);
    pinza30.write(0);
    
    delay(1500);
    rotacion.write(180);     //Se llevan los servos a 0 grados
    
    
    delay(1000);
    muneca.write(100);
    delay(1000);
    muneca.write(125);

    
    delay(1000);
    pinza150.write(120);
    pinza30.write(40);

    delay(1000);
    codo.write(70);
    delay(1000);
    codo.write(60);
    delay(1000);
    codo.write(55);

    delay(1000);
    pinza150.write(180);
    pinza30.write(0);

    delay(1000);
    rotacion.write(90);
    delay(1000);
    muneca.write(90);
    delay(1000);
    codo.write(90);

    delay(1000);
    rotacion.write(20);
    delay(1000);
    muneca.write(100);
    delay(1000);
    muneca.write(125);
    delay(1700);
    
    codo.write(70);
    delay(1000);
    codo.write(60);
    delay(1000);
    codo.write(55);

    delay(1000);
    rotacion.write(90);

    delay(1000);
    pinza150.write(45);
    pinza30.write(130);

    delay(1000);
    muneca.write(90);
    delay(1000);
    codo.write(90);

    delay(1000);
    pinza150.write(180);
    pinza30.write(0);    
    delay(500);
    pinza150.write(45);
    pinza30.write(130); 
    delay(500);   
    pinza150.write(180);
    pinza30.write(0);
    delay(500);
    pinza150.write(45);
    pinza30.write(130); 
    delay(500);   
    pinza150.write(180);
    pinza30.write(0);
    delay(500);
    pinza150.write(45);
    pinza30.write(130);
    delay(1000);   
    pinza150.write(180);
    pinza30.write(0);      
         //Se llevan los servos a 0 grados
         

}

void loop() {
    
    delay(1500);
    rotacion.write(180);     //Se llevan los servos a 0 grados
    
    
    delay(1000);
    muneca.write(100);
    delay(1000);
    muneca.write(125);

    delay(1000);
    pinza150.write(120);
    pinza30.write(40);

    delay(1000);
    codo.write(70);
    delay(1000);
    codo.write(60);
    delay(1000);
    codo.write(53);

    delay(1000);
    pinza150.write(180);
    pinza30.write(0);

    delay(1000);
    rotacion.write(90);
    delay(1000);
    muneca.write(90);
    delay(1000);
    codo.write(90);

    delay(1000);
    rotacion.write(20);
    delay(1000);
    muneca.write(100);
    delay(1000);
    muneca.write(125);
    delay(1700);
    
    codo.write(70);
    delay(1000);
    codo.write(60);
    delay(1000);
    codo.write(55);
    delay(1000);
    codo.write(50);

    delay(1000);
    rotacion.write(90);

    delay(1000);
    pinza150.write(45);
    pinza30.write(130);

    delay(1000);
    muneca.write(90);
    delay(1000);
    codo.write(90);

    delay(1000);
    pinza150.write(180);
    pinza30.write(0);    
    delay(500);
    pinza150.write(45);
    pinza30.write(130); 
    delay(500);   
    pinza150.write(180);
    pinza30.write(0);
    delay(500);
    pinza150.write(45);
    pinza30.write(130); 
    delay(500);   
    pinza150.write(180);
    pinza30.write(0);
    delay(500);
    pinza150.write(45);
    pinza30.write(130);
    delay(1000);   
    pinza150.write(180);
    pinza30.write(0);
 
}

