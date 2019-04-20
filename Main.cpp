#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>

#include "Vecteur.h"
#include "Objet.h"

sf::RenderWindow window;
sf::CircleShape Prometheus(15);

int main() {
  //creation du système
  Objet Vaisseau;

  //création d'un fichier de sortie des données et d'un compteur d'itérations
  std::ofstream outfile;
  outfile.open("../vaisseau.dat");

  int iterations = 0;
  //temps d'une boucle (fps)
  sf::Time time = sf::milliseconds(10);
  double dTime = 0.010;

  // création de la fenêtre
  window.create(sf::VideoMode(800, 600), "My window");
  Prometheus.setFillColor(sf::Color(100, 250, 50));

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
    // effacement de la fenêtre en noir
    window.clear();
    Vaisseau.Acceleration();

    //Vaisseau.affiche_acceleration_x(Vaisseau.acceleration_x());
    //Vaisseau.affiche_acceleration_y(Vaisseau.acceleration_y());
    outfile << iterations << " " << Vaisseau.acceleration_x() << " " << Vaisseau.acceleration_y() << " " << Vaisseau.vitesse_x() << " "  << Vaisseau.vitesse_y() << " " << Vaisseau.x_() << " " << Vaisseau.y_() << std::endl;

    Vaisseau.Euler(dTime);
    Prometheus.setPosition(Vaisseau.x_(), Vaisseau.y_());

    // c'est ici qu'on dessine tout
    window.draw(Prometheus);

    // fin de la frame courante, affichage de tout ce qu'on a dessiné
    iterations += 1;
    window.display();

    // Wait for the next frame, in order to get a constant framerate, independent from the execution time
    sf::sleep(time - clock.getElapsedTime());
  }
  outfile.close();
  return 0;
}
