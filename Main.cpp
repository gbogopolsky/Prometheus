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
#include "Bibli_fct.h"

sf::RenderWindow window;
sf::Font font;

int main() {

  //Variable du jeu
  int n = 10;
  int t = 3;
  double R = 0;
  int Rmax = 200;
  int Rmin = 40;
  ///// Vaisseau fixe
  int Lx = 2000;
  int Ly = 2000;
  ///// Vaisseau mobile
  //int Lx = 900;
  //int Ly = 1200;

  //creation du système
  ///// Vaisseau fixe
  Vecteur position_initial(1900/2, 1200/2);
  ///// Vaisseau mobile
  //Vecteur position_initial(Lx/2, Ly/2);

  Vaisseau Prometheus(100., 100., 100., 6., Vecteur(), Vecteur(), Vecteur(), position_initial, 1.);

  //Forme du Vaisseau
  sf::RectangleShape Ship(sf::Vector2f(80, 80));
  sf::Texture texture;
  texture.loadFromFile("V1.png");
  Ship.setTexture(&texture);
  sf::Texture P1;
  P1.loadFromFile("P1.png");
  //sf::ConvexShape Ship;
  //Ship.setPointCount(6);
  // define the points
  //Ship.setPoint(0, sf::Vector2f(0, -14));
  //Ship.setPoint(1, sf::Vector2f(14, 14));
  //Ship.setPoint(2, sf::Vector2f(12, 10));
  //Ship.setPoint(3, sf::Vector2f(-12, 10));
  //Ship.setPoint(4, sf::Vector2f(-14, 14));
  //Ship.setPoint(5, sf::Vector2f(0, -14));

  //création d'un fichier de sortie des données et d'un copteur d'itérations
  std::ofstream outfile;

  ///// Vaisseau fixe
  Ship.setPosition(position_initial.x_(), position_initial.y_());

  //temps d'une boucle (fps)
  sf::Time time = sf::milliseconds(10);

  //Variable de RK4
  double h = 0.01;

  // création de la fenêtre
  ///// Vaisseau fixe
  window.create(sf::VideoMode(1900, 1200), "My window");
  ///// Vaisseau mobile
  //window.create(sf::VideoMode(Lx,Ly), "My window");

  //Game over
  sf::Text text;
  sf::Font font;
  font.loadFromFile("contrast.ttf");
  text.setFont(font);
  text.setString(std::string("GAME OVER"));
  text.setCharacterSize(100);
  text.setColor(sf::Color::Red);
  text.setPosition(100,100);


  //Couleur des elements
  //Ship.setFillColor(sf::Color(0,0,0));

  //Objet
  std::vector<CorpsStellaire> list_objet;
  //list_objet.push_back(Terre);
  list_objet = Generation_objet (n, t, Lx, Ly, R, Rmax, Rmin);
  unsigned int j = list_objet.size();
  std::vector<sf::CircleShape> Corps;
  for (unsigned int i =  0 ; i<j ; i++) {
    //std::cout << R << std::endl;
    sf::CircleShape Corp(R);
    Corp.setTexture(&P1);
    //std::cout << list_objet[i].position_().x_() << std::endl;
    Corp.setPosition(list_objet[i].position_().x_() - list_objet[i].rayon_(),list_objet[i].position_().y_() - list_objet[i].rayon_());
    Corps.push_back(Corp);
  };

  bool Continue = true;

  // on fait tourner le programme tant que la fenêtre n'a pas été fermée
  while (window.isOpen()) {

    // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
    sf::Event event;

    while (window.pollEvent(event)) {

        // fermeture de la fenêtre lorsque l'utilisateur le souhaite
        if (event.type == sf::Event::Closed)
            window.close();
    };

    if(Continue) {

      //Chronometrage
      sf::Clock clock;

      //Positionnement du vaisseau
      //Ship.setPosition(Prometheus.position_().x_(),Prometheus.position_().y_());
      Ship.setRotation(Prometheus.rotation_().x_());

      //Repositionnement
      //Repositionnement(Prometheus, Ship, position_initial);
      //Sortie de fenêtre
      Bord_Map(Prometheus, list_objet, Corps, n, Lx, Ly, R, Rmax, Rmin);

      ///// Vaisseau fixe
      Vecteur position_precedente(Prometheus.position_());

      //Calcul
      Prometheus.Input_rot();
      Prometheus.RK4_rotation(h);
      Prometheus.Input_prop();
      Prometheus.RK4(h, list_objet);
      //std::cout << Prometheus.rotation_().x_() << "               " << cos(Prometheus.rotation_().x_() * 2 * M_PI / 360) <<  std::endl;

      ///////////////////////////////
      //Vaisseau fixe
      Corps.clear();
      unsigned int j = list_objet.size();
      for (unsigned int i =  0 ; i<j ; i++) {
        Vecteur position(list_objet[i].position_() - (Prometheus.position_() - position_precedente));
        list_objet[i].set_position(position);
        sf::CircleShape Corp(R);
        Corp.setPosition(position.x_() - list_objet[i].rayon_(), position.y_() - list_objet[i].rayon_());
        Corps.push_back(Corp);
      }

      //Affichage
      window.clear();
      window.draw(Ship);
      unsigned int l = list_objet.size();
      for (unsigned int i =  0 ; i<l ; i++)
        window.draw(Corps[i]);

      //Iterations
      window.display();
      sf::sleep(time - clock.getElapsedTime());
      //std::cout << Continue << std::endl;
      unsigned int k = list_objet.size();
      for (unsigned int i = 0 ; i<k ; i++) {
        //std::cout << Prometheus.Distance(list_objet[i].position_(), Prometheus.position_()) << std::endl;
        //std::cout << list_objet[i].rayon_() << std::endl;
        if(Prometheus.Distance(list_objet[i].position_(), Prometheus.position_()) < list_objet[i].rayon_() && Continue) {
          Continue = false;
        };
      };
    }
    else {
      window.clear();
      window.draw(text);
      window.display();
    };
  };
  outfile.close();
  return 0;
}
