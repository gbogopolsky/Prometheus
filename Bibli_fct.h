#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <vector>

#include "Vecteur.h"
#include "Objet.h"
#include "Vaisseau.h"
#include "CorpsStellaire.h"

using namespace std;




random_device r;
mt19937_64  e1(r());

vector<CorpsStellaire> Generation_objet (int n, int t, int Lx, int Ly, double & R, int Rmax, int Rmin) {
  vector<CorpsStellaire> list_objet;
  double M, x, y, vx, vy;
  for (int i = 0 ; i<n ; i++) {
    uniform_int_distribution<int> uniform_dist_R(Rmin, Rmax);
    uniform_int_distribution<int> uniform_dist_Lx(R, Lx - R);
    uniform_int_distribution<int> uniform_dist_Ly(R, Ly - R);
    uniform_int_distribution<int> uniform_dist_t(1,t);
    R = uniform_dist_R(e1);
    M = 6e14*sqrt(R);
    x = uniform_dist_Lx(e1);
    y = uniform_dist_Ly(e1);

    //Pour le moement, les vitesses initials des Objets seront null.
    vx = 0;
    vy = 0;
    Vecteur position(x,y);
    Vecteur vitesse(vx,vy);
    CorpsStellaire Corp(R,vitesse,position,M);
    list_objet.push_back(Corp);
  };
  return list_objet;
}





void Bord_Map (Vaisseau Prometheus, std::vector<CorpsStellaire> list_objet, std::vector<sf::CircleShape> Corps, int n, int Lx, int Ly, double & R, int Rmax, int Rmin) {
  if(Prometheus.position_().x_() < 0.) {
    Vecteur Vect_(Lx,Prometheus.position_().y_());
    Prometheus.set_position(Vect_);
    list_objet.clear();
    Corps.clear();
    //list_objet = Generation_objet (n, Lx, Ly, R, Rmax, Rmin);
    unsigned int j = list_objet.size();
    for (unsigned int i =  0 ; i<j ; i++) {
      sf::CircleShape Corp(R);
      Corp.setPosition(list_objet[i].position_().x_() - list_objet[i].rayon_(),list_objet[i].position_().y_() - list_objet[i].rayon_());
      Corps.push_back(Corp);
    };
  };
  if(Prometheus.position_().x_() > Lx) {
    Vecteur Vect_(0.,Prometheus.position_().y_());
    Prometheus.set_position(Vect_);
    list_objet.clear();
    Corps.clear();
    //list_objet = Generation_objet (n, Lx, Ly, R, Rmax, Rmin);
    unsigned int j = list_objet.size();
    for (unsigned int i =  0 ; i<j ; i++) {
      sf::CircleShape Corp(R);
      //std::cout << list_objet[i].position_().x_() << std::endl;
      Corp.setPosition(list_objet[i].position_().x_() - list_objet[i].rayon_(),list_objet[i].position_().y_() - list_objet[i].rayon_());
      Corps.push_back(Corp);
    };
  };
  if(Prometheus.position_().y_() < 0.) {
    Vecteur Vect_(Prometheus.position_().x_(),Ly);
    Prometheus.set_position(Vect_);
    list_objet.clear();
    Corps.clear();
    //list_objet = Generation_objet (n, Lx, Ly, R, Rmax, Rmin);
    unsigned int j = list_objet.size();
    for (unsigned int i =  0 ; i<j ; i++) {
      sf::CircleShape Corp(R);
      Corp.setPosition(list_objet[i].position_().x_() - list_objet[i].rayon_(),list_objet[i].position_().y_() - list_objet[i].rayon_());
      Corps.push_back(Corp);
    };
  };
  if(Prometheus.position_().y_() > Ly) {
    Vecteur Vect_(Prometheus.position_().x_(),0.);
    Prometheus.set_position(Vect_);
    list_objet.clear();
    Corps.clear();
    //list_objet = Generation_objet (n, Lx, Ly, R, Rmax, Rmin);
    unsigned int j = list_objet.size();
    for (unsigned int i =  0 ; i<j ; i++) {
      sf::CircleShape Corp(R);
      Corp.setPosition(list_objet[i].position_().x_() - list_objet[i].rayon_(),list_objet[i].position_().y_() - list_objet[i].rayon_());
      Corps.push_back(Corp);
    };
  };
}

void Repositionnement (Vaisseau Prometheus, sf::ConvexShape Ship, Vecteur position_initial) {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
    Vecteur Vect_(0.,0.);
    Prometheus.set_position(position_initial);
    Prometheus.set_vitesse(Vect_);
    Prometheus.set_rotation(Vect_);
    Ship.setPosition(position_initial.x_(), position_initial.y_());
  };
}
