# Activité : Linux et le réseau

<!-- TODO Sur le Raspberry Pi la config avec ifup/ifdown ne marche pas, le fichier network/interfaces ne peut en théorie pas être modifié, on peut changer les adresses IP dans le menu raspi-config
TODO Le serveur ssh est déjà installer dans Raspbian mais il faut l'activer dans raspi-config -->

## 1 - Création d'un nouvel utilisateur

La distribution en "live USB" crée un utilisateur "xubuntu" d'office sans mot de passe, pour une connexion à distance sur votre machine vous aurez besoin de créer un nouvel utilisateur avec mot de passe.

Pour cela il s'agit d'utiliser la commande : `adduser`, qui va créer un nouvel utilisateur avec possibilité de lui assigner un mot de passe, nom, prénom, adresse... Le site Ubuntu France, donne une explication complète de l'utilisation de cette commande allez y jeter un coup d'œil : [Ubuntu France tutoriel adduser](https://doc.ubuntu-fr.org/adduser)

![](/tsti2d/linux/figures/sandwich.png)

<sup>
<a href="https://xkcd.com/149/">"Sandwich"</a>, by <a href="https://xkcd.com">XKCD</a>
used under <a href="https://creativecommons.org/licenses/by-nc/2.5/">CC BY-NC 2.5</a>
</sup>

L'utilisateur créé ne dispose des privilèges root (super utilisateur, le `sudo`), il faut donc l'ajouter à la liste des `sudoers`, pour se faire suivez l'explication donnée par le site : [Ubuntu France tutoriel sudoers](https://doc.ubuntu-fr.org/sudoers)

!!! question
    1. Utilisez la commande `adduser` pour créer un nouvel utilisateur de votre choix, définissez également un mot de passe.

    2. Rajoutez une ligne au fichier `/etc/sudoers` pour autoriser l'accès au privilèges super utilisateur à votre nouvel utilisateur : `Nom_utilisateur ALL=(ALL:ALL) ALL`

    3. Identifiez vous avec le nouvel utilisateur créé avec `su nom_nouvel_utilisateur`

## 2 - Le gestionnaire de paquets

Les applications d'un système GNU/Linux sont gérées par un gestionnaire de paquet (**apt** pour Debian et donc Ubuntu, **yum** pour Fedora et **pacman** pour Archlinux) pour installer une application, nous ne procédons pas comme sur Windows où il s'agit la plupart du temps d'aller récupérer le fichier d'installation sur le site du fabricant, ou sur un site généraliste à la merci des virus et programmes publicitaires... Sur GNU Linux les applications sont dans des bases de données appelées **repositories**, chaque application est ainsi constamment maintenue à jour, vous êtes donc certains d'installer la dernière version et ce de manière fiable. Un gros avantage : la mise en jour de l'ensemble des applications du système se fait d'un seul coup, grâce au gestionnaire de paquets.

Avant d'installer quoi que ce soit sur la distribution **il faut toujours mettre à jour les repositories et ensuite mettre à jour le système**. Pour ce faire nous utilisons la commande `apt update` puis `apt upgrade`

!!! question
    1. Utilisez la commande `apt update` **en mode super utilisateur** pour mettre à jour les bases de données.

    2. Utilisez la commande `apt upgrade` **en mode super utilisateur** pour mettre à jour le système.

## 3 - La configuration réseau sous Linux

La commande `ifconfig` permet de visualiser la configuration réseau de l'ordinateur, grâce à elle nous pouvons obtenir des informations sur l'adresse IP, l'adresse MAC ou encore l'interface réseau utilisée.

!!! question
    1. Utilisez la commande `ifconfig` pour obtenir le nom de l'interface réseau utilisé

    2. Utilisez la même commande pour obtenir votre adresse IP

A présent nous souhaitons modifier l'adresse IP de l'interface réseau utilisé, pour ce faire nous utiliserons la commande `ifconfig eth0 nouvelle-adresse`, la nouvelle adresse étant l'adresse de l'ordinateur correspondant à la salle et au bâtiment donnée par le gestionnaire réseau.

Au lycée Rascol, les adresses IP des postes informatiques sont configurées de cette manière :

**10.bbb.ccc.ddd**

* **bbb** : Bâtiment (si bâtiment E : 5)
* **ccc** : Salle (si salle 007 : 7)
* **ddd** : Numéro du PC

!!! question
    3. Désactivez l'interface réseau où vous allez changer la configuration avec `ifdown eth0`

    4. Utiliser la commande `ifconfig` pour changer l'adresse IP de l'ordinateur, en la mettant au *format Rascol*

    5. Réactivez l'interface réseau avec `ifup eth0`

Pour faire une configuration réseau plus poussée, nous pouvons modifier le fichier `/etc/network/interfaces`, fichier de configuration pour le réseau sur chaque distribution linux.

!!! question
    6. Editez le fichier `/etc/network/interfaces` à l'aide de nano pour obtenir la configuration suivante :

        - adresse IP : Celle de Rascol configurée précédemment
        - passerelle : 10.255.5.204
        - masque de sous réseau : 255.0.0.0
        - serveur dns : Celui de Google

    7. Relancez ensuite la configuration des interfaces réseau pour mettre à jour vos changements : `/etc/init.d/networking restart`

Pour vous aider nous donnons ci-dessous un fichier type de configuration réseau Linux :

```
auto lo eth0

iface lo inet loopback

iface eth0 inet static
address 192.168.0.42
netmask 255.255.255.0
gateway 192.195.0.1
dns-nameservers 192.0.2.71
```


## 4 - Les transferts réseaux

### a - Commande ``ping``

Avant de transférer un document ou de se connecter à un ordinateur distant, il faut vérifier si celui-ci est présent sur le réseau. La commande `ping` en utilisant une requête [ICMP](https://fr.wikipedia.org/wiki/Internet_Control_Message_Protocol), le protocole va envoyer un paquet sur la cible, si la cible est accessible elle va répondre à la requête en envoyant un paquet à l'émetteur.

!!! question
    1. Utiliser la commande ``ping`` pour vérifier l'accessibilité du site web de votre choix. Relevez le temps aller-retour (round trip time).

    2. Utilisez la même commande sur l'adresse IP de votre voisin de TP. Relevez le temps aller-retour.

### b - Prendre la main à distance avec ssh

Le protocole ssh permet de se connecter de manière sécurisée (transferts cryptés) à un ordinateur linux distant. Pour vous connecter à votre machine à distance vous devez installer un serveur ssh, le client installé d'office permet juste de se connecter à partir de votre machine à une autre.

* Installez le paquet ``openssh-server``

La connexion à ordinateur distant se fait en utilisant la commande :

``ssh nom_utilisateur_cible@adresse_ip_cible``

!!! question
    3. Connectez-vous en ssh à l'ordinateur de votre voisin de TP

    4. Créez sur son bureau un fichier ``robot.bak`` avec nano du contenu de votre choix.

    5. Demandez à votre voisin si le fichier est bien sur son bureau.
