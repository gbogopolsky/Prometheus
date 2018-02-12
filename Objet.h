#ifndef Objet_h
#define Objet_h
#include <vector>
#include "Vecteur.h"

class Objet {
public:
  Objet ();
  Objet (const double masse_, const Vecteur vitesse_, const Vecteur position_);

  Vecteur position_ () const;
  double masse_ () const;

  void set_position (Vecteur & Vect_);
  void set_vitesse (Vecteur & Vect_);

  double Distance (const Vecteur & Vecteur1, const Vecteur & Vecteur2);

protected:
  double masse;
  Vecteur vitesse;
  Vecteur position;
};

#endif
