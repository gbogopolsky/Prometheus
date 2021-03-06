#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "CorpsStellaire.h"
#include "Objet.h"

CorpsStellaire::CorpsStellaire () :
  Objet (),
  rayon (100.),
  planete(80)
{}

CorpsStellaire::CorpsStellaire (const double rayon_, const Vecteur vitesse_, const Vecteur position_, const double masse_, const sf::Texture texture_, const sf::CircleShape planete_) :
  Objet (masse_, vitesse_, position_, texture_),
  rayon (rayon_),
  planete(planete_)
{}

void CorpsStellaire::set_CorpsStellaire (double & rayon_, sf::CircleShape & planete_) {
  rayon = rayon_;
  planete = planete_;
}

double CorpsStellaire::rayon_ () const {
  return rayon;
}
