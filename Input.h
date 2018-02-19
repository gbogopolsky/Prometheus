#ifndef Input_h
#define Input_h
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Text.h"

class Input : public Text {
public:
  Input ();
  Input (sf::RectangleShape INPUT_ZONE, string INPUT, Text TEXT);

  sf::RectangleShape input_zone ();
  string input ();
  Text input_text();
  bool focus_zone ();


  void set_input (string ipt);
  void input_zone (sf::Vector2f size, Vecteur position);

protected:
  sf::RectangleShape input_zone_;
  string input_;
  Text text_;
  bool focus_zone_;
};

#endif
