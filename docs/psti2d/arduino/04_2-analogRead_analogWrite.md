# Lire/Écrire sur les pins analogiques

L'environnement Arduino nous permet d'utiliser de manière simple deux fonctions essentielles d'un microcontrôleur le CAN et le PWM, nous donnons dans ce cours les explications quant à leurs paramétrages et leurs utilisations.

## 1. ```analogRead()```

Nous rappelons ci-dessous l'emplacement des pins analogiques sur une carte Arduino UNO et MEGA :

![](/psti2d/arduino/figures/PinsAnaArduino.svg)

### 1.1 Conversion Numérique Analogique
Les cartes Arduino UNO et MEGA disposent toutes deux d'un Convertisseur Analogique Numérique de 10 bits intégré au micro-contrôleur, la figure ci-dessous vise à expliquer son fonctionnement :

![](/psti2d/arduino/figures/FigureCAN.svg)

Une carte Arduino dispose de 6 entrées analogiques A0 à A5 pour le UNO, 16 de A0 à A15 pour le MEGA. L'entrée du convertisseur $V_{a0}$ accepte une **tension analogiques comprise entre 0 et 5V maximum, qui sera convertie en un nombre binaire N compris entre 0 et 1023**.

Nous déduisons alors la caractéristique entrée/sortie du CAN :

![](/psti2d/arduino/figures/CaracCAN.svg)

Le quantum q est la plage de tension analogique qui permet à la sortie N de croître d'une marche quand celle-ci est dépassée :

$$
q=\frac{V_{pe}}{2^{n}}=\frac{5}{2^{10}}=4.88mV
$$

À partir de la droite rouge nous obtenons l'équation du CAN :

$$
(N)_{10}=\frac{1023}{5}\times V_{a0}
$$

On peut alors en déduire les valeurs $N_{min}$ et $N_{max}$ :

$$
N_{min}=(0000000000)_{2}=(0)_{10}
$$

$$
N_{max}=2^{10}-1=(1111111111)_{2}=(1023)_{10}
$$



### 1.2 Utiliser le CAN avec Arduino

L'utilisation du CAN avec Arduino est très simple, il suffit d'utiliser la fonction ```analogRead()```, nous donnons ci-dessous sa structure :

![](/psti2d/arduino/figures/analogRead.svg)

Le code suivant lit la valeur analogique sur la pin A0 et la convertit en ```N``` en utilisant la fonction ```analogRead```. La variable ```N``` est ensuite convertie en Volts grâce à l'équation de la droite du CAN, pour obtenir finalement la variable ```Va0```.

```c++
const int PinAna=0; //Déclaration d'une constante de type int et de nom "PinAna", contenant 0 la pin analogique à lire
float VaO=0; //Déclaration d'une variable de type float et de nom "Vao", initialisée à 0
int N=0; //Déclaration d'une variable de type int et de nom "N", initialisée à 0

void setup() //Initialisation
{
//Pas de pinMode pour analogRead()
}

void loop() //Programme principal
{
	N=analogRead(PinAna); //Lecture de la valeur Va0 de la pin analogique 0 et conversion en N -> 0<N<1023
	Vao=(5.0/1023.0)* N; //Conversion de N en Va0 grâce à l'équation de la droite du CAN
}
```

!!! warning
    Ne pas déclarer la pin analogique utilisée en entrée à l'aide de ```pinMode()``` Arduino le fait de manière automatique sachant que ```analogRead()``` ne s'utilise qu'avec des pins analogiques **qui ne fonctionnent qu'en entrée**.

## 2. ```analogWrite()```

### 2.1 Modulation de Largeur d'Impulsion

La MLI aussi appelée PWM (Pulse Width Modulation) en Anglais, est une technique permettant de faire varier la valeur moyenne de la tension d'un signal carré en changeant son rapport cyclique. Avant de rentrer dans les détails, revoyons un peu de vocabulaire technique.

![](/psti2d/arduino/figures/CaracPWM.svg)

La figure ci-dessus montre un signal carré configuré de cette manière :

* Période : T = 2ms

* Fréquence : f = $\frac{1}{T}$ = 500Hz

* Durée de l'état bas : $T_b$ = 1ms

* Durée de l'état haut : $T_h$ = 1ms

* Tension max : $V_{max}$ = $\hat{V}$ = 5V

* Tension min : $V_{min}$ = 0V

Nous montrons ici comment calculer sa valeur moyenne :

![](/psti2d/arduino/figures/CaracPWM2.svg)

Formule de la valeur moyenne $<V>$ pour un signal carré et **seulement pour un signal carré** :

$$
<V>=\frac{\Delta T}{T}
$$

Où $\Delta T$ est l'aire du carré bleu :

$$
\Delta T =V_{max}\times T_h
$$

Nous obtenons alors :

$$
<V>=\frac{V_{max}\times T_h}{T}
$$

En faisant l'application numérique à la figure ci-dessus :

$$
<V>=\frac{5\times 1\times 10^{-3}}{2\times 10^{-3}}=2,5V
$$

On trace à présent la valeur moyenne $<V>$ en vert sur la figure :

![](/psti2d/arduino/figures/CaracPWM3.svg)

Introduisons à présent la notion de **rapport cyclique** $\alpha$ qui est essentielle à la compréhension du fonctionnement d'un PWM :

$$
\alpha=\frac{T_h}{T}
$$

Le rapport cyclique est un pourcentage : $0\%<\alpha<100\%$

**La technique du PWM consiste à faire varier le rapport cyclique qui revient à faire varier la valeur moyenne du signal**.
Nous donnons ci-dessous des variations du rapport cyclique du signal carré précédent, **tout en gardant la même fréquence** f=500Hz :

* Pour $\alpha=0\%$

![](/psti2d/arduino/figures/CaracAlpha0.svg)

* Pour $\alpha=10\%$

![](/psti2d/arduino/figures/CaracAlpha10.svg)

* Pour $\alpha=50\%$

![](/psti2d/arduino/figures/CaracAlpha50.svg)

* Pour $\alpha=90\%$

![](/psti2d/arduino/figures/CaracAlpha90.svg)

* Pour $\alpha=100\%$

![](/psti2d/arduino/figures/CaracAlpha100.svg)

Avec une fréquence élevée le composant branché en sortie du PWM **ne verra que la valeur moyenne (la droite verte) du signal carré qui est continue**.

La technique du PWM peut être utilisée dans les cas suivants :

* Faire varier la vitesse d'un moteur à courant continu.
* Faire varier la luminosité d'une led.

#### 2.2 Utiliser le PWM avec Arduino

En environnement Arduino, le PWM s'utilise avec la fonction ```analogWrite()```, nous donnons ci-dessous sa structure :

![](/psti2d/arduino/figures/analogWrite.svg)

Le choix du rapport cyclique avec la fonction ```analogWrite()``` se fait sur **8 bits** soit une valeur comprise entre 0 -> 0% et 255 -> 100%

**Le PWM ne s'utilise pas avec n'importe quelle pin ! Il faut que la pin soit numérique et que ce soit une pin PWM**, nous donnons le numéro des pins utilisables avec les cartes Arduino UNO et MEGA ainsi que la fréquence dans le tableau suivant :

Carte  | Pins PWM	|	Fréquence du PWM
------------- | ------------- | -------------
UNO  | 3,5,6,9,10,11 | 490Hz et 980Hz sur pins 3 et 11
MEGA  | 2 à 13, 44 à 46 | 490Hz et 980Hz sur pins 3 et 11

!!! note
    Les pins numériques utilisables en PWM sont notées avec un **~** sur les cartes Arduino.

Nous donnons ci-dessous un code exemple de l'utilisation de cette fonction :

```c++
const int PinPWM=3; //Déclaration d'une constante de type int et de nom "PinPWM", contenant 3 la pin numérique à utiliser pour le pwm

void setup() //Initialisation
{
	pinMode(PinPWM,OUTPUT);//Mise en sortie de la pin numérique 3 pour utiliser le pwm
}

void loop() //Programme principal
{
	analogWrite(PinPWM,127); //Création d'un signal PWM sur la pin numérique 3 avec un rapport cyclique de 50%
}
```
