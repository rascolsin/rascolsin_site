# Activité : Écrire des scripts Bash

## Exercice 1 : Tables de multiplication 

Créez un script Bash affichant la table de multiplication d'un nombre entier rentré par l'utilisateur.

Le comportement devra être le suivant :

<script id="asciicast-9hzruFZDTLheuZa1tRcxUBcEv" src="https://asciinema.org/a/9hzruFZDTLheuZa1tRcxUBcEv.js" async></script>

!!! question
    - Écrivez le script Bash en utilisant l'éditeur de votre choix.
    - Vérifiez le fonctionnement en lançant le script et en le testant
    - Appelez l'enseignant pour vérifier

## Exercice 2 : Jeu deviner un nombre

Créez un jeu dans lequel l'ordinateur tire un nombre entre 2 valeurs données en paramètres d'entrée, puis propose à l'utilisateur de deviner ce nombre en 5 essais.
Si il n'y parvient pas mettez fin au script.

Le comportement devra être le suivant :

<script id="asciicast-rj5cb2f32ZQaPpUsFZXUqSvUf" src="https://asciinema.org/a/rj5cb2f32ZQaPpUsFZXUqSvUf.js" async></script>

??? note "Tirer un nombre aléatoire en Bash"
    Pour créer un nombre aléatoire en Bash, il faut utiliser la fonction `$RANDOM` qui donne en retour un entier signé, soit un nombre entre 0 et 32767.

    Pour borner ce nombre aléatoire entre 2 valeurs : [a;b] il faut utiliser la fonction modulo noté `%` En Bash renvoyant le reste d'une division Euclidienne. En effet, le reste d'une division de x par y est toujours compris entre 0 et y (exclu)
