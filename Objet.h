#ifndef Objet_h
#define Objet_h
#include "Vecteur.h"

class Objet {
public:
  Objet ();
  Objet (const double const_gravitationnelle_, const double masse_, const Vecteur acceleration_, const Vecteur vitesse_, const Vecteur position_);

  Vecteur position_ () const;
  Vecteur acceleration_ () const;
  double masse_ () const;
  double const_gravitationnelle_ () const;

  double Distance (const Vecteur & Vecteur1, const Vecteur & Vecteur2);
  void RK4 (const double h, const Objet & Objet2);

protected:
  double const_gravitationnelle;
  double masse;
  Vecteur acceleration;
  Vecteur vitesse;
  Vecteur position;
};

#endif
