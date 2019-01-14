# Activité : Calculatrice

## 1. Présentation du système

Nous souhaitons réaliser une calculatrice effectuant les calculs de base suivants :

* L'addition
* La soustraction
* La multiplication
* La division

Notre calculatrice effectuera des calculs **seulement entre 2 nombres**.

Pour simplifier l'algorithme nous demanderons à l'utilisateur de **choisir son calcul avant de rentrer les nombres**.

### 1.1 Fonctionnement

Quand le bouton d'allumage est sur la position ON, l'écran de la calculette  affichera le menu suivant :

```
Choisissez votre calcul, puis appuyez sur ENTER :
1 - addition
2 - soustraction
3 - multiplication
4 - division
```
Une fois que l'utilisateur a saisi son choix sur le clavier et appuyé sur `ENTER`, l'écran s'effacera et devra afficher :

```
Rentrez le premier nombre, appuyez sur ENTER :
```
Une fois le nombre saisi et l'appui sur la touche `ENTER` effectués, l'écran s'effacera et demandera la saisie du second nombre :

```
Rentrez le second nombre, appuyez sur ENTER :
```

L'écran s'effacera et affichera le calcul à effectuer, nous donnons ci-dessous l'exemple pour l'opération 6+1 :

```
Calcul a effectuer, appuyez sur ENTER :
6+1
```

Pour finir l'écran s'efface et le résultat du calcul est affiché :

```
Résultat :
6+1=7
```

Une fois le calcul effectué l'écran s'effacera et, **le menu sera à nouveau affiché** l'utilisateur pourra effectuer un nouveau calcul si il le souhaite.

### 1.2 Matériel

Vous avez à votre disposition pour réaliser ce système, les macros, capteurs et actionneurs suivants :

#### Capteurs

| Nom | Code | Description |
|---|---|---|
|Touche entrée|`ENTER`|Permet de valider un choix ou un calcul|

#### Macros

| Fonction à appeler | Code |Rôle |
|---|---|---|
|Ecrire sur le lcd|`LCD_ecrire("chaine de carcactères")` ou `LCD_ecrire(variable)`|Permet d'écrire une chaîne de caractères ou le contenu d'une variable sur l'écran.|
|Effacer le contenu de l'écran lcd|`LCD_effacer()`|Permet d'effacer l'écran|
|Lire le clavier numérique|`flottant nombre=Lire_clavier()`|Permet de lire le nombre ou le choix rentrés par l'utilisateur, renvoi le résultat dans un flottant.|

## 2. Travail à faire

Vous devez réaliser l'algorithme du sas de banque en respectant les étapes suivantes.

### A. Création des macros de calculs

Dans un premier temps nous souhaitons créer les 4 macros correspondant aux 4 calculs de base effectués par la calculatrice. Nous en donnons les prototypes ci-dessous :

```
flottant addition(flottant nb1, flottant nb2)
flottant soustraction(flottant nb1, flottant nb2)
flottant multiplication(flottant nb1, flottant nb2)
flottant division(flottant nb1, flottant nb2)
```
!!! note "A faire"
    * Écrivez l'algorithme des 4 macros sur une feuille libre **au crayon à papier**
    * Appelez l'enseignant pour valider, une fois le travail terminé.

### B. Affichage du menu et saisie du choix utilisateur

Nous souhaitons à présent créer le programme principal qui affiche le menu, lit le choix de l'utilisateur et le stocke dans une variable `choix_menu`. Il s'agit ensuite de demander à l'utilisateur de saisir le premier nombre à stocker dans `nb1`, puis le second dans `nb2`

!!! note "A faire"
    * Écrivez l'algorithme du programme principal à la suite de votre feuille **au crayon à papier**
    * Appelez l'enseignant pour valider, une fois le travail terminé.

### C. Réalisation du calcul et affichage du résultat

Pour effectuer le calcul nous utiliserons une structure `choix` qui orientera l'execution vers le calcul choisi par l'utilisateur et affichera le résultat.

!!! note "A faire"
    * Terminez l'algorithme du programme principal à la suite de votre feuille **au crayon à papier**
    * Appelez l'enseignant pour valider, une fois le travail terminé.