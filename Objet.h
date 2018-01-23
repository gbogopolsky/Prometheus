#ifndef Objet_h
#define Objet_h
#include "Vecteur.h"

class Objet {
public:
  Objet ();
  Objet (const Vecteur acceleration_, const Vecteur vitesse_, const Vecteur position_, const double masse_);

  Vecteur position_ () const;
  double masse_ () const;
  virtual double const_gravitationnelle_ () const;

  double Distance (const Objet & Objet1, const Objet & Objet2);
  void RK4 (const double h, const Objet & Objet1, const Objet & Objet2);

protected:
  Vecteur acceleration;
  Vecteur vitesse;
  Vecteur position;
  double masse;
};

#endif
