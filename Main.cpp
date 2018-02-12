#include "Data.h"

sf::RenderWindow game;
//sf::RenderWindow param;

int main() {

  Data Parametres;

  Parametres.text_GO();
  //Parametres.setting();
  Parametres.mapping();

  bool test = false;
  while (test == false)
    test = Parametres.uncovering_test();

  game.create(sf::VideoMode(Parametres.Lx(), Parametres.Ly()), "The Game");
  //param.create(sf::VideoMode(Parametres.Lx()/2, Parametres.Ly()), "Paramètres");
  sf::Time time = sf::milliseconds(20);
  bool Continue = true;

  //while (param.isOpen()) {
  //
  //  sf::Event event;
  //  string parm_input;
  //
  //  while (param.pollEvent(event)) {
  //      if (event.type == sf::Event::Closed)
  //          param.close();
  //      if (event.type == sf::Event::TextEntered) {
  //        if (event.text.unicode < 128) {
  //          cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << endl;
  //          parm_input.push_back(static_cast<char>(event.text.unicode));
  //        };
  //      };
  //  };
  //  params.setString(std::string(parm_input));
  //  cout << parm_input << endl;
  //  param.display();
  //  param.clear();
  //  param.draw(Parametres.game_name());
  //  param.draw(Parametres.params());
  //
  //};

  while (game.isOpen()) {

    sf::Event event;

    while (game.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            game.close();
    };

    if(Continue) {
      sf::Clock clock;
      vector<sf::CircleShape> Corps;
      Corps = Parametres.corps();
      vector<CorpsStellaire> Objets;
      Objets = Parametres.list_objet();
      sf::RectangleShape Ship;
      Ship = Parametres.Prometheus().ship_();
      game.display();
      game.clear();
      Parametres.ship_deplacement(Continue);
      //Parametres.planete_deplacement(Continue);
      game.draw(Ship);
      for (int i = 0; i<Parametres.n(); i++) {
        Corps[i].setPosition(Objets[i].position_().x_() - Objets[i].rayon_(), Objets[i].position_().y_() - Objets[i].rayon_());
        Corps[i].setRadius(Objets[i].rayon_());
        sf::Texture texture = Objets[i].texture_();
        Corps[i].setTexture(& texture);
        game.draw(Corps[i]);
      };
      sf::sleep(time - clock.getElapsedTime());
    }

    else {
      game.display();
      game.clear();
      game.draw(Parametres.game_over());
    };
  };
  return 0;
}
