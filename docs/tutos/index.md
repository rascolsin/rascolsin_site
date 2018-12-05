# Tutoriels

## Arduino

### [Arduino et les Attiny](\tutos\arduino_attiny\arduino_attiny)

!!! note ""
    Nous expliquons dans ce post comment programmer en environnement Arduino la famille de microcontrôleurs [Attiny](http://www.atmel.com/products/microcontrollers/avr/tinyavr.aspxde) de chez Atmel. Les Attiny sont de petits microcontrôleurs (de 6 à 28 pattes disposant de peu de ressources mais sont très appréciés pour les applications d'électronique embarquée où le gain de place et la faible consommation ont une importance capitale.

### [Utiliser le module NFC de Seeed Grove](\tutos\arduino_nfc\arduino_NFC)

!!! note ""
    L'utilisation du module Grove NFC de Seeed Studio avec une carte Arduino demande quelques ajustements, nous en donnons les détails dans ce post.

### [Paramétrer une interruption sur événement du Serial](\tutos\arduino_serial_interrupt\arduino_serial_interrupt)

!!! note ""
    Pour certains projets Arduino nous avons parfois besoin de pouvoir réagir à n'importe quel moment sur événement du Serial. Le fonctionnement classique dans le `void loop()` avec `if (Serial.available())` permet de réagir sur un événement du Serial, seulement si celui-là apparaît quand le programme est sur la condition `if()`, or si la programme est déjà occupé à faire autre chose, jamais il ne détectera l'envoi. La seule solution est donc l'utilisation d'une interruption.

