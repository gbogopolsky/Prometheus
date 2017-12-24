#ifndef Objet_h
#define Objet_h
#include "Vecteur.h"


class Objet {
public:
  Objet();
  Objet(Vecteur position_, Vecteur position_precedente_, Vecteur acceleration_);

  void Acceleration ();
  void Eulerposition ();

  Vecteur position_ () const;
  double x_ () const;
  double y_ () const;
  //Vecteur acceleration_ () const;
  double acceleration_x () const;
  double acceleration_y () const;
  
  void affiche_acceleration_x (double x);
  void affiche_acceleration_y (double y);

private:
  Vecteur position;
  Vecteur position_precedente;
  Vecteur acceleration;

};

#endif
