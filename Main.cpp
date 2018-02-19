#include "Data.h"
#include "PageSetting.h"

sf::RenderWindow game;
sf::RenderWindow param;

int main() {

  Data Parametres;
  PageSetting First_Page(12,8);
  First_Page.setting_1();
  vector<Text> Text_First_Page;
  vector<Input> Input_Zone_First_Page;
  vector<bool> focus_zones;
  Text_First_Page = First_Page.texts();
  Input_Zone_First_Page = First_Page.input_zones();
  Parametres.default_setting_1(Input_Zone_First_Page);
  for (int i = 0; i<First_Page.m() ; i++) {
    focus_zones.push_back(Input_Zone_First_Page[i].focus_zone());
  };

  game.create(sf::VideoMode(Parametres.Lx(), Parametres.Ly()), "The Game");
  param.create(sf::VideoMode(Parametres.Lx(), Parametres.Ly()), "Paramètres");
  sf::Time time = sf::milliseconds(20);
  bool Continue = true;

  string ipt;
  sf::Text texte = Input_Zone_First_Page[0].input_text().text();
  sf::RectangleShape champ_test;
  champ_test.setSize(sf::Vector2f(20,20));
  champ_test.setPosition(1790, 100);
  champ_test.setFillColor(sf::Color::Yellow);


  while (param.isOpen()) {

    sf::Event event;

    while (param.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        param.close();
        game.close();
      };
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        param.close();
      if (event.type == sf::Event::MouseButtonPressed) {
        for (int i = 0; i<First_Page.m(); i++) {
          int x =  Input_Zone_First_Page[i].input_zone().getPosition().x;
          int lx = Input_Zone_First_Page[i].input_zone().getSize().x;
          int y =  Input_Zone_First_Page[i].input_zone().getPosition().y;
          int ly = Input_Zone_First_Page[i].input_zone().getSize().y;
          if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= x && event.mouseButton.x <= x+lx && event.mouseButton.y >= y && event.mouseButton.y <= y+ly) {
            focus_zones[i] = true;
            for (int l = 0; l<First_Page.m(); l++) {
              if (l != i)
                focus_zones[l] = false;
            ipt = "";
            };
          };
        };
      };
      for (int i = 0; i<First_Page.m(); i++) {
        if (event.type == sf::Event::TextEntered && focus_zones[i]) {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
            focus_zones[i+1] = true;
            focus_zones[i] = false;
            i++;
            ipt = "";
          };
          if (event.text.unicode < 128) {
            cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << endl;
            ipt.append(1,static_cast<char>(event.text.unicode));
            Input_Zone_First_Page[i].set_input(ipt);
          };
        };
      };
    };
    param.display();
    param.clear();
    for (int i = 0; i<First_Page.n(); i++) {
      sf::Text text = Text_First_Page[i].text();
      param.draw(text);
    };
    for (int i = 0; i<First_Page.m(); i++) {
      sf::Text ipt_txt = Input_Zone_First_Page[i].text();
      param.draw(Input_Zone_First_Page[i].input_zone());
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        focus_zones[i] = false;
      if (focus_zones[i]) {
        param.draw(champ_test);
      };
      ipt_txt.setString(Input_Zone_First_Page[i].input());
      param.draw(ipt_txt);
    };
    param.draw(texte);
  };

  Data game_setting;
  game_setting = Parametres.cstr_setting_1(Input_Zone_First_Page);

  game_setting.mapping();
  game_setting.Texturage();
  game_setting.Game_Over();

  Vecteur Diff_de_ref;

  bool test = false;
  while (test == false)
    test = game_setting.uncovering_test();

  Continue = true;

  while (game.isOpen()) {

    sf::Event event;

    while (game.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            game.close();
    };

    if(Continue) {
      sf::Clock clock;
      vector<sf::CircleShape> Corps;
      Corps = game_setting.corps();
      vector<CorpsStellaire> Objets;
      Objets = game_setting.list_objet();
      sf::RectangleShape Ship;
      Ship = game_setting.Prometheus().ship_();
      game.display();
      game.clear();
      game.draw(Ship);
      game_setting.ship_deplacement(Continue);
      //game_setting.planete_deplacement(Continue,Diff_de_ref);
      for (int i = 0; i<game_setting.n(); i++) {
        Corps[i].setPosition(Objets[i].position_().x_() - Objets[i].rayon_() - Diff_de_ref.x_(), Objets[i].position_().y_() - Objets[i].rayon_() - Diff_de_ref.y_());
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
      game.draw(game_setting.game_over().text());
    };
  };
  return 0;
}
