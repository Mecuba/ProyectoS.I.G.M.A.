#include <Mindwave.h>

/*
  Code created by Tamás Imets for playing videogames with mindwaves
  Feel free to use it
  25th of March, 2016
*/

#include <Mindwave.h>
#include <SoftwareSerial.h>
#include <Keyboard.h>

SoftwareSerial bluetooth(9, 8); //softwareserial pins
Mindwave mindwave; //mindwave library activated

int medlimit = 70; //set limits
int attlimit = 65; //set limits

void setup() {
  bluetooth.begin(9600); //set Baudrate
  pinMode(5, OUTPUT); //setup pins
  pinMode(4, OUTPUT); //setup pins
}
void onMindwaveData() {

  if (mindwave.meditation() > medlimit) { //if you meditate
    digitalWrite(5, HIGH);
    Keyboard.write('d'); //presses D


  }

  if (mindwave.meditation() < medlimit) {
    digitalWrite(5, LOW);
    Keyboard.write(' ');
  }

  if (mindwave.attention() > attlimit) { //if youe focus
    digitalWrite(6, HIGH);
    Keyboard.write('a'); //presses A
  }

  if (mindwave.attention() < attlimit) {
    digitalWrite(6, LOW);
    Keyboard.write(' ');
  }
}

void loop() {
  mindwave.update(bluetooth, onMindwaveData);
}
