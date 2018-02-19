#include "PageSetting.h"

using namespace std;

PageSetting::PageSetting () :
  n_(8),
  texts_(8),
  input_zones_(5)
  {}

PageSetting::PageSetting (int N) :
  n_(N),
  texts_(N),
  input_zones_(N)
  {}

PageSetting::PageSetting (int N, int M) :
  n_(N),
  texts_(N),
  input_zones_(M)
  {}

PageSetting::PageSetting (int N, vector<Text> TEXTS, vector<Input> INPUT_ZONES) :
  n_(N),
  texts_(TEXTS),
  input_zones_(INPUT_ZONES)
  {}

int PageSetting::n () {
  return (n_);
}

int PageSetting::m () {
  return (input_zones_.size());
}

vector<Text> PageSetting::texts () {
  return (texts_);
}
vector<Input> PageSetting::input_zones () {
  return (input_zones_);
}

void Initial_input () {

}

void PageSetting::setting_1 () {
  texts_[0].loading (1,"cubic"        , "PROMETHEUS"                                                               ,100, Vecteur(520, 40));
  texts_[1].loading (1,"FORCED SQUARE", "Vous pourrez ici regler les parametres du jeu pour l'instant accessibles.", 40, Vecteur(80 ,220));
  texts_[2].loading (1,"FORCED SQUARE", "Parametres globales :"                                                    , 30, Vecteur(80 ,300));
  texts_[3].loading (1,"FORCED SQUARE", "Nombre de planetes ="                                                     , 30, Vecteur(80 ,370));
  texts_[4].loading (1,"FORCED SQUARE", "Rayon maximal d'une planete ="                                            , 30, Vecteur(80 ,420));
  texts_[5].loading (1,"FORCED SQUARE", "Rayon minimal d'une planete ="                                            , 30, Vecteur(80 ,470));
  texts_[6].loading (1,"FORCED SQUARE", "Parametres du vaisseau :"                                                 , 40, Vecteur(80 ,570));
  texts_[7].loading (1,"FORCED SQUARE", "Propulsion avant ="                                                       , 30, Vecteur(80 ,670));
  texts_[8].loading (1,"FORCED SQUARE", "Propulsion arriere ="                                                     , 30, Vecteur(80 ,720));
  texts_[9].loading (1,"FORCED SQUARE", "Propulsion laterales ="                                                   , 30, Vecteur(80 ,770));
  texts_[10].loading(1,"FORCED SQUARE", "Propulsion de rotation ="                                                 , 30, Vecteur(80 ,820));
  texts_[11].loading(1,"FORCED SQUARE", "Masse du vaisseau ="                                                      , 30, Vecteur(80 ,870));

  input_zones_[0].input_zone(sf::Vector2f(310, 40), Vecteur (370, 370));
  input_zones_[1].input_zone(sf::Vector2f(200, 40), Vecteur (480, 420));
  input_zones_[2].input_zone(sf::Vector2f(210, 40), Vecteur (470, 470));
  input_zones_[3].input_zone(sf::Vector2f(345, 40), Vecteur (335, 670));
  input_zones_[4].input_zone(sf::Vector2f(330, 40), Vecteur (350, 720));
  input_zones_[5].input_zone(sf::Vector2f(310, 40), Vecteur (370, 770));
  input_zones_[6].input_zone(sf::Vector2f(280, 40), Vecteur (400, 820));
  input_zones_[7].input_zone(sf::Vector2f(320, 40), Vecteur (360, 870));

  input_zones_[0].loading(0, "FORCED SQUARE", 30, Vecteur (600, 370));
  input_zones_[1].loading(0, "FORCED SQUARE", 30, Vecteur (600, 420));
  input_zones_[2].loading(0, "FORCED SQUARE", 30, Vecteur (600, 470));
  input_zones_[3].loading(0, "FORCED SQUARE", 30, Vecteur (600, 670));
  input_zones_[4].loading(0, "FORCED SQUARE", 30, Vecteur (600, 720));
  input_zones_[5].loading(0, "FORCED SQUARE", 30, Vecteur (600, 770));
  input_zones_[6].loading(0, "FORCED SQUARE", 30, Vecteur (600, 820));
  input_zones_[7].loading(0, "FORCED SQUARE", 30, Vecteur (600, 870));
}
