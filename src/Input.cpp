#include "Input.h"

Input::Input () :
  input_zone_(),
  input_(),
  text_(),
  focus_zone_(false)
  {}

Input::Input (sf::RectangleShape INPUT_ZONE, string INPUT, Text TEXT) :
  input_zone_(INPUT_ZONE),
  input_(INPUT),
  text_(TEXT),
  focus_zone_(false)
  {}

sf::RectangleShape Input::input_zone () {
  return(input_zone_);
}

string Input::input () {
  return (input_);
}

Text Input::input_text () {
  return (text_);
}

bool Input::focus_zone () {
  return (focus_zone_);
}

void Input::set_input (string ipt) {
  input_ = ipt;
}

void Input::input_zone (sf::Vector2f size, Vecteur position) {
  input_zone_.setSize(size);
  input_zone_.setPosition(position.x_(), position.y_());
  input_zone_.setFillColor(sf::Color::Yellow);
}
