#!/bin/bash

g++ -std=c++11 -c Main.cpp Vecteur.cpp Objet.cpp CorpsStellaire.cpp Vaisseau.cpp Data.cpp Input.cpp PageSetting.cpp Text.cpp
g++ -std=c++11 Main.o Objet.o Vecteur.o CorpsStellaire.o Vaisseau.o Data.o Input.o PageSetting.o Text.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
#rm Main.o Objet.o Vecteur.o
./sfml-app
cd ..
python3 display.py
