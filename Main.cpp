#include "Game.h"

sf::RenderWindow game;
sf::RenderWindow param;

int main() {

  Data Parametres(3,120,30,80,20,10,10,4,0);

  sf::Time time = sf::milliseconds(20);
  Vecteur Diff_de_ref;

  bool end = true;
  bool close = true;

  do {
    game.create(sf::VideoMode(Parametres.Lx(), Parametres.Ly()), "The Game");
    param.create(sf::VideoMode(Parametres.Lx(), Parametres.Ly()), "Paramètres");
    Front_Page (param, game, Diff_de_ref, Parametres, close);
  } while (Game(game, param, Diff_de_ref, time, Parametres, end, close));
  return 0;
  }
