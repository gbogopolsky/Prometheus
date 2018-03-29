#include "Data.h"
#include "PageSetting.h"

void Front_Page (sf::RenderWindow & param_, sf::RenderWindow & game_, Vecteur Diff_de_ref, Data & Parametres, bool & close) {

  PageSetting First_Page(22,16);
  First_Page.setting_1(Parametres.Mode());
  vector<Text> Text_First_Page;
  vector<Input> Input_Zone_First_Page;
  vector<bool> focus_zones;
  Text_First_Page = First_Page.texts();
  Input_Zone_First_Page = First_Page.input_zones();
  Parametres.default_setting_1(Input_Zone_First_Page);
  for (int i = 0; i<First_Page.m() ; i++) {
    focus_zones.push_back(Input_Zone_First_Page[i].focus_zone());
  };

  string ipt;
  sf::Text texte = Input_Zone_First_Page[0].input_text().text();
  sf::RectangleShape champ_test;
  champ_test.setSize(sf::Vector2f(20,20));
  champ_test.setPosition(1790, 100);
  champ_test.setFillColor(sf::Color::Yellow);

  bool test = false;

  while (param_.isOpen()) {

    sf::Event event;

    while (param_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        param_.close();
        game_.close();
        close = false;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        param_.close();
      // if (event.type == sf::Event::MouseButtonPressed) {
      //   for (int i = 0; i<First_Page.m(); i++) {
      //     int x =  Input_Zone_First_Page[i].input_zone().getPosition().x;
      //     int lx = Input_Zone_First_Page[i].input_zone().getSize().x;
      //     int y =  Input_Zone_First_Page[i].input_zone().getPosition().y;
      //     int ly = Input_Zone_First_Page[i].input_zone().getSize().y;
      //     if (event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x >= x && event.mouseButton.x <= x+lx && event.mouseButton.y >= y && event.mouseButton.y <= y+ly) {
      //       focus_zones[i] = true;
      //       for (int l = 0; l<First_Page.m(); l++) {
      //         if (l != i)
      //           focus_zones[l] = false;
      //       ipt = "";
      //       }
      //     }
      //   }
      // }
      // for (int i = 0; i<First_Page.m(); i++) {
      //   if (event.type == sf::Event::TextEntered && focus_zones[i]) {
      //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
      //       focus_zones[i+1] = true;
      //       focus_zones[i] = false;
      //       i++;
      //       ipt = "";
      //     }
      //     if (event.text.unicode < 128) {
      //       cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << endl;
      //       ipt.append(1,static_cast<char>(event.text.unicode));
      //       Input_Zone_First_Page[i].set_input(ipt);
      //     }
      //   }
      // }
    }
    Parametres.set_mode();
    param_.display();
    param_.clear();
    for (int i = 0; i<First_Page.n(); i++) {
      sf::Text text = Text_First_Page[i].text();
      param_.draw(text);
    }
    // if (Parametres.Mode() == 0) {
    //   sf::RectangleShape rect_f1 = Input_Zone_First_Page[14].input_zone();
    //   rect_f1.setOutlineThickness(4);
    //   rect_f1.setOutlineColor(sf::Color::Red);
    // }
    // else if (Parametres.Mode() == 1) {
    //   sf::RectangleShape rect_f2 = Input_Zone_First_Page[15].input_zone();
    //   rect_f2.setOutlineThickness(4);
    //   rect_f2.setOutlineColor(sf::Color::Red);
    // }
    // for (int i = 0; i<First_Page.m(); i++) {
    //   sf::Text ipt_txt = Input_Zone_First_Page[i].text();
    //   param_.draw(Input_Zone_First_Page[i].input_zone());
    //   if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    //     focus_zones[i] = false;
    //   if (focus_zones[i]) {
    //     param_.draw(champ_test);
    //   }
    //   ipt_txt.setString(Input_Zone_First_Page[i].input());
    //   param_.draw(ipt_txt);
    // }
    param_.draw(texte);
  }

  Data game_setting;
  Parametres = Parametres.cstr_setting_1(Input_Zone_First_Page);

  Parametres.mapping();
  Parametres.Texturage();
  Parametres.Game_Over();

  while (test == false) {
    test = Parametres.uncovering_test();
  }
}
