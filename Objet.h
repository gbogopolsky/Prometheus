#ifndef _OBJET_H
#define _OBJET_H


#include "Vecteur.h"

class Objet {
  public:
    Objet();

    Objet(const double masse_, const Vecteur vitesse_, const Vecteur position_, const sf::Texture texture_);

    Vecteur position_() const;

    double masse_() const;

    sf::Texture texture_() const;

    void set_position(Vecteur & Vect_);

    void set_position(double x, double y);

    void set_vitesse(Vecteur & Vect_);

    void set_texture(std::string nom_texture);

    void set_Objet(double & masse_, Vecteur & vitesse_, Vecteur & position_, sf::Texture & texture_);

    double Distance(const Vecteur & Vecteur1, const Vecteur & Vecteur2);


  protected:
    double masse;

    Vecteur vitesse;

    Vecteur position;

    sf::Texture texture;

};
#endif
