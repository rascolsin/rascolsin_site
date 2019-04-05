# Utilisation des modules Grove de Seeed Studio

Les modules Grove de Seeed Studio permettant de prototyper rapidement une solution, seront utilisés lors des activités sin.

## 1. Introduction

![](/psti2d/arduino/figures/seeedstudio_logo.png)

[Seeed Studio](http://www.seeedstudio.com) est une entreprise Chinoise basée à Shenzhen qui commercialise des produits électroniques pour les [Makers](https://fr.wikipedia.org/wiki/Culture_maker). Grove est un système de modules se branchant sur une carte mère appelée Grove shield :

* Pour Arduino UNO : [Grove Base Shield](http://www.seeedstudio.com/wiki/Grove_-_Base_Shield)
* Pour Arduino Mega : [Grove Mega Shield](http://www.seeedstudio.com/wiki/Grove_-_Mega_Shield)

**Beaucoup de documentation est disponible sur le [Wiki](http://www.seeedstudio.com/wiki/Main_Page) de Seeed Studio allez y jeter un coup d'oeil !**

## 2. Comment connecter un module au shield Grove ?

Ci-dessous le shield Grove Mega qui s'enfiche par dessus une carte Arduino Mega:

![](/psti2d/arduino/figures/Schema_Grove_Mega.svg)

Ce shield dispose de 4 familles de connecteurs :

* Les connecteurs sur pins numériques **commençant par un D** qui reçoivent des **modules numériques** comme le module LED, le bouton poussoir (*Button*), le capteur d'inclinaison (*Tilt Switch*) et le bargraphe (*LED Bar*)

* Les connecteurs sur pins analogiques **commençant pas un A** qui reçoivent des **modules analogiques** comme le module potentiomètre (*Rotary Sensor*), le capteur de luminosité (*Light Sensor*) et le capteur de température (*Temperature Sensor*).

* Les connecteurs i2C **IIC sur la carte**, au nombre de 3 (tous les mêmes, spécificité du bus) permettant de connecter par la liaison série i2C des composants fonctionnant sur ce bus comme l'écran LCD (*LCD RGB Backlight*)

* Les connecteurs UART, au nombre de 4 un pour chaque Serial disponible sur l'Arduino MEGA, permettent de connecter des modules utilisant ce type de liaison.

La connexion des modules Grove sur le shield se fait grâce à des **cordons de 4 fils** :

* Un fil **noir pour la masse** noté G ou GND sur les modules
* Un fil **rouge pour l'alimentation** noté Vcc ou V sur les modules
* Un fil **blanc pour un des deux signaux bien souvent ce fil n'est pas utilisé et est noté NC** (Non Connecté)
* Un fil **jaune pour un des deux signaux noté SIG, c'est ce fil qui est utilisé principalement pour connecter le module à la pin désirée**.


![](/psti2d/arduino/figures/PinsModulesGrove.svg)

Sur ce schéma nous avons connecté le module *Light Sensor* à la pin analogique **A0**.