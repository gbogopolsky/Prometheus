#ifndef CorpsStellaire_h
#define CorpsStellaire_h
#include "Vecteur.h"
#include "Objet.h"

class CorpsStellaire : public Objet {
public:
  CorpsStellaire ();
  CorpsStellaire (const double const_gravitationnelle_, const double rayon_, const Vecteur acceleration_, const Vecteur vitesse_, const Vecteur position_, const double masse_);

  double const_gravitationnelle_ () const;

private:
  double const_gravitationnelle;
  double rayon;
};

#endif
