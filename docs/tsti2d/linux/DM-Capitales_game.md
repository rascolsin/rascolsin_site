# DM de Noël : Jeu devine la capitale

Nous donnons ci-dessous un fichier contenant la liste des 196 pays reconnus par l'ONU dans le monde, ce fichier en langue Anglaise est organisé de la manière suivante :

```bash
Costa Rica -- San Jose
Cote d'Ivoire -- Yamoussoukro
Croatia -- Zagreb
Cuba -- Havana
```

Chaque ligne comporte un pays suivi par sa capitale, les deux sont séparés par `--` 

A télécharger ici : [capitales.txt](https://rascolsin.fr/tsti2d/linux/ressources/capitales.txt)

```bash
wget https://rascolsin.fr/tsti2d/linux/ressources/capitales.txt
```

Le script que vous devez réaliser, tire de manière aléatoire une ligne parmi les 196, affiche à l'écran le nom du pays et demande à l'utilisateur de saisir la capitale correspondante.

L'utilisateur à le droit à 5 tentatives, si les 5 tentatives sont infructueuses le programme met fin à la partie.