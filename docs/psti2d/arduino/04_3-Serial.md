# Le Serial

Le port série Serial ou encore UART est un protocole de communication filaire, où les données à transmettre sont envoyées par paquets de 8 bits. Le port série est un des moyens qu'a une carte Arduino pour communiquer avec des éléments externes comme une autre carte ou un ordinateur.

## 1. Fonctionnement
L'UART (Universal Asynchronous Receiver Transmitter) est un des périphériques du micro-contrôleur qui vient gérer la liaison série, ce protocole de communication nécessite 3 fils. La figure ci-dessous montre le câblage nécessaire pour une transmission série par l'UART entre 2 cartes Arduino UNO.

![](/psti2d/arduino/figures/FigureSerial.svg)

Les données transitent par la liaison série sous forme de **paquets de 8bits plus 1 bit de start et 1 bit de stop**, nous donnons ci-dessous une trame, exemple d'émission par l'UART :

![](/psti2d/arduino/figures/SignalUART.svg)

Décrivons les étapes de cet envoi qui débute à gauche du graphe et se termine à droite :

1. La liaison est au **repos au niveau "1" à 5V** dans un état que l'on apelle **"Idle"** en Anglais.

2. La liaison détecte le début d'émission par le passage de l'état Idle à "0" => **C'est le bit de start**.

3. Les **8 bits du message** sont envoyés en commençant par le bit de poids faible le **LSB** (Least Significant Bit) et se termine par le bit de poids fort le MSB (Most Significant Bit). Si le message que l'on souhaite envoyer est codé sur plus de 8 bits il sera découpé en paquet de 8 obligatoirement.

4. La liaison termine son émission par un **bit de stop à "1"** avant de retourner à l'état Idle.

## 2. ```Serial.begin()```
La fréquence d'émission soit le nombre de **Bauds** (bits par seconde) est définie avec la fonction Arduino ```Serial.begin()```, notons que cette durée ne varie pas dans la suite du code une fois qu'on en a fait le paramétrage dans le ```void setup()```. Nous donnons ci-dessous la structure de cette fonction :

![](/psti2d/arduino/figures/SerialBegin.svg)

!!! warning
    Le protocole de transmission série étant asynchrone l'horloge qui permet de synchroniser les signaux entre l'émetteur et le récepteur n'est pas transmise. Il faut donc que la **fréquence d'émission soit la même sur l'émetteur et sur le récepteur.**

Nous donnons ci-dessous un code exemple Arduino pour le paramétrage d'une liaison série à 9600 Bauds :

```c++
void setup()//Initialisations
{
  Serial.begin(9600);//Initialisation du port série avec une fréquence d'émission de 9600 Bauds
}
```

## 3. ```Serial.print()``` et ```Serial.println()```

Deux fonctions permettent d'écrire simplement des messages sur le port série d'une carte Arduino :

* ```Serial.print()``` : Permet d'écrire de multiples choses sur le serial sans se soucier si le contenu de notre message est d'une taille supérieure à 8 bits. **La fonction fait elle même le partage en paquets de 8 bits**. Nous donnons ci-dessous la structure de cette fonction :

![](/psti2d/arduino/figures/SerialPrint.svg)

* ```Serial.println()``` : Fait la même chose que la fonction précédente mais provoque un renvoi à la ligne **en fin d'émission**. Nous donnons ci-dessous la structure de cette fonction :

![](/psti2d/arduino/figures/SerialPrintln.svg)

Nous donnons ci-dessous un code exemple complet comprenant l'initialisation du serial et l'utilisation des deux fonctions précédentes :

```c++
int Tutu=2345; //Déclaration d'un entier initialisé à 2345
float Tomaas=3.14;//Déclaration d'un flottant initialisé à 3.14

void setup()//Initialisations
{
  Serial.begin(9600);//Initialisation du port série avec une fréquence d'émission de 9600 Bauds
}

void loop()//Programme principal
{
  Serial.print("Ma variable Tutu contient : ");//Ecriture d'une chaine de caractères sur le serial
  Serial.println(Tutu);//Ecriture du contenu de Tutu et retour à la ligne
  Serial.print("Ma variable Tomaas contient : ");//Ecriture d'une chaine de caractères sur le serial
  Serial.println(Tomaas);//Ecriture du contenu de Tomaas et retour à la ligne
}
```

Une fonction sur l'Arduino IDE appelée **Moniteur série** permet d'afficher ce que notre carte Arduino écrit sur le serial grâce à la liaison usb. (Les pins Rx et Tx du port série sont retransmises sur le port USB). Observons ce que notre code produit sur le moniteur série :

![](/psti2d/arduino/figures/OutputSerialMonitor.svg)

Le code précédent affiche de manière infinie (Nous rappelons que le ```void loop()``` est équivalent à un ```while(1)```) la première chaîne de caractère, le contenu de la variable Tutu, retourne à la ligne puis affiche la seconde chaîne de caractères et affiche la variable Tomaas pour à nouveau retourner à la ligne et recommencer...
