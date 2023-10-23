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

const int totalPines = 43;

int x = 54;
int conteo = 1;
char letras[] = {
  'Q', 'A', '2', 'Z', 'W', 'S', '3', 'X', 'E', 'D',
  '4', 'C', 'R', 'F', '5', 'V', 'T', 'G', '6', 'B',
  'Y', 'H', '7', 'N', 'U', 'J', '8', 'M', 'I', 'K',
  '9', ',', 'O', 'L', '_', '.', 'P', 209, '!', '$', '¢', ':','?'};

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
int anchoLetras = 0;

void loop() {
  if (receptor.available()) {
    const int indiceTecla = receptor.getReceivedValue();
    const int i = receptor.getReceivedValue()-1;
        
    mensaje += letras[i];

    pantalla.clearScreen( true );
    pantalla.selectFont(FUENTE);
    const char * c = mensaje.c_str();

    anchoLetras += pantalla.charWidth(letras[i]) + 1;
    
    pantalla.drawMarquee(c, strlen(c), (32*PANELESX), 0);
    pantalla.stepMarquee(-anchoLetras, 0);
    //salida(receptor.getReceivedValue(), receptor.getReceivedBitlength(), receptor.getReceivedDelay(), receptor.getReceivedRawdata(),receptor.getReceivedProtocol());

    Serial.print(i);
    Serial.print(": ");
    Serial.print(letras[i]);
    Serial.print(" - ");
    Serial.print("N. chars: ");
    Serial.print(strlen(c));
    Serial.print(" | ancho letras: ");
    Serial.print(anchoLetras);
    Serial.println();
    
    delay(1000);
    receptor.resetAvailable();
  }
}
