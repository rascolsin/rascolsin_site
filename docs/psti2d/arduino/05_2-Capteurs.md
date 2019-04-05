# Les capteurs

Les modules capteurs émettent un signal électrique (une tension) image de la donnée physique (température, luminosité ...) qu'ils mesurent.

## 1. Bouton poussoir : *Button*

Nous donnons ci-dessous un code exemple de l'utilisation du module *Button*, le comportement est le suivant : L'appui sur le bouton poussoir relié sur la pin numérique 3, provoque l'allumage de la led reliée sur la pin numérique 2. Le relâchement provoque son extinction.

```c++
const int led=2; //Déclaration d'une constante de type int et de nom "led", contenant 2 la pin où la led est reliée
const int bp=3; //Déclaration d'une constante de type int et de nom "bp", contenant 3 la pin où le bouton poussoir est relié
boolean etat=false; //Déclaration d'une variable "etat" de type booléen initialisée à false (soit niveau logique 0)

void setup() //Initialisation
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin numérique 2 pour la led
	pinMode(bp,INPUT); //Mise en entrée de la pin numérique 3 pour le bouton poussoir
}

void loop() //Programme principal
{
	etat=digitalRead(bp); //Lecture de la valeur de la pin 3 : bouton appuyé -> etat=1   bouton relaché -> etat=0
	digitalWrite(led,etat); //La led s'allume ou s'éteint suivant la valeur de "etat"
}

```

## 2. Capteur d'inclinaison : *Tilt Switch*

Nous donnons ci-dessous un code exemple de l'utilisation du module *Tilt Switch*, le comportement est le suivant : L'inclinaison du capteur relié sur la pin numérique 3, provoque l'allumage de la led reliée sur la pin numérique 2. Le fait de mettre le capteur à l'horizontale provoque son extinction.

```c++
const int led=2; //Déclaration d'une constante de type int et de nom "led", contenant 2 la pin où la led est reliée
const int tilt=3; //Déclaration d'une constante de type int et de nom "bp", contenant 3 la pin où le bouton poussoir est relié
boolean etat=false; //Déclaration d'une variable "etat" de type booléen initialisée à false (soit niveau logique 0)

void setup() //Initialisation
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin numérique 2 pour la led
	pinMode(tilt,INPUT); //Mise en entrée de la pin numérique 3 pour le tilt switch
}

void loop() //Programme principal
{
	etat=digitalRead(tilt); //Lecture de la valeur de la pin 3 : tilt incliné -> etat=1   tilt horizontal -> etat=0
	digitalWrite(led,etat); //La led s'allume ou s'éteint suivant la valeur de "etat"
}

```

## 3. Potentiomètre : *Rotary Sensor*

Nous donnons ci-dessous un code exemple de l'utilisation du module *Rotary Sensor*, le comportement est le suivant : Le module potentiomètre est relié à la pin analogique 0, le fait de faire tourner celui-ci fait varier la tension $V_{a0}$ entre 0 et 5V sur cette pin. Nous utilisons le CAN pour lire cette tension et la transformer en une information numérique N comprise entre 0 et 1023 (sur 10 bits), nous "re-bornons" cette information à l'aide de la fonction Arduino ```map()``` entre 0 et 255 (sur 8 bits) et l'utilisons avec le PWM sur la pin numérique 2 pour faire varier la luminosité du module led.

```c++
const int led=2; //Déclaration d'une constante de type int et de nom "led", contenant 2 la pin numérique où la led est reliée
const int rotary_sensor=0; //Déclaration d'une constante de type int et de nom "rotary_sensor", contenant 0 la pin analogique où le potentiomètre est relié

int N=0; //Déclaration d'une variable entière appelée N est initialisée à 0 pour stocker la sortie du CAN

void setup() //Initialisation
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin numérique 2 pour la led
}

void loop() //Programme principal
{
	N=analogRead(rotary_sensor); //Conversion Analogique -> Numérique de la tension Va0 -> N
	N=map(N,0,1023,0,255); //Rebornage de 0<N<1023 en 0<N<255
	analogWrite(led,N); //La luminosité de la led varie en fonction de N et donc de Va0
}

```

## 4. LDR : *Light Sensor*

Nous donnons ci-dessous un code exemple de l'utilisation du module *Light Sensor*, le comportement est le suivant : Le module LDR est relié à la pin analogique 0, le fait de faire varier la luminosité (cacher ou dévoiler le capteur) fait varier la tension $V_{a0}$ entre 0 et 5V sur cette pin. Nous utilisons le CAN pour lire cette tension et la transformer en une information numérique N comprise entre 0 et 1023 (sur 10 bits), nous "re-bornons" cette information à l'aide de la fonction Arduino ```map()``` entre 0 et 255 (sur 8 bits) et l'utilisons avec le PWM sur la pin numérique 2 pour faire varier la luminosité du module led. **Cette fois-ci une forte luminosité entraînera une extinction de la led et une faible luminosité un éclairement maximal.**

```c++
const int led=2; //Déclaration d'une constante de type int et de nom "led", contenant 2 la pin numérique où la led est reliée
const int light_sensor=0; //Déclaration d'une constante de type int et de nom "light_sensor", contenant 0 la pin analogique où la LDR est reliée

int N=0; //Déclaration d'une variable entière appelée N est initialisée à 0 pour stocker la sortie du CAN

void setup() //Initialisation
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin numérique 2 pour la led
}

void loop() //Programme principal
{
	N=analogRead(light_sensor); //Conversion Analogique -> Numérique de la tension Va0 -> N
	N=map(N,0,1023,255,0); //Rebornage de 0<N<1023 en 0<N<255 avec inversion pour 0 ->255 pour 1023->0
	analogWrite(led,N); //La luminosité de la led varie en fonction de N et donc de Va0
}

```
!!! info
    Il est possible que la tension de la LDR même avec une forte luminosité ne fasse pas monter la valeur N à 1023, il s'agit donc de regarder la valeur max réelle de N (à l'aide du Serial par exemple) pour ajuster le rebornage dans ```map()```.


## 5. Capteur de température : *Temperature Sensor*

Nous donnons ci-dessous un code exemple de l'utilisation du module *Temperature Sensor*, le comportement est le suivant : Le module température est relié à la pin analogique 0, le fait de faire monter la température au dessus de 30°C allume le module led relié sur la pin numérique 2. Faire descendre la température en dessous provoque l'extinction de la led.

```c++
#include <math.h> //Ajout de la bibliothèque C/C++ math.h pour utiliser la fonction logarithme décimal : log()

//Constantes prises sur la documentation du Wiki de Seeed Studio
const int B=4275; //B valeur de la LDR en Ohms
const int R0 = 100000; //R0 = 100k

const int led=2; //Déclaration d'une constante de type int et de nom "led", contenant 2 la pin numérique où la led est reliée
const int temperature_sensor=0; //Déclaration d'une constante de type int et de nom "temperature_sensor", contenant 0 la pin analogique où le capteur de température est relié

int N=0; //Déclaration d'une variable entière appelée N est initialisée à 0 pour stocker la sortie du CAN
float R=0; //Déclaration d'une variable flottante appelée R est initialisée à 0 pour calculer la température
float temperature=0; //Déclaration d'une variable flottante appelée R est initialisée à 0 pour stocker la valeur de la température

void setup() //Initialisation
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin numérique 2 pour la led
}

void loop() //Programme principal
{
	N=analogRead(temperature_sensor); //Conversion Analogique -> Numérique de la tension Va0 -> N

	//Calcul de la temperature suivant la doc du Wiki de Seeed Studio
	R=1023.0/((float)N)-1.0;
	R=100000.0*R;
 	temperature=1.0/(log(R/100000.0)/B+1/298.15)-273.15; //calcul de la temperature suivant la doc

	if(temperature>30)
	{
		digitalWrite(led,HIGH); //Allumage de la led si temperature > 30
	}
	else
	{
		digitalWrite(led,LOW); //Extinction de la led si temperature < 30
	}
}
```

!!! note
    La bibliothèque math.h est déjà pré-ajoutée dans l'IDE Arduino inutile de chercher où la télécharger.
