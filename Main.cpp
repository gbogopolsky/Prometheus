#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Vecteur.h"
#include "Objet.h"

sf::RenderWindow window;
sf::CircleShape Prometheus(15);

int main() {
  //creation du système
  Objet Vaisseau;
  //temps d'une boucle (fps)
  sf::Time time = sf::milliseconds(60);
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

    Vaisseau.Eulerposition();
    Prometheus.move(Vaisseau.x_(), Vaisseau.y_());
    window.draw(Prometheus);

    // c'est ici qu'on dessine tout
      // fin de la frame courante, affichage de tout ce qu'on a dessiné
    window.display();
    sf::sleep(time - clock.getElapsedTime());
  }
  return 0;
}
