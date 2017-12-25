#include <iostream>
#include "Vecteur.h"

Vecteur::Vecteur(): x(0.) , y(0.) {};
Vecteur::Vecteur(double x_, double y_): x(x_), y(y_) {};
Vecteur::Vecteur(const Vecteur & vect): x(vect.x), y(vect.y) {};

double Vecteur::get_x() const {
  return x;
}

double Vecteur::get_y() const {
  return y;
}

Vecteur & Vecteur::operator += (const Vecteur & vecteur_) {
  x += vecteur_.get_x();
  y += vecteur_.get_y();
  return *this;
}

Vecteur & Vecteur::operator -= (const Vecteur & vecteur_) {
  x -= vecteur_.get_x();
  y -= vecteur_.get_y();
  return *this;
}

Vecteur & Vecteur::operator = (const Vecteur & vecteur_) {
  if (&vecteur_ != this) {
    x = vecteur_.get_x();
    y = vecteur_.get_y();
  }
  return *this;
}

Vecteur operator + (const Vecteur & Vecteur1, const Vecteur & Vecteur2) {
  return Vecteur(Vecteur1.get_x() + Vecteur2.get_x(), Vecteur1.get_y() + Vecteur2.get_y());
}

Vecteur operator - (const Vecteur & Vecteur1, const Vecteur & Vecteur2) {
  return Vecteur(Vecteur1.get_x() - Vecteur2.get_x(), Vecteur1.get_y() - Vecteur2.get_y());
}

Vecteur operator * (const double dt_, const Vecteur & vecteur_) {
  return Vecteur(dt_*vecteur_.get_x(), dt_*vecteur_.get_y());
}

void affiche_x (Vecteur vecteur_) {
  std::cout << vecteur_.get_x() << std::endl;
}

void affiche_y (Vecteur vecteur_) {
  std::cout << vecteur_.get_y() << std::endl;
}
