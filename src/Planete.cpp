#include <iostream>
#include "Vecteur.h"
#include "Planete.h"

Planete::Planete (): rayon(), masse(), cst_gravitationnelle(), position() {}

Planete::Planete (double rayon_, double masse_, double cst_gravitationnelle_, Vecteur position_):
  rayon(rayon_),
  masse(masse_),
  cst_gravitationnelle(cst_gravitationnelle_),
  position(position_)
{}

double Planete::rayon_() const {
  return rayon;
}

double Planete::masse_() const {
  return masse;
}

double Planete::cst_gravitationnelle_() const {
  return cst_gravitationnelle;
}
