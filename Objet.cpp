#include <iostream>
#include "Vecteur.h"
#include "Objet.h"
#include <SFML/Graphics.hpp>

Objet::Objet (): position() , position_precedente() , acceleration(), vitesse(), vitesse_precedente() {}

Objet::Objet (Vecteur position_,Vecteur position_precedente_, Vecteur acceleration_, Vecteur vitesse_, Vecteur vitesse_precedente_) {
  position = position_;
  position_precedente = position_precedente_;
  acceleration = acceleration_;
  vitesse = vitesse_;
  vitesse_precedente = vitesse_precedente_;
}

void Objet::Acceleration () {
  acceleration = Vecteur();

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    acceleration += Vecteur(100.0, 0.);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    acceleration -= Vecteur(100.0, 0.);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    acceleration += Vecteur(0., 100.0);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    acceleration -= Vecteur(0., 100.0);
  }
}

void Objet::Euler(double dTime) {
  // Vecteur position_ = position;
  // Vecteur vitesse_ = vitesse;
  //std::cout << acceleration.x_() << std::endl;
  //std::cout << acceleration.y_() << std::endl;
  vitesse = vitesse + dTime*acceleration;
  position = position + dTime*vitesse + 0.5*dTime*dTime*acceleration;
  // position_precedente = position_;
  // vitesse_precedente = vitesse_;
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

double Objet::vitesse_x () const {
  return vitesse.x_();
}

double Objet::vitesse_y () const {
  return vitesse.y_();
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
