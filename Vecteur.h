#ifndef Vecteur_h
#define Vecteur_h

class Vecteur {
public:
  Vecteur();
  Vecteur(double x_, double y_);
  Vecteur(const Vecteur & vect);

  double x_() const;
  double y_() const;
  void set_x (double x_);
  void set_y (double y_);

  Vecteur & operator += (const Vecteur & vecteur_);
  Vecteur & operator -= (const Vecteur & vecteur_);
  Vecteur & operator = (const Vecteur & vecteur_);

  friend Vecteur operator + (const Vecteur & Vecteur1, const Vecteur & Vecteur2);
  friend Vecteur operator - (const Vecteur & Vecteur1, const Vecteur & Vecteur2);
  friend Vecteur operator * (const double dt_, const Vecteur & vecteur_);
  friend Vecteur operator / (const Vecteur & vecteur_, const double dt_);

  void affiche_x (Vecteur vecteur_) ;
  void affiche_y (Vecteur vecteur_) ;

private:
  double x;
  double y;

};

#endif
