# Lire/Écrire sur les pins numériques

Les cartes Arduino disposent toutes de pins numériques utilisables aussi bien en entrées qu'en sorties, nous montrons dans ce cours comment les paramétrer et s'en servir.

Nous rappelons ci-dessous l'emplacement des pins numériques sur une carte Arduino UNO et MEGA :

![](/psti2d/arduino/figures/PinsNumArduino.svg)

## 1. ```pinMode()```
Une carte Arduino peu importe le modèle, dispose de pins numériques et de pins analogiques, la première catégorie de pins contrairement à la seconde peut être configurée, aussi bien en entrée qu'en sortie :

* Une pin numérique est utilisée en **entrée** ```INPUT``` pour recueillir une information extérieure (un "1" ou un "0") venant d'un capteur à sortie numérique, par exemple un bouton poussoir ou un capteur ILS (Reed).

* Une pin numérique est utilisée en **sortie** ```OUTPUT``` pour écrire un niveau logique (un "1" ou un "0") sur l'entrée d'un actionneur, par exemple une led, un relais ou un moteur.

La figure ci-dessous illustre ces deux possibilités, **la pin 13 est configurée en sortie et la pin 2 en entrée** :

![](/psti2d/arduino/figures/SensInfoPinMode.svg)

La fonction ```pinMode()``` à coder dans la partie ```void setup()``` va nous permettre d'indiquer au micro-contrôleur le sens d'utilisation de chaque pin. Ci-dessous nous donnons la structure de cette fonction :

![](/psti2d/arduino/figures/pinMode.svg)

Puis un code exemple de l'utilisation de cette fonction :

```c++
const int led=13; //Déclaration d'une constante de type entier appelée "led" et initialisée à 13
const int bp=2; //Déclaration d'une constante de type entier appelée "bp" et initialisée à 2

void setup() //Initialisations
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin 13
	pinMode(bp,INPUT); //Mise en entrée de la pin 2
}

```

!!! warning
    Comme précisé ci-dessus ```pinMode()``` ne s'utilise qu'avec des **pins numériques (digital)**. De plus quand une pin a été définie en sortie, il est interdit de l'utiliser en entrée plus tard dans le programme et vice-versa.

## 2. ```digitalWrite()```
La fonction Arduino ```digitalWrite()``` permet d'écrire une information numérique (un 0 ou un 1), sur une **pin numérique**. Les niveaux de tension correspondants sont les niveaux TTL :

* Un **1** logique vaut **5V**
* Un **0** logique vaut **GND** (la masse)

Ci-dessous nous donnons la structure de cette fonction :

![](/psti2d/arduino/figures/digitalWrite.svg)

Le code ci-dessous allume la led 13 reliée à la pin 13 (led présente sur le circuit imprimé d'une carte Arduino UNO ou Mega) en se servant de ```digitalWrite()``` :

```c++
const int led=13; //Déclaration d'une constante de type int et de nom "led", contenant 13 la pin où la led est reliée

void setup() //Initialisations
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin numérique 13
}

void loop() //Programme principal
{
	digitalWrite(led,HIGH); //Mise à 1 de la pin numérique 13 désignée par la constante led
}

```

Même exemple mais en se servant d'une variable ```etat``` de type ```boolean``` contenant le niveau logique servant à l'allumage de la led :

```c++
const int led=13; //Déclaration d'une constante de type int et de nom "led", contenant 13 la pin où la led est reliée
boolean etat=true; //Déclaration d'une variable "etat" de type booléen initialisée à true (soit niveau logique 1)

void setup() //Initialisation
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin numérique 13
}

void loop() //Programme principal
{
	digitalWrite(led,etat); //Mise à 1 de la pin numérique 13 désignée par la constante led, l'état de la pin est contenu dans la variable "etat"
}

```

Emplacement de la led 13 sur les cartes Arduino UNO et MEGA :

![](/psti2d/arduino/figures/Led13.svg)

## 3. ```digitalRead()```
La fonction Arduino ```digitalRead()``` permet de lire une information numérique (un 0 ou un 1), sur une **pin numérique**. Les niveaux de tension correspondants sont également des niveaux TTL.

Ci-dessous nous donnons la structure de cette fonction :

![](/psti2d/arduino/figures/digitalRead.svg)

{% include important.html content="Ne pas oublier de déclarer une variable (ici nommée *Etat*) de type booléen ```boolean``` qui contiendra le niveau logique de la pin dont vous faites la lecture."%}

Le code ci-dessous allume la led reliée à la pin 13 quand le bouton poussoir reliée à la pin 2 est appuyé :

```c++
const int led=13; //Déclaration d'une constante de type int et de nom "led", contenant 13 la pin où la led est reliée
const int bp=2; //Déclaration d'une constante de type int et de nom "bp", contenant 2 la pin où le bouton poussoir est relié
boolean etat=false; //Déclaration d'une variable "etat" de type booléen initialisée à false (soit niveau logique 0)

void setup() //Initialisation
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin numérique 13 pour la led
	pinMode(bp,INPUT); //Mise en entrée de la pin numérique 2 pour le bouton poussoir
}

void loop() //Programme principal
{
	etat=digitalRead(bp); //Lecture de la valeur de la pin 2 : bouton appuyé -> etat=1   bouton relaché -> etat=0
	digitalWrite(led,etat); //La led s'allume ou s'éteint suivant la valeur de "etat"
}

```

Montage Arduino pour le code précédent :

![](/psti2d/arduino/figures/bp_led_digitalRead.svg)
