#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "CorpsStellaire.h"
#include "Objet.h"

CorpsStellaire::CorpsStellaire () :
  Objet (),
  rayon (100.)
{}

CorpsStellaire::CorpsStellaire (const double const_gravitationnelle_, const double rayon_, const Vecteur acceleration_, const Vecteur vitesse_, const Vecteur position_, const double masse_) :
  Objet (const_gravitationnelle_, masse_, acceleration_, vitesse_, position_),
  rayon (rayon_)
{}

double CorpsStellaire::rayon_ () const {
  return rayon;
}
