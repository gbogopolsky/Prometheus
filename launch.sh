# Il contient des lignes de commandes � la suite qu'il va effectuer.
#
# chmod +x launch.sh
# 
# ./launch.sh
#
# Voil� ;)

g++ -c Main.cpp Vecteur.cpp Objet.cpp
g++ Main.o Objet.o Vecteur.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-systems
./sfml-app
