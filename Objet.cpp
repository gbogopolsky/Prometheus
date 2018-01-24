#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Objet.h"


Objet::Objet () :
  const_gravitationnelle(),
  masse(),
  acceleration(),
  vitesse(),
  position()
{}

Objet::Objet (const double const_gravitationnelle_, const double masse_, const Vecteur acceleration_, const Vecteur vitesse_, const Vecteur position_):
  const_gravitationnelle(const_gravitationnelle_),
  masse(masse_),
  acceleration(acceleration_),
  vitesse(vitesse_),
  position(position_)
{}

Vecteur Objet::position_ () const {
  return position;
}

Vecteur Objet::acceleration_ () const {
  return acceleration;
}

double Objet::masse_ () const {
  return masse;
}

double Objet::const_gravitationnelle_ () const {
  return const_gravitationnelle;
}

void Objet::set_position (Vecteur & Vect_) {
  position = Vect_;
}

void Objet::set_vitesse (Vecteur & Vect_) {
  vitesse = Vect_;
}

void Objet::set_acceleration (Vecteur & Vect_) {
  acceleration = Vect_;
}

double Objet::Distance (const Vecteur & Vecteur1, const Vecteur & Vecteur2) {
  return sqrt(pow(Vecteur1.x_() - Vecteur2.x_(),2) + pow((Vecteur1.y_() - Vecteur2.y_()),2));
}

void Objet::RK4_inertie (const double h) {
  position += h * vitesse + h * h / 6 * ( 3 * acceleration / masse );
  vitesse += h / 6 * ( 4 * acceleration / masse );
}

void Objet::RK4 (const double h, const Objet & Objet2) {
  Vecteur k1, k2, k3, k4;
  k1 = Objet2.const_gravitationnelle_() * Objet2.masse_() / pow(Distance(Objet2.position_(),position), 3) * (Objet2.position_() - position);
  k2 = Objet2.const_gravitationnelle_() * Objet2.masse_() / pow(Distance(Objet2.position_(),position + h / 2 * vitesse), 3) * (Objet2.position_() - position - h / 2 * vitesse);
  k3 = Objet2.const_gravitationnelle_() * Objet2.masse_() / pow(Distance(Objet2.position_(),(position + h / 2 * vitesse + h * h / 4 * k1)), 3) * (Objet2.position_() - position - h / 2 * vitesse - h * h / 4 * k1);
  k4 = Objet2.const_gravitationnelle_() * Objet2.masse_() / pow(Distance(Objet2.position_(),(position + h * vitesse + h * h / 2 * k2)), 3) * (Objet2.position_() - position - h * vitesse - h * h / 2 * k2);
  position += h * vitesse + h * h / 6 * (k1 + k2 + k3);
  vitesse += h / 6 * (k1 + k2 + k3 + k4);
}
