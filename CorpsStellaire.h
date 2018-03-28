#ifndef _CORPSSTELLAIRE_H
#define _CORPSSTELLAIRE_H


#include "Objet.h"

class Vecteur;

class CorpsStellaire : public Objet {
  public:
    CorpsStellaire();

    CorpsStellaire(const double rayon_, const Vecteur vitesse_, const Vecteur position_, const double masse_, const sf::Texture texture_, const sf::CircleShape planete_);

    void set_CorpsStellaire(double & rayon_, sf::CircleShape & planete_);

    double rayon_() const;


  private:
    double rayon;

    sf::CircleShape planete;

};
#endif
