# L'afficheur LCD

Ce module est un écran LCD noir et blanc de 2 lignes et 16 colonnes, un rétro-éclairage fonctionnant à l'aide de leds RGB est disponible.

!!! info
    Ce module fonctionne grâce à la liaison [i2C](https://fr.wikipedia.org/wiki/I2C), **il est donc nécessaire de choisir un connecteur i2C sur le shield Grove**.

## 1. Bibliothèque

**L'ajout d'une bibliothèque à l'IDE Arduino est nécessaire** à l'utilisation du module *LCD RGB Backlight*, celle-ci est disponible sur le Github de Seeed Studio : [lien](https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight)

![](/psti2d/arduino/figures/Bibli_lcd_github.svg)

Ensuite, ajoutez le fichier .zip à l'IDE Arduino :

![](/psti2d/arduino/figures/Bibli_lcd_ide.svg)

Il suffit d'inclure à présent la bibliothèque **au début** du code Arduino de cette manière :

```c++
#include <Wire.h> //Ajout de la bibliothèque i2c pour utiliser le lcd
#include "rgb_lcd.h" //Ajout de la bibliothèque du lcd

```

!!! info
    Ne pas oublier d'ajouter également la bibliothèque ```Wire.h``` pour utiliser la liaison i2C.

## 2. Initialisation

Nous donnons ci-dessous un code exemple de l'initialisation de l'écran *Grove RGB LCD* :

```c++
rgb_lcd lcd; //Constructeur rgb_lcd pour l'objet lcd

void setup() //Initialisations
{
    lcd.begin(16, 2); //Initialisation du lcd de 16 colonnes et 2 lignes
}
```
{% include note.html content=" Le langage C++ est un langage orienté objet, un principe de programmation complexe que nous n'allons pas aborder ici. Le constructeur est en quelque sorte la manière de *déclarer* un objet, dans notre cas nous *déclarons* un objet ```lcd``` de *type* ```rgb_lcd```."%}

## 3. Le curseur

L'écran lcd du module *Grove RGB LCD* dispose de 16 colonnes et 2 lignes, si on ne précise rien quand on code l'instruction permettant d'écrire des choses dessus, la colonne 0 et la ligne 0 sont prisent en défaut ce qui a pour conséquence d'écrire en haut à gauche :

![](/psti2d/arduino/figures/lcdLC.svg)

Mais comment fait-on si on souhaite commencer à écrire au milieu ? Il suffit d'utiliser la fonction ```lcd.setCursor()```, dont nous expliquons le fonctionnement ci-dessous :

![](/psti2d/arduino/figures/lcdSetCursor.svg)

## 4. Effacer

La fonction ```lcd.clear()``` permet d'effacer **entièrement** l'écran lcd, nous donnons la structure de cette fonction ci-dessous :

![](/psti2d/arduino/figures/lcdClear.svg)

## 5. Écrire

La fonction ```lcd.print()``` permet d'écrire ce que l'on veut sur le lcd mais ne **gère pas le dépassement** (écrire au delà des 16 colonnes et 2 lignes), **c'est au développeur de vérifier deux fois que ce qu'il souhaite écrire tienne bien dans la place impartie.** Nous donnons la structure de cette fonction ci-dessous :

* Pour écrire une chaîne de caractères :

![](/psti2d/arduino/figures/lcdPrintChaine.svg)

* Pour écrire le contenu d'une variable :

![](/psti2d/arduino/figures/lcdPrintVar.svg)

Nous donnons ci-dessous un code exemple **complet** de l'utilisation de ```lcd.print()``` et montrons le résultat sur l'écran lcd :

```c++
#include <Wire.h> //Ajout de la bibliothèque i2c pour utiliser le lcd
#include "rgb_lcd.h" //Ajout de la bibliothèque du lcd

rgb_lcd lcd;  //Constructeur rgb_lcd pour l'objet lcd

int cpt=0; //Déclaration d'un entier "cpt" initialisé à 0 pour compter le nombre de cycles d'affichages

void setup() //Initialisations
{
    lcd.begin(16, 2); //Initialisation du lcd de 16 colonnes et 2 lignes    
}

void loop() //Programme principal
{
    lcd.setCursor(0,0); //On commence à écrire en haut à gauche
    lcd.print("hello, world!"); //On écrit "hello, world!"
    lcd.setCursor(0,1); //On se met sur la ligne du bas à gauche
    lcd.print("STI2D SIN"); //On écrit "STI2D SIN"
    delay(3000); //On attend 3s
    lcd.clear(); //On efface le lcd

    lcd.setCursor(0,0); //On commence à écrire en haut à gauche
    lcd.print("Lycee GT"); //On écrit "Lycee LGT"
    lcd.setCursor(0,1); //On se met sur la ligne du bas à gauche
    lcd.print("L.Rascol Albi"); //On écrit "L.Rascol Albi"
    delay(3000); //On attend 3s
    lcd.clear(); //On efface le lcd

    lcd.setCursor(0,0); //On commence à écrire en haut à gauche
    lcd.print("Affichage : "); //On écrit "Affichage : "
    lcd.setCursor(13,0); //On se met sur la 13 ème colonne de la première ligne
    lcd.print(cpt); //On écrit le contenu de la variable cpt
    delay(3000); //On attend 3s
    lcd.clear(); //On efface le lcd

    cpt++ //On incrémente de 1 la variable cpt
}
```
![](/psti2d/arduino/figures/lcd_ex_print.svg)

## 6. Changer la couleur

Le module *LCD RGB Backlight* comme son nom l'indique contient des leds RGB pour Red Green Blue. En faisant varier l'intensité de chaque composante nous pouvons choisir la couleur du rétro-éclairage parmi une infinité. Nous donnons ci-dessous la structure de la fonction ```lcd.setRGB()``` à paramétrer dans le ```void setup()```.

![](/psti2d/arduino/figures/lcdSetRGB.svg)

L'intensité de chaque couleur se code sur **8 bits, soit une valeur entre 0 et 255.** Nous donnons ci-dessous un code exemple pour un éclairage en rouge et montrons le résultat sur l'écran lcd :

```c++
#include <Wire.h> //Ajout de la bibliothèque i2c pour utiliser le lcd
#include "rgb_lcd.h" //Ajout de la bibliothèque du lcd

rgb_lcd lcd;  //Constructeur rgb_lcd pour l'objet lcd

void setup() //Initialisations
{
    lcd.begin(16, 2); //Initialisation du lcd de 16 colonnes et 2 lignes
    lcd.setRGB(255,0,0); //Configuration de l'éclairage en rouge
}

void loop() //Programme principal
{
    lcd.setCursor(0,0); //On commence à écrire en haut à gauche
    lcd.print("hello, world!"); //On écrit "hello, world!"
    lcd.setCursor(0,1); //On se met sur la ligne du bas à gauche
    lcd.print("STI2D SIN"); //On écrit "STI2D SIN"           
}
```
![](/psti2d/arduino/figures/lcd_ex_rgb.svg)