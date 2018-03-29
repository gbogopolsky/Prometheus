#ifndef Text_h
#define Text_h
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Vecteur.h"

using namespace std;

class Text {
public:
  Text();
  Text(sf::Font font_, sf::Text text_);

  sf::Font font ();
  sf::Text text ();

  void loading_font (string nom_font);
  void loading_text (string nom_text);
  void loading (int c, string nom_font, string nom_text, int size, Vecteur position);
  void loading (int c, string nom_font,  int size, Vecteur position);
  void loading (int c, int size, Vecteur position);


protected:
  sf::Font font_;
  sf::Text text_;
};

#endif
