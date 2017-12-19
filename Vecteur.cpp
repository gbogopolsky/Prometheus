#include <iostream>
#include "Vecteur.h"

Vecteur::Vecteur(): x(0.) , y(0.) {};
Vecteur::Vecteur(double x_, double y_): x(x_), y(y_) {};
double Vecteur::x_ () const {
  return x;
};

double Vecteur::y_ () const {
  return y;
};

Vecteur & Vecteur::operator += (const Vecteur & vecteur_)
{
  x += vecteur_.x_();
  y += vecteur_.y_();
  return *this;
};

Vecteur & Vecteur::operator -= (const Vecteur & vecteur_)
{
  x -= vecteur_.x_();
  y -= vecteur_.y_();
  return *this;
};

Vecteur & Vecteur::operator = (const Vecteur & vecteur_)
{
  if (&vecteur_ != this)
  {
    x = vecteur_.x_();
    y = vecteur_.y_();
  };
  return *this;
};

Vecteur operator + (const Vecteur & Vecteur1, const Vecteur & Vecteur2)
{
  return Vecteur(Vecteur1.x_() + Vecteur2.x_(), Vecteur1.y_() + Vecteur2.y_());
};

Vecteur operator - (const Vecteur & Vecteur1, const Vecteur & Vecteur2)
{
  return Vecteur(Vecteur1.x_() - Vecteur2.x_(), Vecteur1.y_() - Vecteur2.y_());
};

Vecteur operator * (const double dt_, const Vecteur & vecteur_)
{
  return Vecteur(dt_*vecteur_.x_(), dt_*vecteur_.y_());
};

void affiche_x (Vecteur vecteur_) {
  std::cout << vecteur_.x_() << std::endl;
};

void affiche_y (Vecteur vecteur_) {
  std::cout << vecteur_.y_() << std::endl;
};
