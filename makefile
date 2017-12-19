#PARTIE A MODIFIER : Liste des fichiers .cpp (et uniquement les .cpp) a compiler
SOURCES=Main.cpp Clock.cpp Objet.cpp Vecteur.cpp
#FIN DE LA PARTIE A MODIFIER

# Nom du compilateur
CXX=g++
# Arguments pour l'etape d'édition de liens : all warnings & c++11 standart
LDFLAGS=-Wall -std=c++11
# Arguments pour l'etape de compilation : all warnings & c++11 standart
CPPFLAGS=-Wall -std=c++11 -Wextra -Wno-ignored-attributes
# Librairies : SFML
LDLIBS=-lsfml-graphics -lsfml-window - lsfml-system


# Liste des fichiers objet (*.o), générée automagiquement
OBJETS=$(subst .cpp,.o,$(SOURCES))

all: build

build: $(OBJETS)
	$(CXX) $(LDFLAGS) -o run $(OBJETS) $(LDLIBS)

depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	rm $(OBJETS)

dist-clean: clean
	rm -f *~ .depend

include .depend
