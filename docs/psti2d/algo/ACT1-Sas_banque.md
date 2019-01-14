# Activité : Sas de banque

## 1. Présentation du système

La plupart des établissements bancaires disposent d'entrées sécurisées appelées sas. Ce type d'entrée est composée de 2 portes en verre épais et d'un espace tampon entre, l’accès est contrôlé par une console à l’accueil, les demandes d'entrées se font par un boîtier au niveau de la première porte et un autre boîtier au niveau de la seconde.

### 1.1 Fonctionnement

* Quand un client ou un visiteur souhaite accéder à l'établissement il demande l'ouverture de la première porte en appuyant sur le bouton du boîtier d'entrée, après un contrôle visuel l'agent d'accueil a alors la possibilité d'ouvrir ou non l'entrée du sas. Le client une fois rentré dans le sas doit attendre la fermeture puis le verrouillage de la première porte, il doit ensuite appuyer sur un autre bouton pour demander l'ouverture de la seconde porte et ainsi accéder à l'accueil.

* Un client peut demander à entrer dans le sas **seulement lorsque les deux portes sont fermées et verrouillées**.

* Quand le client souhaite sortir de l'établissement, l'agent d'accueil doit d'abord lui ouvrir la seconde porte, attendre que le client rentre dans le sas, attendre la fermeture et le verrouillage de la seconde porte puis lui ouvrir la première.

* Les portes se **verrouillent automatiquement** lorsque leur **bouton d'ouverture sur la console d'accueil, est relâché**.

![](/psti2d/algo/figures/Sas_banque.svg)

![](/psti2d/algo/figures/boitiers_banque.svg)


### 1.2 Matériel

Vous avez à votre disposition pour réaliser la commande de ce système, les capteurs et actionneurs suivants :

#### Capteurs

| Nom | Code | Description |
|---|---|---|
|Capteur d'état porte 1|ep1|0 si porte 1 ouverte, 1 si porte 1 fermée|
|Capteur d'état porte 2|ep2|0 si porte 2 ouverte, 1 si porte 2 fermée|
|Bouton poussoir d'ouverture porte 1|bpop1|0 si bp relâché, 1 si bp appuyé|
|Bouton poussoir d'ouverture porte 2|bpop2|0 si bp relâché, 1 si bp appuyé|
|Bouton poussoir demande d'ouverture porte 1|bpd1|0 si bp relâché, 1 si bp appuyé|
|Bouton poussoir demande d'ouverture porte 2|bpd2|0 si bp relâché, 1 si bp appuyé|

#### Actionneurs

| Nom | Code | Description |
|---|---|---|
|Led demande ouverture porte 1|ldp1|0 pour éteindre, 1 pour allumer|
|Led demande ouverture porte 2|ldp2|0 pour éteindre, 1 pour allumer|
|Led verrouillage porte 1|lvp1|0 pour éteindre, 1 pour allumer|
|Led verrouillage porte 2|lvp2|0 pour éteindre, 1 pour allumer|
|Led déverrouillage porte 1|ldvp1|0 pour éteindre, 1 pour allumer|
|Led déverrouillage porte 2|ldvp2|0 pour éteindre, 1 pour allumer|
|Led refus boîtier porte 1|lrp1|0 pour éteindre, 1 pour allumer|
|Led refus boîtier porte 2|lrp2|0 pour éteindre, 1 pour allumer|
|Led accord boîtier porte 1|lap1|0 pour éteindre, 1 pour allumer|
|Led accord boîtier porte 2|lap2|0 pour éteindre, 1 pour allumer|
|Verrou porte 1|vp1|0 pour déverrouiller, 1 pour verrouiller|
|Verrou porte 2|vp2|0 pour déverrouiller, 1 pour verrouiller|

## 2. Travail à faire

Vous devez réaliser l'algorithme du sas de banque en respectant les étapes suivantes.

### A. Création du programme principal

Nous souhaitons réaliser l'algorithme permettant la gestion du sas, **dans un premier temps vous ne vous occuperez pas de gérer les LEDs sur les boîtiers de commandes**.

!!! note "A faire"
    * Écrivez votre algorithme sur une feuille libre **au crayon à papier** en vous servant du squelette donné ci-dessous.
    * Appelez l'enseignant pour valider, une fois le travail terminé.

![](/psti2d/algo/figures/Algo_Sas_banque_prog_princ.svg)

### B. Ajout des leds de demandes d'ouverture

A présent nous souhaitons allumer les leds de demande d'ouverture :

* Quand le client appui sur `bpd1`, `ldp1` doit s'allumer jusqu'à ce que l'agent d'accueil ouvre la porte 1.
* Quand le client appui sur `bpd2`, `ldp2` doit s'allumer jusqu'à ce que l'agent d'accueil ouvre la porte 2.

!!! note "A faire"
    * Rajoutez à l'algorithme précédent les lignes de gestion des deux leds de demande d'accès.
    * Appelez l'enseignant pour valider, une fois le travail terminé.

### C. Ajout de la macro led

A présent nous souhaitons ajouter les leds restantes (`lvp1`,`lvp2`,`ldvp1`,`ldvp2`,`lrp1`,`lap1`,`lrp2`,`lap2`) à l'algorithme de gestion du sas de banque, une macro appelée `leds_etats_portes` sera dédiée à cette tâche, nous en donnons le prototype ci-dessous :

```
vide leds_etats_portes (booleen etat_p1, booleen etat_p2)
```

!!! note "A faire"
    * Écrivez votre algorithme sur une feuille libre **au crayon à papier** en vous servant du squelette donné ci-dessous.
    * Rajouter l'appel de la macro que vous venez de créer au programme principal.
    * Appelez l'enseignant pour valider, une fois le travail terminé.

![](/psti2d/algo/figures/Algo_Sas_banque_macro.svg)