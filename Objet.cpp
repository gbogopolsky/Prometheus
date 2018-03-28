
#include "Objet.h"

Objet::Objet() :
  masse(),
  vitesse(),
  position(),
  texture()
{
}

Objet::Objet(const double masse_, const Vecteur vitesse_, const Vecteur position_, const sf::Texture texture_):
  masse(masse_),
  vitesse(vitesse_),
  position(position_),
  texture(texture_)
{
}

Vecteur Objet::position_() const {
  return position;
}

double Objet::masse_() const {
  return masse;
}

sf::Texture Objet::texture_() const {
  return texture;
}

void Objet::set_position() {
  position = Vect_;
}

void Objet::set_position() {
  position.set_x(x);
  position.set_y(y);
}

void Objet::set_vitesse() {
  vitesse = Vect_;
}

void Objet::set_texture() {
  texture.loadFromFile(nom_texture + ".png");
}

void Objet::set_Objet() {
  masse = masse_;
  vitesse = vitesse_;
  position = position_;
  texture = texture_;
}

double Objet::Distance() {
  return sqrt(pow(Vecteur1.y_() - Vecteur2.y_(),2) + pow((Vecteur1.x_() - Vecteur2.x_()),2));
}

