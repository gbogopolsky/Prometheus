
#include "Vecteur.h"

Vecteur::Vecteur(): x(0.) , y(0.) {
}

Vecteur::Vecteur(double x_, double y_): x(x_), y(y_) {
}

Vecteur::Vecteur(const Vecteur & vect): x(vect.x), y(vect.y) {
}

double Vecteur::x_() const {
  return x;
}

double Vecteur::y_() const {
  return y;
}

void Vecteur::set_x() {
  x = x_;
}

void Vecteur::set_y() {
  y = y_;
}

Vecteur Vecteur::operator +=() {
  x += vecteur_.x_();
  y += vecteur_.y_();
  return *this;
}

Vecteur Vecteur::operator -=() {
  x -= vecteur_.x_();
  y -= vecteur_.y_();
  return *this;
}

Vecteur Vecteur::operator =() {
  if (&vecteur_ != this) {
    x = vecteur_.x_();
    y = vecteur_.y_();
  }
  return *this;
}

Vecteur operator +() {
  return Vecteur(Vecteur1.x_() + Vecteur2.x_(), Vecteur1.y_() + Vecteur2.y_());
}

Vecteur operator -() {
  return Vecteur(Vecteur1.x_() - Vecteur2.x_(), Vecteur1.y_() - Vecteur2.y_());
}

Vecteur operator *() {
  return Vecteur(dt_*vecteur_.x_(), dt_*vecteur_.y_());
}

Vecteur operator /() {
  return Vecteur(vecteur_.x_()/dt_, vecteur_.y_()/dt_);
}

