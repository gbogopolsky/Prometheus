#ifndef Vecteur_h
#define Vecteur_h

class Vecteur {
public:
  Vecteur();
  Vecteur(double x_, double y_);

  double x_() const;
  double y_() const;

  Vecteur & operator += (const Vecteur & vecteur_);
  Vecteur & operator -= (const Vecteur & vecteur_);
  Vecteur & operator = (const Vecteur & vecteur_);

  friend Vecteur operator + (const Vecteur & Vecteur1, const Vecteur & Vecteur2);
  friend Vecteur operator - (const Vecteur & Vecteur1, const Vecteur & Vecteur2);
  friend Vecteur operator * (const double dt_, const Vecteur & vecteur_);

  void affiche_x (Vecteur vecteur_) ;
  void affiche_y (Vecteur vecteur_) ;

private:
  double x;
  double y;

};

#endif