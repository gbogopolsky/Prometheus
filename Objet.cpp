#include <iostream>
#include "Vecteur.h"
#include "Objet.h"
#include <SFML/Graphics.hpp>

Objet::Objet (): position() , position_precedente() , acceleration () {};

Objet::Objet (const Vecteur position_, const Vecteur position_precedente_, const Vecteur acceleration_) {
  position = position_;
  position_precedente = position_precedente_;
  acceleration = acceleration_;
}

void Objet::Acceleration () {
  acceleration = Vecteur(0.,0.);
  Vecteur input;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    input = Vecteur(0.1,0.);
    acceleration += input;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    input = Vecteur(0.1,0.);
    acceleration -= input;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    input = Vecteur(0.,0.1);
    acceleration += input;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    input = Vecteur(0.,0.1);
    acceleration -= input;
  }
}

void Objet::Eulerposition() {
  Vecteur position_;
  position_ = position;
  //std::cout << acceleration.x_() << std::endl;
  //std::cout << acceleration.y_() << std::endl;
  position = 0.5*0.5*acceleration + 2*position - position_precedente;
  position_precedente = position_;
}

Vecteur Objet::position_() const {
  return (position);
}

double Objet::x_ () const {
  return (position.x_());
}

double Objet::y_ () const {
  return (position.y_());
}

double Objet::acceleration_x () const {
  return acceleration.x_();
}

double Objet::acceleration_y () const {
  return acceleration.y_();
}

void Objet::affiche_acceleration_x (double x) {
  std::cout << x << std::endl;
}

void Objet::affiche_acceleration_y (double y) {
  std::cout << y << std::endl;
}
