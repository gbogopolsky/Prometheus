#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "Vecteur.h"
#include "Objet.h"


Objet::Objet () :
  masse(),
  vitesse(),
  position(),
  texture()
{}

Objet::Objet (const double masse_, const Vecteur vitesse_, const Vecteur position_, const sf::Texture texture_):
  masse(masse_),
  vitesse(vitesse_),
  position(position_),
  texture(texture_)
{}

void Objet::set_Objet (double & masse_, Vecteur & vitesse_, Vecteur & position_, sf::Texture & texture_) {
  masse = masse_;
  vitesse = vitesse_;
  position = position_;
  texture = texture_;
}


Vecteur Objet::position_ () const {
  return position;
}

Vecteur Objet::vitesse_ () const {
   return vitesse;
}

double Objet::masse_ () const {
  return masse;
}

sf::Texture Objet::texture_ () const {
  return texture;
}


void Objet::set_position (Vecteur & Vect_) {
  position = Vect_;
}

void Objet::set_vitesse (Vecteur & Vect_) {
  vitesse = Vect_;
}

void Objet::set_texture (std::string nom_texture) {
  texture.loadFromFile(nom_texture + ".png");
}

double Objet::Distance (const Vecteur & Vecteur1, const Vecteur & Vecteur2) {
  return sqrt(pow(Vecteur1.y_() - Vecteur2.y_(),2) + pow((Vecteur1.x_() - Vecteur2.x_()),2));
}
