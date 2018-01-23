#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Vaisseau.h"
#include "Objet.h"

Vaisseau::Vaisseau () :
  Objet (),
  prop_arriere (20.),
  prop_avant (5.),
  prop_lat (2.),
  prop_rot (2.) {}

Vaisseau::Vaisseau (const double prop_arriere_, const double prop_avant_, const double prop_lat_, const double prop_rot_, const Vecteur acceleration_, const Vecteur vitesse_, const Vecteur position_, const double masse_) :
  Objet (acceleration_, vitesse_, position_, masse_),
  prop_arriere (prop_arriere_),
  prop_avant (prop_avant_),
  prop_lat (prop_lat_),
  prop_rot (prop_rot_) {}

void Vaisseau::Input () {
  acceleration = Vecteur(0.,0.);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    acceleration += Vecteur(prop_lat, 0.);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    acceleration -= Vecteur(prop_lat,0.);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    acceleration += Vecteur(0., prop_arriere);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    acceleration -= Vecteur(0., prop_avant);
  }
}
