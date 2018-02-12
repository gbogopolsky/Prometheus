#define CST_G 6.67408e-11
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Vecteur.h"
#include "Vaisseau.h"
#include "Objet.h"
#include "CorpsStellaire.h"

Vaisseau::Vaisseau () :
  Objet (),
  prop_arriere (20.),
  prop_avant (5.),
  prop_lat (2.),
  prop_rot (2.),
  rotation (),
  propulsion ()
{}

Vaisseau::Vaisseau (const double prop_arriere_, const double prop_avant_, const double prop_lat_, const double prop_rot_, const Vecteur rotation_, const Vecteur propulsion_, const Vecteur vitesse_, const Vecteur position_, const double masse_) :
  Objet (masse_, vitesse_, position_),
  prop_arriere (prop_arriere_),
  prop_avant (prop_avant_),
  prop_lat (prop_lat_),
  prop_rot (prop_rot_),
  rotation (rotation_),
  propulsion(propulsion_)
{}

void Vaisseau::Input_rot () {
  rot = 0.;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
    rot += prop_rot;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    rot -= prop_rot;
  }
}
void Vaisseau::Input_prop () {
  propulsion = Vecteur();
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
    propulsion += Vecteur (prop_avant * cos(rotation.x_() * 2 * M_PI / 360), prop_avant * sin(rotation.x_() * 2 * M_PI / 360));
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    propulsion -= Vecteur (prop_avant * cos(rotation.x_() * 2 * M_PI / 360), prop_avant * sin(rotation.x_() * 2 * M_PI / 360));
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
    propulsion += Vecteur (prop_lat * sin(rotation.x_() * 2 * M_PI / 360), - prop_lat * cos(rotation.x_() * 2 * M_PI / 360));
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    propulsion += Vecteur ( - prop_lat * sin(rotation.x_() * 2 * M_PI / 360), prop_lat * cos(rotation.x_() * 2 * M_PI / 360));
  }
}

Vecteur Vaisseau::rotation_ () const {
  return rotation;
}

void Vaisseau::set_rotation (Vecteur & Vect_) {
  rotation = Vect_;
}

void Vaisseau::RK4 (const double h, std::vector<CorpsStellaire> const & list_objet) {
  Vecteur k1, k2, k3, k4;
  unsigned int j = list_objet.size();
  k1 = k2 = k3 = k4 = propulsion / masse;
  for (unsigned int i = 0; i<j; i++){
    //std::cout<<i<<std::endl;
    k1 += CST_G * list_objet[i].masse_() / pow(Distance(list_objet[i].position_(),position), 3) * (list_objet[i].position_() - position);
    k2 += CST_G * list_objet[i].masse_() / pow(Distance(list_objet[i].position_(),position + h / 2 * vitesse), 3) * (list_objet[i].position_() - position - h / 2 * vitesse);
  };
  for (unsigned int i = 0; i<j; i++){
    //std::cout<<i<<std::endl;
    k3 += CST_G * list_objet[i].masse_() / pow(Distance(list_objet[i].position_(),(position + h / 2 * vitesse + h * h / 4 * k1)), 3) * (list_objet[i].position_() - position - h / 2 * vitesse - h * h / 4 * k1);
    k4 += CST_G * list_objet[i].masse_() / pow(Distance(list_objet[i].position_(),(position + h * vitesse + h * h / 2 * k2)), 3) * (list_objet[i].position_() - position - h * vitesse - h * h / 2 * k2);
  };
  position += h * vitesse + h * h / 6 * (k1 + k2 + k3);
  vitesse += h / 6 * (k1 + k2 + k3 + k4);
}

void Vaisseau::RK4_rotation (const double h) {
  double k1, k2, k3, k4;
  k1 = k2 = k3 = k4 = rot / masse;
  rotation.set_x(rotation.x_() + h * rotation.y_() + h * h / 6 * (k1 + k2 + k3));
  rotation.set_y(rotation.y_() + h / 6 * (k1 + k2 + k3 + k4));
}
