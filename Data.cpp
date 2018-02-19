#include "Data.h"

//Paramètres aléatoirs
random_device r;
mt19937_64  e1(r());

Data::Data () :
  n_(3),
  t_(3),
  R_(10.),
  M_(0.),
  Rmax_(120),
  Rmin_(40),
  Lx_(1900),
  Ly_(1200),
  h_(0.08),
  Propulsion_Ar_(80),
  Propulsion_Av_(20),
  Propulsion_Lat_(10),
  Propulsion_Rot_(10),
  Masse_(1),
  Largeur_(40),
  Longueur_(40),
  position_initial_(1900/2, 1200/2),
  Ship_ (sf::Vector2f(40,40)),
  Prometheus_(
    80,
    20,
    10,
    10,
    Vecteur (),
    Vecteur (),
    Vecteur (),
    Vecteur (1900/2, 1200/2),
    1,
    texture_vaisseau_,
    Ship_
    ),
  list_objet_ (3),
  corps_ (3)
{}

Data::Data (const int N,
            const int RMAX,
            const int RMIN,
            const int LX,
            const int LY,
            const double PROPULSION_AR,
            const double PROPULSION_AV,
            const double PROPULSION_LAT,
            const double PROPULSION_ROT,
            const double MASSE
            ) :
  n_(N),
  t_(3),
  R_(10.),
  M_(0.),
  Rmax_(RMAX),
  Rmin_(RMIN),
  Lx_(LX),
  Ly_(LY),
  h_(0.08),
  Propulsion_Ar_(PROPULSION_AR),
  Propulsion_Av_(PROPULSION_AV),
  Propulsion_Lat_(PROPULSION_LAT),
  Propulsion_Rot_(PROPULSION_ROT),
  Masse_(MASSE),
  Largeur_(40),
  Longueur_(40),
  position_initial_(1900/2, 1200/2),
  Ship_ (sf::Vector2f(40,40)),
  Prometheus_(
    PROPULSION_AR,
    PROPULSION_AV,
    PROPULSION_LAT,
    PROPULSION_ROT,
    Vecteur(),
    Vecteur(),
    Vecteur(),
    Vecteur (1900/2, 1200/2),
    MASSE,
    texture_vaisseau_,
    Ship_
    ),
  list_objet_ (N),
  corps_ (N)
{}

int Data::n () {
  return (n_);
}

int Data::Lx () {
  return (Lx_);
}

int Data::Ly () {
  return (Ly_);
}

sf::RectangleShape Data::Ship () {
  return (Ship_);
}

Vaisseau Data::Prometheus () {
  return (Prometheus_);
}

vector<CorpsStellaire> Data::list_objet () {
  return (list_objet_);
}

vector<sf::CircleShape> Data::corps () {
  return (corps_);
}

sf::Text Data::game_over () {
  return (game_over_);
}

sf::Text Data::game_name () {
  return (game_name_);
}

sf::Text Data::params () {
  return (params_);
}

void Data::loading_font (string nom_font, sf::Font & font) {
  font.loadFromFile(nom_font + ".ttf");
}

void Data::text_GO () {
  loading_font("contrast", font_);
  game_over_.setFont(font_);
  game_over_.setString(std::string("GAME OVER"));
  game_over_.setCharacterSize(100);
  game_over_.setColor(sf::Color::Red);
  game_over_.setPosition(100,100);
}

void Data::setting () {
  loading_font("cubic", font_name_);
  game_name_.setFont(font_name_);
  loading_font("FORCED SQUARE", font_txt_);
  params_.setFont(font_txt_);
  game_name_.setString(std::string("PROMETHEUS"));
  game_name_.setCharacterSize(100);
  game_name_.setColor(sf::Color::Yellow);
  game_name_.setPosition(100, 200);
  params_.setCharacterSize(40);
  params_.setColor(sf::Color::Yellow);
  params_.setPosition(100, 400);
}

void Data::corpsstellaire_generation (CorpsStellaire & CorpsStellaire_, sf::CircleShape & corps_) {
  double x, y, vx, vy;
  sf::Texture texture;
  uniform_int_distribution<int> uniform_dist_R(Rmin_, Rmax_);
  R_ = uniform_dist_R(e1);
  uniform_int_distribution<int> uniform_dist_Lx(Rmax_, Lx_ - Rmax_);
  uniform_int_distribution<int> uniform_dist_Ly(Rmax_, Ly_ - Rmax_);
  uniform_int_distribution<int> uniform_dist_t(1,t_);
  x = uniform_dist_Lx(e1);
  y = uniform_dist_Ly(e1);
  string m, fichier;
  ostringstream convert;
  int l = uniform_dist_t(e1);
  convert << l;
  m = convert.str();
  fichier = "P" + m + ".png";
  texture.loadFromFile(fichier);
  M_ = 6e14*sqrt(R_);
  vx = 0;
  vy = 0;
  Vecteur position(x,y);
  Vecteur vitesse(vx,vy);
  CorpsStellaire_.set_Objet(M_, vitesse, position, texture);
  CorpsStellaire_.set_CorpsStellaire(R_, corps_);
}

void Data::mapping () {
  for (int i = 0; i<n_; i++){
    corpsstellaire_generation(list_objet_[i], corps_[i]);
  };
};

bool Data::uncovering_test () {
  bool test = true;
  for (int j = 0; j < (n_ - 1); j++) {
    for (int i = j+1; i < n_; i++) {
      if (list_objet_[j].Distance(list_objet_[i].position_(), list_objet_[j].position_()) < (list_objet_[j].rayon_() + list_objet_[i].rayon_()))
        test = false;
    };
  };
  if (test == false)
    mapping();
  return test;
}

void Data::Texturage () {
  Prometheus_.set_texture("V1");
  Prometheus_.assign_texture();
}

void Data::ship_deplacement (bool & test) {
  Prometheus_.set_shape();
  Prometheus_.Input_rot();
  Prometheus_.RK4_rotation(h_);
  Prometheus_.Input_prop();
  Prometheus_.RK4(h_, list_objet_);
  for (int i = 0; i<n_; i++) {
    if(Prometheus_.Distance(list_objet_[i].position_(), Prometheus_.position_()) < list_objet_[i].rayon_() && test) {
      test = false;
    };
  };
}

void Data::planete_deplacement (bool & test, Vecteur & Diff_de_ref) {
  Vecteur position_precedente(Prometheus_.position_());
  Vecteur position_vaisseau(1900/2 - Longueur_/2 ,1200/2 - Largeur_/2);
  Prometheus_.set_shape(position_vaisseau.x_(), position_vaisseau.y_());
  Prometheus_.Input_rot();
  Prometheus_.RK4_rotation(h_);
  Prometheus_.Input_prop();
  Prometheus_.RK4(h_, list_objet_);
  Diff_de_ref = (Prometheus_.position_() - position_initial_);
  for (int l = 0; l<n_; l++) {
    if(Prometheus_.Distance(list_objet_[l].position_(), Prometheus_.position_()) < list_objet_[l].rayon_() && test) {
      test = false;
    };
  };
}

void Data::vaisseauStabilisation () {
   double eps = 1.e-3;
   double vitesse_x = Prometheus_.vitesse_().x_();
   double vitesse_y = Prometheus_.vitesse_().y_();
   double rot = Prometheus_.rotation_().x_();
   if (vitesse_x > eps) {};   //=> accélération selon -x
   if (vitesse_x < - eps) {}; //=> accélération selon +x
   if (vitesse_y > eps) {};   //=> accélération selon -y
   if (vitesse_y < - eps) {}; //=> accélération selon +y
   if (rot > eps) {};         //=> couple selon -angle
   if (rot < eps) {};         //=> couple selon +angle
}
