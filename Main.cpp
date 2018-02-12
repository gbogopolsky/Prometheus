#include "bibli_fct.h"

sf::RenderWindow game;
sf::RenderWindow param;

int main() {

  text_GO();
  setting();
  mapping();

  bool test = false;
  while (test == false)
    test = uncovering_test();

  game.create(sf::VideoMode(Lx, Ly), "The Game");
  param.create(sf::VideoMode(Lx/2, Ly), "Paramètres");
  sf::Time time = sf::milliseconds(20);
  bool Continue = true;

  while (param.isOpen()) {

    sf::Event event;
    string parm_input;

    while (param.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            param.close();
        if (event.type == sf::Event::TextEntered) {
          if (event.text.unicode < 128) {
            cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << endl;
            parm_input.push_back(static_cast<char>(event.text.unicode));
          };
        };
    };
    params.setString(std::string(parm_input));
    cout << parm_input << endl;
    param.display();
    param.clear();
    param.draw(game_name);
    param.draw(params);

  };

  while (game.isOpen()) {

    sf::Event event;

    while (game.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            game.close();
    };

    if(Continue) {
      sf::Clock clock;
      game.display();
      game.clear();
      ship_deplacement(Continue);
      //planete_deplacement(Continue);
      game.draw(Prometheus.ship_());
      for (int i = 0; i<n; i++) {
        corps[i].setPosition(list_objet[i].position_().x_() - list_objet[i].rayon_(), list_objet[i].position_().y_() - list_objet[i].rayon_());
        corps[i].setRadius(list_objet[i].rayon_());
        sf::Texture texture = list_objet[i].texture_();
        corps[i].setTexture(& texture);
        game.draw(corps[i]);
      };
      sf::sleep(time - clock.getElapsedTime());
    }

    else {
      game.display();
      game.clear();
      game.draw(game_over);
    };
  };
  return 0;
}
