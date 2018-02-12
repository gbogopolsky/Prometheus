#ifndef Data_h
#define Data_h
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Vecteur.h"
#include "Objet.h"
#include "Vaisseau.h"
#include "CorpsStellaire.h"

using namespace std;

class Data {

public:

  Data ();
  Data (const int N,
        const int RMAX,
        const int RMIN,
        const int LX,
        const int LY,
        const double PROPULSION_AR,
        const double PROPULSION_AV,
        const double PROPULSION_LAT,
        const double PROPULSION_ROT,
        const double MASSE
        );

  void loading_font (string nom_font);
  void text_GO ();
  void setting ();
  void corpsstellaire_generation (CorpsStellaire & CorpsStellaire_, sf::CircleShape & corps_);
  void mapping ();
  bool uncovering_test ();
  void Texturage ();
  void ship_deplacement (bool & test);
  void planete_deplacement (bool & test, Vecteur & Diff_de_ref);


  int n ();
  //int t () const;
  //double R () const;
  //double M () const;
  //int Rmax () const;
  //int Rmin () const;
  int Lx ();
  int Ly ();
  //double h () const;
  //double Propulsion_Ar () const;
  //double Propulsion_Av () const;
  //double Propulsion_Lat () const;
  //double Propulsion_Rot () const;
  //double Masse () const;
  //int Largeur () const;
  //int Longueur () const;
  //Vecteur position_initial () const;
  //sf::Texture texture_vaisseau () const;
  sf::RectangleShape Ship ();
  Vaisseau Prometheus();
  vector<CorpsStellaire> list_objet ();
  vector<sf::CircleShape> corps ();
  //sf::Font font () const;
  //sf::Font font_name () const:
  //sf::Font font_txt () const;
  sf::Text game_over ();
  sf::Text game_name ();
  sf::Text params ();


private:
  //Nombre d'objets
  int n_;
  //Nombre de texture de planètes differentes
  int t_;
  //Rayon d'un CorpsStellaire
  double R_;
  //Masse d'un CorpsStellaire
  double M_;
  //Rayon maximum d'un CorpsStellaire
  int Rmax_;
  //Rayon minimum d'un CorpsStellaire
  int Rmin_;
  //Taille de la fenêtre selon x
  int Lx_;
  //Taille de la fenêtre seon y
  int Ly_;
  //Paramètrage RK4
  double h_;
  //Propulsion arrière d'un Vaisseau
  double Propulsion_Ar_;
  //Propulsion avant d'un Vaisseau
  double Propulsion_Av_;
  //Propulsion laterale d'un Vaisseau
  double Propulsion_Lat_;
  //Propulsion de rotation d'un Vaisseau
  double Propulsion_Rot_;
  //Masse d'un Vaisseau
  double Masse_;
  //Largeur d'un Vaisseau
  int Largeur_;
  //Longueur d'un Vaisseau
  int Longueur_;
  //Position initial du Vaisseau
  Vecteur position_initial_;
  //Texture du vaisseau
  sf::Texture texture_vaisseau_;
  //Forme du vaisseau
  sf::RectangleShape Ship_;
  //vaisseau
  Vaisseau Prometheus_;
  //Liste de CorpsStellaire (physique)
  vector<CorpsStellaire> list_objet_;
  //Liste de CorpsStellaire (affichage)
  vector<sf::CircleShape> corps_;
  //Police game over
  sf::Font font_;
  //Police nom du jeu
  sf::Font font_name_;
  //Police texte du jeu
  sf::Font font_txt_;
  //Texte game over
  sf::Text game_over_;
  //Texte nom du jeu
  sf::Text game_name_;
  //Texte du jeu
  sf::Text params_;

};

#endif
