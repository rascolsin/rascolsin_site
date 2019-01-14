# Utilisation de variables

## 1. Les types de variables

![](/psti2d/arduino/figures/Boites_gigognes.svg)

### 1.1 Le booléen

![](/psti2d/arduino/figures/Boite_bool.svg)

Le booléen est le plus petit type de variable que vous serez emmené à rencontrer, il est codé sur seulement 2 bits. Son contenu ne peut être que **0 ou 1**, soit ```Vrai```ou ```Faux```.
Ce type est souvent utilisé pour stocker l'état d'un capteur numérique, par exemple un bouton poussoir : ```Vrai```si le bouton est appuyé, ```Faux```si il est relâché.

### 1.2 L'octet

![](/psti2d/arduino/figures/Boite_octet.svg)

L'octet est un type de variable codé sur 8 bits. Son contenu est un nombre pouvant aller de **0 à 255**.

### 1.4 L'entier

![](/psti2d/arduino/figures/Boite_entier.svg)

L'entier est codé sur 16 bits. Son contenu est un nombre pouvant aller de ${-2}^{15}$ à ${2}^{15}-1$ soit de -32768 à 32767. Le calcul des extrema se fait sur 15 bits et non pas sur 16 car le bit de poids fort est réservé pour le bit de signe, si celui-ci est à 1 le complément à deux du nombre qui suit est interprété comme un négatif, inversement pour un positif.


### 1.5 Le flottant

![](/psti2d/arduino/figures/Boite_flottant.svg)

Le flottant est codé sur 4 octets soit 32 bits. Son contenu est un nombre pouvant aller de 3.4028235E+38 à -3.4028235E+38.

**Codage d'un nombre en virgule flottante :**
La virgule flottante est une technique pour stocker dans une variable un nombre réel. Pour cela il suffit de décomposer le nombre de la manière suivante :

![](/psti2d/arduino/figures/Flottant.svg)

* Le bit de poids fort est le bit de signe, il est à 1 si le nombre est négatif, à 0 si il est positif.
* La mantisse contient les chiffres significatifs du nombre elle est codée sur 23 bits.
* L'exposant représente la place de la virgule dans le nombre, il est codé sur 8 bits.

### 1.6 Le caractère

![](/psti2d/arduino/figures/Boite_char.svg)

Le caractère est un type de variable codé sur 8 bits. Son contenu est un **caractère**, codé avec son code décimal ASCII correspondant. Pour enregistrer un caractère il suffit de le mettre entre côtes : ```'a'``` , si on souhaite enregistrer le code **décimal** ASCII correspondant au caractère souhaité il suffit de le noter tel quel. Pour ```'a'``` le code ASCII correspondant est 97.

**Le codage ASCII**

> L'ASCII pour *American Standard Code for Information Interchange* (Code américain normalisé pour l'échange d'information) est un système de codage des caractères inventé dans les 60 par l'ISO (*International Organization for Standardization*). C'est un système de codage devenu un standard pour transmettre l'information de manière numérique. 

Pour de plus amples renseignements sur la création du code ASCII n'hésitez pas à consulter la page [Wikipédia](https://fr.wikipedia.org/wiki/American_Standard_Code_for_Information_Interchange) dédiée.

![](/psti2d/arduino/figures/ASCII-Table.svg)

## 2. La déclaration et l'initialisation de variables

Pour utiliser une variable dans son algorithme il faut au préalable la créer, en programmation on parlera de **déclarer une variable**. Les déclarations de variables se font au début du programme si elles sont globales, au début de la macro si elles sont locales. Quand on déclare une variable on a pour obligation de lui donner un nom, et de préciser son type, il est préférable également de l'initialiser, c'est à dire lui donner une valeur de départ.

!!! note
    * Une **variable locale** ne peut s'utiliser que dans la macro ou le programme principal où elle est déclarée.
    * Une **variable globale** se déclare en début de l'algorithme et peut s'utiliser n'importe où.

Pour déclarer et initialiser une variable il suffit d'utiliser l'instruction suivante :

<img src="/psti2d/algo/figures/Declaration_variable.svg" width="50%">

Dans cet exemple nous venons de déclarer une variable de type entier appelée *ma_variable* et initialisée à 124.

!!! warning
    Les noms de variables ne doivent **pas contenir d'espaces, d'accents, de caractères spéciaux autre que ```_```**.  Les minuscules et les majuscules sont aussi différenciées.


## 3. La déclaration de constantes

Une constante à l'inverse d'une variable, ne varie pas lors de l'exécution du programme elle reste à la valeur à laquelle elle a été initialisée. Cela est très utile pour **définir un numéro de pin ou une constante comme le nombre pi.**

<img src="/psti2d/algo/figures/Declaration_constante.svg" width="60%">

Ici nous déclarons une constante appelée ```ma_constante``` et initialisée à la valeur 234.

## 4. Utilisation de variables ou de constantes

En algorithmique pour **tester** le contenu d'une variable nous utiliserons des opérateurs de comparaison comme `=`, `<`, `>` pouvant être couplés avec des opérateurs logiques. Pour **affecter** une valeur à une variable nous utiliserons la flèche : $mavariable \Leftarrow 22$

| Opérateurs de comparaison |   |
|:------------- |:---------------|
| ```==```     | Egalité |
| ```!=```      | Différence        |
| ```<```| Inférieur       |
| ```>``` | Supérieur        |
| ```<=``` | Inférieur ou égal        |
| ```>=```| Supérieur ou égal        |

| Opérateurs logiques |   |
|:------------- |:---------------|
| ```&&```      | Et logique |
|  &#124; &#124;     | Ou logique        |
| ```!``` | Non      |

!!! important
    Lors d'une affectation, la **variable doit être à gauche** et la **valeur à affecter à droite**