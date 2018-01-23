#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>

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
  Vaisseau Prometheus(50., 50., 50., 50., Vecteur(), Vecteur(), Vecteur (), 1.,1.);
  CorpsStellaire Planete(9.3, 200000., Vecteur(), Vecteur(), Vecteur(110,250), 300000.);
  CorpsStellaire Satellite(9.3, 10000., Vecteur(), Vecteur(), Vecteur(400,500), 3000.);

  //création d'un fichier de sortie des données et d'un compteur d'itérations
  std::ofstream outfile;

  //temps d'une boucle (fps)
  sf::Time time = sf::milliseconds(10);

  //Variable de RK4
  double h = 0.01;

  // création de la fenêtre
  window.create(sf::VideoMode(800, 600), "My window");

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
    std::cout << Prometheus.acceleration_().x_() << std::endl;
    std::cout << Prometheus.acceleration_().y_() << std::endl;
    Prometheus.RK4(h, Planete);

    //Positionnement
    Ship.setPosition(Prometheus.position_().x_(), Prometheus.position_().y_());
    Mars.setPosition(Planete.position_().x_(), Planete.position_().y_());
    Lune.setPosition(Satellite.position_().x_(), Satellite.position_().y_());

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
