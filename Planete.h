#ifndef Planete_h
#define Plenete_h
#include "Vecteur.h"

class Planete {
public:
  Planete ();
  Planete (double rayon_, double masse_, double cst_gravitationnelle_, Vecteur position);
  double rayon_ () const;
  double masse_ () const;
  double cst_gravitationnelle_ () const;
private:
  double rayon;
  double masse;
  double cst_gravitationnelle;
  Vecteur position;
};

#endif
