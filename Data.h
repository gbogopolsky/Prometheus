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

//Paramètrage objets
int n = 1;
int t = 3;
double R = 10;
double M = 0;
int Rmax = 120;
int Rmin = 40;
int Lx = 1900;
int Ly = 1200;
std::vector<CorpsStellaire> list_objet(n);
std::vector<sf::CircleShape> corps(n);

//Paramètrage RK4
double h = 0.08;

//Paramètrage Vaisseau
double Propulsion_Ar = 80;
double Propulsion_Av = 20;
double Propulsion_Lat = 10;
double Propulsion_Rot = 10;
double Masse = 1;
int Largeur = 40;
int Longueur = 40;
Vecteur position_initial(1900/2, 1200/2);
sf::Texture texture_vaisseau;
sf::RectangleShape Ship(sf::Vector2f(Longueur, Largeur));
Vaisseau Prometheus(Propulsion_Ar,
                    Propulsion_Av,
                    Propulsion_Lat,
                    Propulsion_Rot,
                    Vecteur(),
                    Vecteur(),
                    Vecteur(),
                    position_initial,
                    Masse,
                    texture_vaisseau,
                    Ship
                    );

//Paramètrage texte
sf::Font font;
sf::Font font_name;
sf::Font font_txt;
sf::Text game_over;

sf::Text game_name;
sf::Text params;

//Paramètres aléatoirs
random_device r;
mt19937_64  e1(r());
