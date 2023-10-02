/**
***█* ***** **██* *█*** *█**█ ***** █***█ 
**█*█ **█** *█**█ █**** █**█* ***** **█** 
*█*** ***█* █**** *█*** *█**█ ****█ *█*█* 
█**** █***█ *█*** █**** █**█* ***** *█*█* 
*██** ██**█ **██* *█*** *█**█ **█*█ *█*█* 
█**** █*█*█ *█**█ █**** █**█* *█**█ *█*█* 
*█**█ █**██ *█*** *█**█ *█**█ ██*██ **█** 
**██* █**█* *█*** █*███ **██* *███* █***█
--------------- Maquinita ---------------
......................... 2023 ..........
**/

#include "SystemFont5x7.h"
#include <RCSwitch.h>

const int totalPines = 40;
const int tilde = 42;
const int primerPin = 2; // Primer pin que se usa para conectar teclas.
char letras[] = {
  'q', 'a', '2', 'z', 'w', 's', '3', 'x', 'e', 'd',
  '4', 'c', 'r', 'f', '5', 'v', 't', 'g', '6', 'b',
  'y', 'h', '7', 'n', 'u', 'j', '8', 'm', 'i', 'k',
  '9', ',', 'o', 'l', '_', '.', 'p', 'ñ', '!', '$', '¢', ':', '?'};
RCSwitch emisor = RCSwitch();
bool estados[totalPines] = {false};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < totalPines; i++) {
    pinMode(i + primerPin, INPUT);
  }
  
  emisor.enableTransmit(52);
}

void loop() {

  for (int i = 0; i < totalPines; i++) {
    int pin = i + primerPin;
    int estado = digitalRead(pin);
    bool estadoActual = estados[i];

    if (estado == HIGH) {
      if (estadoActual) continue;
      estados[i] = true;
      emisor.send(i, 24);
      Serial.print(i);
      Serial.print(": ");
      Serial.print(letras[i]);
      Serial.println("--");
      
    } else {
      if (!estadoActual) continue;
      estados[i] = false;
    }
  }
 
  delay(20);

}
