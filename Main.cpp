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

sf::RenderWindow window;
sf::CircleShape Ship(15);
sf::CircleShape Mars(50);
sf::CircleShape Lune(10);

int main() {

  //creation du système
  Vaisseau Prometheus(60., 60., 60., 60., Vecteur(), Vecteur(), Vecteur (), 1.,1.);
  CorpsStellaire Planete(9.3, 50., Vecteur(), Vecteur(), Vecteur(110,400), 300000.);
  CorpsStellaire Satellite(9.3, 10., Vecteur(), Vecteur(), Vecteur(900,600), 300.);

  //Figures
  //sf::CircleShape Ship(15);
  sf::CircleShape Mars(Planete.rayon_());
  sf::CircleShape Lune(Satellite.rayon_());
  //Forme du Vaisseau
  sf::ConvexShape Ship;
  Ship.setPointCount(5);
  // define the points
  Ship.setPoint(0, sf::Vector2f(0, 0));
  Ship.setPoint(1, sf::Vector2f(40, 20));
  Ship.setPoint(2, sf::Vector2f(0, 40));
  Ship.setPoint(3, sf::Vector2f(8, 34));
  Ship.setPoint(4, sf::Vector2f(8, 6));
  //création d'un fichier de sortie des données et d'un compteur d'itérations
  std::ofstream outfile;

  //temps d'une boucle (fps)
  sf::Time time = sf::milliseconds(10);

  //Variable de RK4
  double h = 0.01;

  // création de la fenêtre
  window.create(sf::VideoMode(1900, 1200), "My window");

  //Couleur des elements
  Ship.setFillColor(sf::Color(100, 250, 50));
  Mars.setFillColor(sf::Color(250,50,100));
  Lune.setFillColor(sf::Color(250,50,100));

  // on fait tourner le programme tant que la fenêtre n'a pas été fermée
  while (window.isOpen()) {

    //Chronometrage
    sf::Clock clock;

    // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
    sf::Event event;

    while (window.pollEvent(event)) {

        // fermeture de la fenêtre lorsque l'utilisateur le souhaite
        if (event.type == sf::Event::Closed)
            window.close();
    }

    //Calcul
    Prometheus.Input();
    //std::cout << Prometheus.acceleration_().x_() << std::endl;
    //std::cout << Prometheus.acceleration_().y_() << std::endl;
    std::vector<Objet> list_objet;
    //list_objet.reserve(CorpsStellaire);
    list_objet.push_back(Planete);
    list_objet.push_back(Satellite);
    //std::cout<<list_objet.size()<<std::endl;
    Prometheus.RK4(h, list_objet);

    //Positionnement
    Mars.setPosition(Planete.position_().x_(), Planete.position_().y_());
    Lune.setPosition(Satellite.position_().x_(), Satellite.position_().y_());
    Ship.setPosition(Prometheus.position_().x_(),Prometheus.position_().y_());
    //Repositionnement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
      Vecteur Vect_(0.,0.);
      Prometheus.set_position(Vect_);
      Prometheus.set_vitesse(Vect_);
      Prometheus.set_acceleration(Vect_);
      Ship.setPosition(0.,0.);
    };

    //Affichage
    window.clear();
    window.draw(Ship);
    window.draw(Mars);
    window.draw(Lune);

    //Iterations
    window.display();
    sf::sleep(time - clock.getElapsedTime());
  }
  outfile.close();
  return 0;
}
