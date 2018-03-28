
#include "Text.h"
#include "Vecteur.h"

Text::Text() :
  font_(),
  text_()
  {
}

Text::Text(sf::Font FONT, sf::Text TEXT) :
  font_(FONT),
  text_(TEXT)
  {
}

sf::Font Text::font() {
  return (font_);
}

sf::Text Text::text() {
  return (text_);
}

void Text::loading_font() {
  font_.loadFromFile(nom_font + ".ttf");
}

void Text::loading_text() {
  text_.setString(std::string(nom_text));
}

void Text::loading() {
  loading_font(nom_font);
  text_.setFont(font_);
  text_.setString(std::string(nom_text));
  text_.setCharacterSize(size);
  text_.setPosition(position.x_(), position.y_());
  if (c==0)
    text_.setColor(sf::Color::Red);
  else if (c==1)
    text_.setColor(sf::Color::Yellow);
  else if (c==2)
    text_.setColor(sf::Color::Black);
}
