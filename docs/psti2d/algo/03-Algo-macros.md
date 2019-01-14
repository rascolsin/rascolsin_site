# Création et utilisation de macros en algorithmique

Une macro aussi appelée sous-programme ou fonction est une suite d'instuctions définies à l'avance, pouvant être éxectuée à l'infini. Une macro est utilisée pour, par exemple simplifier le code en limitant les répétitions.

## 1. Création d'une macro sans paramètres d'entrée ni de sortie

La figure ci-dessous montre l'exemple de la déclaration d'une telle macro, de manière algorithmique :

![](/psti2d/algo/figures/macro_sans_param.svg)


## 2. Création d'une macro avec paramètre d'entrée

La figure ci-dessous montre l'exemple de la déclaration d'une telle macro, de manière algorithmique :

![](/psti2d/algo/figures/macro_avec_param-entree.svg)



## 3. Création d'une macro avec paramètres d'entrée et de sortie

La figure ci-dessous montre l'exemple de la déclaration d'une telle macro, de manière algorithmique :

![](/psti2d/algo/figures/macro_avec_param-entree_sortie.svg)

## 4. Appel de macros

Pour appeler une macro dans un algorithme il suffit de citer son nom, suivi entre parentheses des paramètres d'entrée :

* Pour une macro sans paramètres d'entrée ni de sortie :
```
ma_macro()
```

* Pour une macro avec paramètres d'entrée seulement :
```
ma_macro(param1,param2)
```

* Pour une macro avec paramètres d'entrée et de sortie :
```
ma_variable = ma_macro(param1,param2)
```
