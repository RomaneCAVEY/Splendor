# Sujet de projet de programmation du S5

Pour compiler , on utiise la commande suivante:

make project
./project

Si on veut tester uniquement les tests faire:

make test

On peut ajouter des options après le ./project : 

-s 	# and an optional parameter to initialize the RNG (here 156)
-m	# One optional parameter for MAX_TURNS (here 10),
-c	 # an optional parameter to pass to init_builders (here 2)