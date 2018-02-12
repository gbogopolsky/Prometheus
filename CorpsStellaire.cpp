#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "CorpsStellaire.h"
#include "Objet.h"

CorpsStellaire::CorpsStellaire () :
  Objet (),
  rayon (100.)
{}

CorpsStellaire::CorpsStellaire (const double rayon_, const Vecteur vitesse_, const Vecteur position_, const double masse_) :
  Objet (masse_, vitesse_, position_),
  rayon (rayon_)
{}

double CorpsStellaire::rayon_ () const {
  return rayon;
}
