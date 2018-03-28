#ifndef _TEXT_H
#define _TEXT_H


#include <string>
using namespace std;

class Vecteur;

class Text {
  public:
    Text();

    Text(sf::Font FONT, sf::Text TEXT);

    sf::Font font();

    sf::Text text();

    void loading_font(string nom_font);

    void loading_text(string nom_text);

    void loading(int c, string nom_font, string nom_text, int size, Vecteur position);


  protected:
    // void loading (int c, string nom_font,  int size, Vecteur position);
    // void loading (int c, int size, Vecteur position);

    sf::Font font_;

    sf::Text text_;

};
#endif
