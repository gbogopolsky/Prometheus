#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "CorpsStellaire.h"
#include "Objet.h"

CorpsStellaire::CorpsStellaire () :
  Objet (),
  const_gravitationnelle (9.88),
  rayon (100.) {}

CorpsStellaire::CorpsStellaire (const double const_gravitationnelle_, const double rayon_, const Vecteur acceleration_, const Vecteur vitesse_, const Vecteur position_, const double masse_) :
  Objet (acceleration_, vitesse_, position_, masse_),
  const_gravitationnelle (const_gravitationnelle_),
  rayon (rayon_) {}

double CorpsStellaire::const_gravitationnelle_ () const {
  return const_gravitationnelle;
}
