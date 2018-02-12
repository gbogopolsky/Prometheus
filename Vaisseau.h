#ifndef Vaisseau_h
#define Vaisseau_h
#include <vector>
#include "Vecteur.h"
#include "Objet.h"
#include "CorpsStellaire.h"

class Vaisseau : public Objet {
public:
  Vaisseau ();
  Vaisseau (const double prop_arriere_, const double prop_avant, const double prop_lat_, const double prop_rot_, const Vecteur rotation_, const Vecteur propulsion_, const Vecteur vitesse_, const Vecteur position_, const double masse_);

  Vecteur rotation_ () const;
  void set_rotation (Vecteur & Vect_);

  void Input_rot ();
  void Input_prop ();

  void RK4 (const double h, std::vector<CorpsStellaire> const & list_objet);
  void RK4_rotation (const double h);

private:
  double prop_arriere;
  double prop_avant;
  double prop_lat;
  double prop_rot;
  double rot;
  Vecteur rotation;
  Vecteur propulsion;
};

#endif
