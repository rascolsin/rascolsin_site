---
title: "Déclencher une interruption sur un événement du Serial avec Arduino"
categories: jekyll update
permalink: arduino_serial_interrupt.html
tags: [news,arduino]
published: false
---
Pour certains projets Arduino nous avons parfois besoin de pouvoir réagir à n'importe quel moment sur événement du Serial. Le fonctionnement classique dans le `void loop()` avec `if (Serial.available())` permet de réagir sur un événement du Serial, seulement si celui-là apparaît quand le programme est sur la condition `if()`, or si la programme est déjà occupé à faire autre chose, jamais il ne détectera l'envoi. La seule solution est donc l'utilisation d'une interruption.

Dans la suite de ce post nous donnons une adaptation du code Arduino `serial_interrupt.ino`
, produit par [Ricardo Mena Cortés](https://github.com/wifixcort), que vous pouvez trouver [ici](https://github.com/wifixcort/serial_event_interrupt/blob/master/serial_interrupt.ino).
