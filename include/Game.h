#include "Parametres.h"

bool Game (sf::RenderWindow & game_, sf::RenderWindow & param_, Vecteur Diff_de_ref, sf::Time time, Data & game_setting, bool & end, bool & close) {

  bool Continue = true;

  if (close) {
    while (game_.isOpen()) {

      sf::Event event;

      while (game_.pollEvent(event)) {
          if (event.type == sf::Event::Closed) {
              game_.close();
              end = false;
          }
      };

      if(Continue) {
        sf::Clock clock;
        vector<sf::CircleShape> Corps;
        Corps = game_setting.corps();
        vector<CorpsStellaire> Objets;
        Objets = game_setting.list_objet();
        sf::RectangleShape Ship;
        Ship = game_setting.Prometheus().ship_();
        game_.display();
        game_.clear();
        game_.draw(Ship);
        if (game_setting.Mode() == 0) {
          game_setting.ship_deplacement(Continue);
        };
        if (game_setting.Mode() == 1) {
          game_setting.planete_deplacement(Continue, Diff_de_ref);
        };
        for (int i = 0; i<game_setting.n(); i++) {
          Corps[i].setPosition(Objets[i].position_().x_() - Objets[i].rayon_() - Diff_de_ref.x_(), Objets[i].position_().y_() - Objets[i].rayon_() - Diff_de_ref.y_());
          Corps[i].setRadius(Objets[i].rayon_());
          sf::Texture texture = Objets[i].texture_();
          Corps[i].setTexture(& texture);
          game_.draw(Corps[i]);
        };
        sf::sleep(time - clock.getElapsedTime());
      }
      else {
        game_.display();
        game_.clear();
        game_.draw(game_setting.game_over().text());
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
          end = true;
          game_.close();
          param_.close();
        }
        else {
          end = false;
        };
      };
    };
  }
  else {
    end = false;
  };
  return (end);
};
