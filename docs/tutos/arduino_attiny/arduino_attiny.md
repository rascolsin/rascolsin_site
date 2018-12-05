# Utilisation des microcontrôleurs Attiny avec Arduino

Nous expliquons dans ce post comment programmer en environnement Arduino la famille de microcontrôleurs [Attiny](http://www.atmel.com/products/microcontrollers/avr/tinyavr.aspxde) de chez Atmel. Les Attiny sont de petits microcontrôleurs (de 6 à 28 pattes) disposant de peu de ressources mais sont très appréciés pour les applications d'électronique embarquée où le gain de place et la faible consommation ont une importance capitale.

## L'Attiny 45
L'[Attiny 45](http://www.atmel.com/devices/ATTINY45.aspx) est un microcontrôleur de 8 pattes disposant d'une mémoire de **4ko** et d'une fmax de **20Mhz**. Nous donnons ci-dessous le brochage et le schéma structurel issus de la [datasheet](http://www.atmel.com/Images/Atmel-2586-AVR-8-bit-Microcontroller-ATtiny25-ATtiny45-ATtiny85_Datasheet.pdf) du fabricant :

![](\tutos\arduino_attiny\figures\Block_diagram_Attiny45.png)
![](\tutos\arduino_attiny\figures\Brochage_Attiny45.png)

## Utiliser une carte Arduino comme programmateur

Deux possibilités pour programmer les puces Attiny en environnement Arduino :

* Utiliser un programmateur dédié type Tiny programmer
* Utiliser une carte Arduino (UNO ou Mega) comme programmateur

Nous traiterons ici que le deuxième cas à savoir la programmation d'un **Attiny 45** à l'aide d'un **Arduino UNO** :

1. Dans un premier temps il faut téléverser sur l'**Arduino UNO** le code **ArduinoISP**

	![](\tutos\arduino_attiny\figures\Ecran_ArduinoISP.svg)

2. Ensuite, il faut rajouter l'URL d'un repository Github permettant d'accéder au téléversement du code sur les puces Attiny, au gestionnaire de cartes supplémentaires :

	![](\tutos\arduino_attiny\figures\Add_repo_Attiny.svg)

	**URL à rajouter :** https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json

3. Télécharger avec le gestionnaire de cartes la bibliothèque **attiny** :

	![](\tutos\arduino_attiny\figures\Ecran_Arduino_Gest_cartes.svg)

	![](\tutos\arduino_attiny\figures\Ecran_Arduino_Gest_cartes_in.svg)

4. Vous êtes fin prêts ! Il suffit maintenant de câbler l'Arduino UNO servant de programmateur au microcontrôleur Attiny.

	<iframe frameborder='0' height='448' marginheight='0' marginwidth='0' scrolling='no' src='https://123d.circuits.io/circuits/2287078-linking-an-arduino-uno-to-attiny-45-for-uploading-a-code/embed#breadboard' width='650'></iframe>

## Programmer un Attiny 45 avec l'IDE Arduino

Une fois les étapes précédentes effectuées, vous êtes en mesure de téleverser un code Arduino sur un Attiny 45 grâce à l'IDE. Prenons comme un exemple un code simple : nous faisons clignoter une led par intervalle de 500 ms.

```c++
const int pin_led 0; //Constante contenant le numéro de la pin où la led est reliée : 0

void setup()
{
	pinMode(pin_led,OUTPUT); //Mise en sortie de la pin 0
}

void loop()
{
	digitalWrite(pin_led,HIGH); //Allumage de la led
	delay(500); // Attente de 500 ms
	digitalWrite(pin_led,LOW); //Extinction de la led
	delay(500); // Attente de 500 ms
}

```

Pour téléverser le code sur l'Attiny 45 :

1. Choisir dans **Outils** --> **Type de carte** --> **Attiny**
2. Choisir dans **Outils** --> **Processeur** --> **Attiny 45**
3. Chosir  le port de l'Arduino UNO dans **Outils** --> **Port**
4. Choisir le programmateur **Arduino as ISP** dans **Outils** --> **Programmateur**
5. Appuyez sur **Téléverser** !

Nous obtenons alors le fonctionnement suivant de l'Attiny 45 :
>Appuyez sur "Start Simulation"

<iframe frameborder='0' height='448' marginheight='0' marginwidth='0' scrolling='no' src='https://123d.circuits.io/circuits/2294378-making-a-led-blink-with-an-attiny-45/embed#breadboard' width='650'></iframe>
