# Les actionneurs

Les modules actionneurs reçoivent de l'énergie électrique venant de l'Arduino et la transforme, par exemple le module LED reçoit de l'énergie électrique et la transforme en énergie lumineuse.

## 1. La LED

Nous donnons ci-dessous un exemple d'utilisation du module LED, ce code fait clignoter la LED du module Grove LED toutes les secondes qui est connecté sur la pin numérique 2 :

```c++
const int led=2; //Déclaration d'une constante de type int et de nom "led", contenant 2 la pin où la led est reliée

void setup() //Initialisations
{
	pinMode(led,OUTPUT); //Mise en sortie de la pin numérique 2
}

void loop() //Programme principal
{
	digitalWrite(led,HIGH); //Mise à 1 de la pin numérique 2 désignée par la constante led
	delay(1000); //Pause de 1s
	digitalWrite(led,LOW); //Mise à 0 de la pin numérique 2 désignée par la constante led
	delay(1000); //Pause de 1s
}

```
