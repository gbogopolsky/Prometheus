#include <iostream>
#include <cmath>
#include "Objet.h"
#include "Vecteur.h"

Objet::Objet () :
  acceleration(),
  vitesse(),
  position(),
  masse (1.0) {}

Objet::Objet (const Vecteur acceleration_, const Vecteur vitesse_, const Vecteur position_, const double masse_) :
  acceleration (acceleration_),
  vitesse (vitesse_),
  position (position_),
  masse (masse_) {}

Vecteur Objet::position_ () const {
  return position;
}

double Objet::masse_ () const {
  return masse;
}

double Objet::Distance (const Objet & Objet1, const Objet & Objet2) {
  return (sqrt( (Objet2.position_().x_() - Objet1.position_().x_()) + (Objet2.position_().y_() - Objet1.position_().y_()) ));
}

void Objet::RK4 (const double h, const Objet & Objet1, const Objet & Objet2) {
  Vecteur k1, k2, k3;
  k1 = acceleration / Objet1.masse_() - Objet2.const_gravitationnelle_() * Objet2.masse_() / pow(Distance(Objet1, Objet2), 3) * (Objet2.position_() - Objet1.position_());
  k2 = acceleration / Objet1.masse_() - Objet2.const_gravitationnelle_() * Objet2.masse_() / pow(Distance(Objet1, Objet2), 3) * (Objet2.position_() - Objet1.position_());
  k3 = acceleration / Objet1.masse_() - Objet2.const_gravitationnelle_() * Objet2.masse_() / pow(Distance(Objet1, Objet2), 3) * (Objet2.position_() - Objet1.position_() - h * h / 4 * k1);
  Objet1.position_() += h * h / 6 * (k1 + k2 + k3);
}
