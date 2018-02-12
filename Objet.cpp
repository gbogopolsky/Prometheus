#include <iostream>
#include <cmath>
#include <vector>
#include "Vecteur.h"
#include "Objet.h"


Objet::Objet () :
  masse(),
  vitesse(),
  position()
{}

Objet::Objet (const double masse_, const Vecteur vitesse_, const Vecteur position_):
  masse(masse_),
  vitesse(vitesse_),
  position(position_)
{}

Vecteur Objet::position_ () const {
  return position;
}

double Objet::masse_ () const {
  return masse;
}

void Objet::set_position (Vecteur & Vect_) {
  position = Vect_;
}

void Objet::set_vitesse (Vecteur & Vect_) {
  vitesse = Vect_;
}

double Objet::Distance (const Vecteur & Vecteur1, const Vecteur & Vecteur2) {
  return sqrt(pow(Vecteur1.y_() - Vecteur2.y_(),2) + pow((Vecteur1.x_() - Vecteur2.x_()),2));
}
