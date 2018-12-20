# Partager un fichier sur PasteBin en ligne de commande

Vous êtes connecté sur un raspberry pi sans l'interface graphique et vous voulez partager un code ? Une solution simple consiste à mettre ce code sur un service de partage de code comme PasteBin ou Gist.

Pour ce faire téléchargez l'utilitaire `pastebinit` : `sudo apt install pastebinit`

La commande `pastebinit -l` affiche tous les services en ligne disponibles pour le partage :

```bash
$ pastebinit -l
Supported pastebins:
- cxg.de
- fpaste.org
- p.defau.lt
- paste.debian.net
- paste.drizzle.org
- paste.kde.org
- paste.openstack.org
- paste.pocoo.org
- paste.pound-python.org
- paste.ubuntu.com
- paste.ubuntu.org.cn
- paste2.org
- pastebin.com
- pastie.org
- pb.daviey.com
- slexy.org
- sprunge.us
```

Par exemple pour partager un script appelé `foobar.sh` avec le service pastebin.com il suffit de taper :

```bash
$ pastebinit -i foobar.sh -b pastebin.com
```

La commande vous retourne le lien de partage de votre code !