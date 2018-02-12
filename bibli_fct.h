#include "Data.h"

//Paramètres aléatoirs
random_device r;
mt19937_64  e1(r());

//Data


void loading_font (string nom_font, sf::Font & font) {
  font.loadFromFile(nom_font + ".ttf");
};

void text_GO () {
  loading_font("contrast", font);
  game_over.setFont(font);
  game_over.setString(std::string("GAME OVER"));
  game_over.setCharacterSize(100);
  game_over.setColor(sf::Color::Red);
  game_over.setPosition(100,100);
};

void setting () {
  loading_font("cubic", font_name);
  game_name.setFont(font_name);
  loading_font("FORCED SQUARE", font_txt);
  params.setFont(font_txt);
  game_name.setString(std::string("PROMETHEUS"));
  game_name.setCharacterSize(100);
  game_name.setColor(sf::Color::Yellow);
  game_name.setPosition(100, 200);
  params.setCharacterSize(40);
  params.setColor(sf::Color::Yellow);
  params.setPosition(100, 400);
}

void corpsstellaire_generation (CorpsStellaire & CorpsStellaire_, sf::CircleShape & corps_, double & R, double & M) {
  double x, y, vx, vy;
  sf::Texture texture;
  uniform_int_distribution<int> uniform_dist_R(Rmin, Rmax);
  R = uniform_dist_R(e1);
  uniform_int_distribution<int> uniform_dist_Lx(Rmax, Lx - Rmax);
  uniform_int_distribution<int> uniform_dist_Ly(Rmax, Ly - Rmax);
  uniform_int_distribution<int> uniform_dist_t(1,t);
  x = uniform_dist_Lx(e1);
  y = uniform_dist_Ly(e1);
  string m, fichier;
  ostringstream convert;
  int l = uniform_dist_t(e1);
  convert << l;
  m = convert.str();
  fichier = "P" + m + ".png";
  texture.loadFromFile(fichier);
  M = 6e14*sqrt(R);
  vx = 0;
  vy = 0;
  Vecteur position(x,y);
  Vecteur vitesse(vx,vy);
  CorpsStellaire_.set_Objet(M, vitesse, position, texture);
  CorpsStellaire_.set_CorpsStellaire(R, corps_);
};

void mapping () {
  for (int i = 0; i<n; i++){
    corpsstellaire_generation(list_objet[i], corps[i], R, M);
  };
};

bool uncovering_test () {
  bool test = true;
  for (int j = 0; j < (n-1); j++) {
    for (int i = j+1; i < n; i++) {
      if (list_objet[j].Distance(list_objet[i].position_(), list_objet[j].position_()) < (list_objet[j].rayon_() + list_objet[i].rayon_()))
        test = false;
    };
  };
  if (test == false)
    mapping();
  return test;
};

void ship_deplacement (bool & test) {
  Prometheus.set_shape();
  Prometheus.Input_rot();
  Prometheus.RK4_rotation(h);
  Prometheus.Input_prop();
  Prometheus.RK4(h, list_objet);
  Prometheus.set_texture("V1");
  Prometheus.assign_texture();
  for (int i = 0; i<n; i++) {
    if(Prometheus.Distance(list_objet[i].position_(), Prometheus.position_()) < list_objet[i].rayon_() && test) {
      test = false;
    };
  };
}

void planete_deplacement (bool & test) {
  Vecteur position_precedente(Prometheus.position_());
  Vecteur position_vaisseau(1900/2 - Longueur/2 ,1200/2 - Largeur/2);
  Prometheus.set_shape(position_vaisseau.x_(), position_vaisseau.y_());
  Prometheus.Input_rot();
  Prometheus.RK4_rotation(h);
  Prometheus.Input_prop();
  Prometheus.RK4(h, list_objet);
  Prometheus.set_texture("V1");
  Prometheus.assign_texture();
  for (int i =  0 ; i<n ; i++) {
    //cout << list_objet[i].position_().x_() << "                      " << list_objet[i].position_().y_() << endl;
    Vecteur position(list_objet[i].position_() - (Prometheus.position_() - position_precedente));
    list_objet[i].set_position(position);
    //cout << list_objet[i].position_().x_() << "                      " << list_objet[i].position_().y_() << endl;
    //cout << Prometheus.Distance(list_objet[i].position_(), Prometheus.position_()) << endl;
    //cout << list_objet[i].rayon_() << endl;
  };
  for (int l = 0; l<n; l++) {
    if(Prometheus.Distance(list_objet[l].position_(), position_vaisseau) < list_objet[l].rayon_() && test) {
      //cout << "ECRASEMENT !!!" << endl;
      test = false;
    };
  };
};
