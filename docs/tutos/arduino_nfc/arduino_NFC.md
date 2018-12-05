# Le module Grove NFC avec Arduino

<img src="\tutos\arduino_nfc\ressources\Grove-NFC.jpg" width="50%">

L'utilisation du module Grove NFC de Seeed Studio avec une carte Arduino demande quelques ajustements, nous en donnons les détails dans ce post.

## Ajout des bibliothèques

Tout d'abord, nous donnons ci-dessous l'ensemble des bibliothèques nécessaires au fonctionnement du module. Elles sont identiques avec celles proposées par le fabriquant **à l'exception de NDEF où un changement a été effectué**, sans cela l'Arduino était incapable de lire n'importe quelle carte.

[Bibliothèques en archive .zip](\tutos\arduino_nfc\ressources\libraries.zip) : Décompressez cette archive dans votre dossier ```Documents/Arduino/librairies/```, puis redémarrez l'IDE Arduino.

## Utilisation du module

Le code ci-dessous permet de renvoyer l'UID d'une carte NFC sur le moniteur série dès que celle-ci est présente.

```c++

// Utilisation du module Grove NFC avec une carte Arduino MEGA

#include "PN532_HSU.h"
#include "PN532.h"
#include "NfcAdapter.h"

PN532_HSU interface(Serial1); //Connexion du module Grove NFC sur le serial 1
NfcAdapter nfc = NfcAdapter(interface);

String UID_scan;
/**************************************************************************************************/

void setup()
{
    Serial.begin(9600);
    Serial.println("NDEF Reader");
    nfc.begin(); //Initialisation du module
}

void loop()
{
    if (nfc.tagPresent())
    {
        NfcTag tag = nfc.read(); //Lecture de la carte NFC
        UID_scan = tag.getUidString(); //Acquisition du code UID de la carte
        Serial.println(UID_scan); //Renvoi sur le moniteur du code UID
    }
    delay(500);
}
```

Ce nouveau code va faire de la même manière, une acquisition du code UID d'une carte NFC, et va ensuite comparer le résultat avec un code rentré en constante, si les deux correspondent, nous renvoyons ```AUTORISATION``` sur le moniteur série, dans le cas contraire nous affichons ```INTERDIT```.


```c++

// Utilisation du module Grove NFC avec une carte Arduino MEGA

#include "PN532_HSU.h"
#include "PN532.h"
#include "NfcAdapter.h"

PN532_HSU interface(Serial1); //Connexion du module Grove NFC sur le serial 1
NfcAdapter nfc = NfcAdapter(interface);

String const myUID = "7A F3 96 34"; // Définition du code UID qui garantie l'autorisation
String scannedUID;
/**************************************************************************************************/
void setup()
{
    Serial.begin(115200);
    Serial.println("NDEF Reader");
    nfc.begin();
}
/**************************************************************************************************/  
void loop()
{
    if (nfc.tagPresent())
      { NfcTag tag = nfc.read(); //Lecture de la carte NFC
        scannedUID = tag.getUidString(); //Acquisition du code UID de la carte
        Serial.println(scannedUID); //Renvoi sur le moniteur du code UID

        if( myUID.compareTo(scannedUID) == 0) //Comparaison entre les deux chaînes de caractères
          Serial.println("AUTORISATION"); // Dans le cas où elles sont identiques
        else
          Serial.println("INTERDIT"); //Dans le cas où elles diffèrent
      }
    delay(500);
}

```
