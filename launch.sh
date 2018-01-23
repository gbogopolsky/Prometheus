# Un fichier pour compiler et ex�cuter le programme
# Il contient des lignes de commandes � la suite qu'il va effectuer.
#
# Pour le rendre ex�cutable, il suffit de taper :
# chmod +x launch.sh
#
# Puis de l'ex�cuter avec :
# ./launch.sh
#
# Voil� ;)

g++ -c Main.cpp Vecteur.cpp Objet.cpp CorpsStellaire.cpp Vaisseau.cpp Planete.cpp 
g++ Main.o Objet.o Vecteur.o Objet.o CorpsStellaire.o Vaisseau.o Planete.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
#rm Main.o Objet.o Vecteur.o
./sfml-app
