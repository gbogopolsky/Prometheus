# Un fichier pour compiler et exécuter le programme
# Il contient des lignes de commandes à la suite qu'il va effectuer.
#
# Pour le rendre exécutable, il suffit de taper : 
# chmod +x launch.sh
# 
# Puis de l'exécuter avec : 
# ./launch.sh
#
# Voilà ;)

g++ -c Main.cpp Vecteur.cpp Objet.cpp
g++ Main.o Objet.o Vecteur.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
rm Main.o Objet.o Vecteur.o
./sfml-app

