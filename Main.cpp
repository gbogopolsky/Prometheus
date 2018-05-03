#include "Game.h"

sf::RenderWindow game;

int main() {

  Data Parametres(3,120,30,80,20,10,10,4,0);

  sf::Time time = sf::milliseconds(20);
  Vecteur Diff_de_ref;

  bool end = true;
  bool close = true;
  bool test = false;
  game.create(sf::VideoMode(Parametres.Lx(), Parametres.Ly()), "The Game");
  Parametres.Texturage();
  Parametres.Game_Over();
  int i = 0;

  do {

    Parametres.mapping();

    while (test == false) {
      test = Parametres.uncovering_test();
    }
  } while (Game(game, Diff_de_ref, time, Parametres, end, close));
  return 0;
  }
