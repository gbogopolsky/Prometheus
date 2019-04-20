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

void PageSetting::setting_1 (int mode) {
  texts_[0].loading (1,"PROMETHEUS"   , "PROMETHEUS - PROJECT"                                                     ,100, Vecteur(120 , 40));
  texts_[1].loading (1,"FORCED SQUARE", "Vous pourrez ici regler les parametres du jeu pour l'instant accessibles.", 50, Vecteur(80  ,220));
  texts_[2].loading (1,"FORCED SQUARE", "Parametres globales :"                                                    , 40, Vecteur(80  ,340));
  texts_[3].loading (1,"FORCED SQUARE", "Nombre de planetes ="                                                     , 30, Vecteur(80  ,410));
  texts_[4].loading (1,"FORCED SQUARE", "Rayon maximal d'une planete ="                                            , 30, Vecteur(80  ,450));
  texts_[5].loading (1,"FORCED SQUARE", "Rayon minimal d'une planete ="                                            , 30, Vecteur(80  ,510));
  texts_[6].loading (1,"FORCED SQUARE", "Parametres du vaisseau :"                                                 , 40, Vecteur(80  ,610));
  texts_[7].loading (1,"FORCED SQUARE", "Propulsion avant ="                                                       , 30, Vecteur(80  ,710));
  texts_[8].loading (1,"FORCED SQUARE", "Propulsion arriere ="                                                     , 30, Vecteur(80  ,760));
  texts_[9].loading (1,"FORCED SQUARE", "Propulsion laterales ="                                                   , 30, Vecteur(80  ,810));
  texts_[10].loading(1,"FORCED SQUARE", "Propulsion de rotation ="                                                 , 30, Vecteur(80  ,850));
  texts_[11].loading(1,"FORCED SQUARE", "Masse du vaisseau ="                                                      , 30, Vecteur(80  ,910));
  texts_[12].loading(1,"good times rg", "Commandes du jeu :"                                                       , 40, Vecteur(900 ,340));
  texts_[13].loading(1,"good times rg", "Les commandes de pilotage du vaisseau ci-contre"                          , 20, Vecteur(1100,455));
  texts_[14].loading(1,"good times rg", "correspondent a l'acceleration que l'on lui"                              , 20, Vecteur(1100,485));
  texts_[15].loading(1,"good times rg", "lui donne dans son referentiel."                                          , 20, Vecteur(1100,515));
  texts_[16].loading(1,"good times rg", "Permet de remettre le vaisseau a sa position"                             , 20, Vecteur(1100,615));
  texts_[17].loading(1,"good times rg", "d'origine."                                                               , 20, Vecteur(1100,645));
  texts_[18].loading(1,"good times rg","Lance le jeu."                                                            , 20, Vecteur(1100,740));
  texts_[19].loading(1,"good times rg", "Permet de selectionner le mode de jeu :"                                  , 20, Vecteur(1100,820));
  texts_[20].loading(1,"good times rg", "F1 etre dans le referentiel des planetes."                                , 15, Vecteur(1100,860));
  texts_[21].loading(1,"good times rg", "F1 etre dans le referentiel du vaisseau."                                 , 15, Vecteur(1100,880));

  input_zones_[0].input_zone (sf::Vector2f(310, 40), Vecteur (370 , 410));
  input_zones_[1].input_zone (sf::Vector2f(200, 40), Vecteur (480 , 460));
  input_zones_[2].input_zone (sf::Vector2f(210, 40), Vecteur (470 , 510));
  input_zones_[3].input_zone (sf::Vector2f(345, 40), Vecteur (335 , 710));
  input_zones_[4].input_zone (sf::Vector2f(330, 40), Vecteur (350 , 760));
  input_zones_[5].input_zone (sf::Vector2f(310, 40), Vecteur (370 , 810));
  input_zones_[6].input_zone (sf::Vector2f(280, 40), Vecteur (400 , 860));
  input_zones_[7].input_zone (sf::Vector2f(320, 40), Vecteur (360 , 910));
  input_zones_[8].input_zone (sf::Vector2f(50 , 50), Vecteur (900 , 510));
  input_zones_[9].input_zone (sf::Vector2f(50 , 50), Vecteur (960 , 510));
  input_zones_[10].input_zone(sf::Vector2f(50 , 50), Vecteur (960 , 450));
  input_zones_[11].input_zone(sf::Vector2f(50 , 50), Vecteur (1020, 510));
  input_zones_[12].input_zone(sf::Vector2f(50 , 50), Vecteur (960 , 620));
  input_zones_[13].input_zone(sf::Vector2f(50 , 50), Vecteur (960 , 730));
  input_zones_[14].input_zone(sf::Vector2f(50 , 50), Vecteur (930 , 840));
  input_zones_[15].input_zone(sf::Vector2f(50 , 50), Vecteur (990 , 840));

  input_zones_[0].loading (0, "FORCED SQUARE", 30, Vecteur (550 , 410));
  input_zones_[1].loading (0, "FORCED SQUARE", 30, Vecteur (550 , 460));
  input_zones_[2].loading (0, "FORCED SQUARE", 30, Vecteur (550 , 510));
  input_zones_[3].loading (0, "FORCED SQUARE", 30, Vecteur (550 , 710));
  input_zones_[4].loading (0, "FORCED SQUARE", 30, Vecteur (550 , 760));
  input_zones_[5].loading (0, "FORCED SQUARE", 30, Vecteur (550 , 810));
  input_zones_[6].loading (0, "FORCED SQUARE", 30, Vecteur (550 , 860));
  input_zones_[7].loading (0, "FORCED SQUARE", 30, Vecteur (550 , 910));
  input_zones_[8].loading (0, "good times rg", 20, Vecteur (915 , 525));
  input_zones_[9].loading (0, "good times rg", 20, Vecteur (975 , 525));
  input_zones_[10].loading(0, "good times rg", 20, Vecteur (975 , 465));
  input_zones_[11].loading(0, "good times rg", 20, Vecteur (1035, 525));
  input_zones_[12].loading(0, "good times rg", 20, Vecteur (975 , 635));
  input_zones_[13].loading(0, "good times rg", 20, Vecteur (975 , 745));
  input_zones_[14].loading(0, "good times rg", 20, Vecteur (945 , 855));
  input_zones_[15].loading(0, "good times rg", 20, Vecteur (1005, 855));

  input_zones_[8].set_input ("Q");
  input_zones_[9].set_input ("S");
  input_zones_[10].set_input("Z");
  input_zones_[11].set_input("D");
  input_zones_[12].set_input("R");
  input_zones_[13].set_input("P");
  input_zones_[14].set_input("F1");
  input_zones_[15].set_input("F2");
  
}
