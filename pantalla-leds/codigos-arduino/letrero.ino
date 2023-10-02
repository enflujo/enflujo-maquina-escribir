/**
***█* ***** **██* *█*** *█**█ ***** █***█ 
**█*█ **█** *█**█ █**** █**█* ***** **█** 
*█*** ***█* █**** *█*** *█**█ ****█ *█*█* 
█**** █***█ *█*** █**** █**█* ***** *█*█* 
*██** ██**█ **██* *█*** *█**█ **█*█ *█*█* 
█**** █*█*█ *█**█ █**** █**█* *█**█ *█*█* 
*█**█ █**██ *█*** *█**█ *█**█ ██*██ **█** 
**██* █**█* *█*** █*███ **██* *███* █***█
---------------- Letrero ----------------
........................ 2023 ...........
**/
#include <SPI.h> 
#include <DMD.h>
#include <TimerOne.h>
#include <RCSwitch.h>
#include "Arial_Black_16_ISO_8859_1.h"
#define PANELESX 2
#define PANELESY 1
#define FUENTE Arial_Black_16_ISO_8859_1
#define VELOCIDAD 30

DMD pantalla(PANELESX, PANELESY);
RCSwitch receptor = RCSwitch();

const int totalPines = 42;

char letras[] = {'q', 'a', '2', 'z', 'w', 's', '3', 'x', 'e', 'd', '4', 'c', 'r', 'f', '5', 'v', 't', 'g', '6', 'b', 'y', 'h', '7', 'n', 'u', 'j', '8', 'm', 'i', 'k', '9', ',', 'o', 'l', '_', '.', 'p', 'ñ', '!', '$', '¢', ':', '?','x', 'e', 'd'};


String mensaje = "";

void escanearPantalla() { 
  pantalla.scanDisplayBySPI();
}

void setup() {
  Serial.begin(9600);
  Timer1.initialize( 3000 );
  Timer1.attachInterrupt( escanearPantalla );
  pantalla.clearScreen( true );
  receptor.enableReceive(0);
}

void loop() {
 // Serial.print('miau');
  if (receptor.available()) {
    const int indiceTecla = receptor.getReceivedValue();
    const int i = receptor.getReceivedValue() - 2;
   // Serial.print(i);
    Serial.print(": ");
    Serial.println(letras[i]);
    mensaje += letras[i];

    pantalla.clearScreen( true );
    pantalla.selectFont(FUENTE);
    const char * c = mensaje.c_str();

    pantalla.drawMarquee(c, strlen(c), (32*PANELESX)-1,0);
    long start = millis();

    //pantalla.stepMarquee(-1, 0)

    long timer = start;
    boolean ret = false;
    while(!ret){
      if ((timer+30) < millis()) {
        ret = pantalla.stepMarquee(-1,0);
        timer = millis();
      }
    }
    // int x = 1;
    // int y = 0;
    // pantalla.drawMarquee(c, strlen(c), x, y);
    
  }
}

void revisar() {
  if (receptor.available()) {

    receptor.resetAvailable();
  }
}
