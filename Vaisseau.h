#ifndef Vaisseau_h
#define Vaisseau_h
#include "Vecteur.h"
#include "Objet.h"

class Vaisseau : public Objet {
public:
  Vaisseau ();
  Vaisseau (const double prop_arriere_, const double prop_avant, const double prop_lat_, const double prop_rot_, const Vecteur acceleration_, const Vecteur vitesse_, const Vecteur position_, const double masse_, const double const_gravitationnelle_);
  void Input ();
  //void Repartition ();

private:
  double prop_arriere;
  double prop_avant;
  double prop_lat;
  double prop_rot;
  //shape du vaisseau;
  //Coque (barre de vie);
  //shield ?;

};

#endif