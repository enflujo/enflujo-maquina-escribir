#  🦾Máquina de escribir que se convierte en teclado digital ⌨️

![Tamaño](https://img.shields.io/github/repo-size/enflujo/enflujo-maquina-escribir?color=%235757f7&label=Tama%C3%B1o%20repo&logo=open-access&logoColor=white)
![Licencia](https://img.shields.io/github/license/enflujo/enflujo-maquina-escribir?label=Licencia&logo=open-source-initiative&logoColor=white)

### Documentación de los precedimientos máquina de escribir de la biscabuela 👵🏼 + arduino + pantalla + (...)


Una máquina de escribir <img src="https://emojis.slackmojis.com/emojis/images/1643510651/50638/typewriter.gif?1643510651" width="30"/> de unos 150 años  se conecta a dispositivos digitales para hacer ✨ cositas beias ✨ en tiempo real.


<br />
<p align="center">
<img src="https://emojis.slackmojis.com/emojis/images/1687220989/66713/andy-dwyer-amazed.gif?1687220989" width="100" />
</p>
<br />



### Se necesita:
- Arduino MEGA 2650
- El código que vamos a dejar acá para cada Arduino
- Máquina de escribir
- Dos baquelitas
- Resistencias de 10K
- Cable, mucho cable.
- Componentes de Arduino de señal de radio (emisor y receptor, aquí usamos los JMR-Tx y JMR Rx 433) 
(aquí aparece el código con comunicación inalámbrica pero puede funcionar con diferentes componentes/cables según la necesidad)





---

Con nuestra biscabuela 👵🏼, conseguimos nuestra máquina linda preciosa <img src="https://emojis.slackmojis.com/emojis/images/1643510651/50638/typewriter.gif?1643510651" width="30"/>:

<img width="795" alt="image" src="https://github.com/enflujo/enflujo-maquina-escribir/assets/42554838/306b7a5e-b917-421f-8053-1fe2fb691197">


---
Ya con la máquina de escribir de la biscabuela 👵🏼, hay que producir una baquelita que se ubica debajo de la máquina y hace que al oprimir cualquier tecla, se complete el circuito hacia uno de los pines.

<img src="https://github.com/enflujo/enflujo-maquina-escribir/assets/42554838/64deea1e-73da-4a58-ae40-9924af2e8948" width="500" />

---
A esa baquelita le soldaremos unos cables que salgan a comunicarse con los pines del Arduino.

<img src="https://github.com/enflujo/enflujo-maquina-escribir/assets/5365329/5915e37e-1ff5-4631-bc03-cf3e7db9b83a" width="500" />


---
Con ayuda de 🩵 **Nila** 🩵, se pone la baquelita debajo de la máquina.

<img src="https://github.com/enflujo/enflujo-maquina-escribir/assets/42554838/e94092b0-edba-4d90-b1a7-c34b873fc66a" width="400" />
<img src="https://github.com/enflujo/enflujo-maquina-escribir/assets/42554838/31b85fc7-8ece-4470-a274-3f98c1b5cc1f" width="400" />

---
Este va a ser el mapa de nuestros pines en el código y en el arduino para que la máquina escriba cada tecla.

<img src="https://github.com/enflujo/enflujo-maquina-escribir/assets/42554838/9410ecf6-39a9-4244-b671-a7b900928e70" width="500" />

---
Conectada a nuesta baquelita deberemos hacer los circuitos para que no se cocinen los pines una vez le mandemos los 5V cuando se complete el circuito.

Usando resistencias de 10K **(café-negro-naranja-dorado) **

![Mapeo de letras a pines de Arduino](https://github.com/enflujo/enflujo-maquina-escribir/assets/42554838/7d12b5ce-d0be-4692-ba59-38cb7bb73682)

Este es el circuito:


![Circuito Máquina](https://github.com/enflujo/enflujo-maquina-escribir/assets/42554838/bc9e0020-6cc1-4639-8901-3befb7e0a602)


----

Una vez terminemos de conectar los pines del Arduino a la segunda baquelita debe verse así de hermoso:

<img src="https://github.com/enflujo/enflujo-maquina-escribir/assets/42554838/12a54a99-1e84-4900-9810-ca183b587a52" width="600" />


----

Con esta primera parte ya tenemos la electrónica y el código para que nuestra máquina de escribir pueda enviar señales de las teclas a través del arduino y desde un emisor de señales de radio. Para saber cómo continuar según sea la necesidad, entre a ccualquiera de estas opciones:

> 1. [Paso a paso para maquinita-pantalla de leds](https://github.com/enflujo/enflujo-maquina-escribir/tree/main/pantalla-leds)




