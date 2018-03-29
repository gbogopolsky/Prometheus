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
  corps_ (3),
  game_over_(),
  mode_(0)
{}

Data::Data (const double N,
            const double RMAX,
            const double RMIN,
            const double PROPULSION_AR,
            const double PROPULSION_AV,
            const double PROPULSION_LAT,
            const double PROPULSION_ROT,
            const double MASSE,
            const int MODE
            ) :
  n_(N),
  t_(3),
  R_(10.),
  M_(0.),
  Rmax_(RMAX),
  Rmin_(RMIN),
  Lx_(1900),
  Ly_(1200),
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
  corps_ (N),
  game_over_(),
  mode_(MODE)
{}

double Data::n () {
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

Text Data::game_over () {
  return (game_over_);
}

int Data::Mode () {
  return (mode_);
}

// void Data::default_setting_1 (vector<Input> & Input) {
//   ostringstream convert_0;
//   convert_0 << n_;
//   Input[0].set_input(convert_0.str());
//   ostringstream convert_1;
//   convert_1 << Rmax_;
//   Input[1].set_input(convert_1.str());
//   ostringstream convert_2;
//   convert_2 << Rmin_;
//   Input[2].set_input(convert_2.str());
//   ostringstream convert_3;
//   convert_3 << Propulsion_Ar_;
//   Input[3].set_input(convert_3.str());
//   ostringstream convert_4;
//   convert_4 << Propulsion_Av_;
//   Input[4].set_input(convert_4.str());
//   ostringstream convert_5;
//   convert_5 << Propulsion_Lat_;
//   Input[5].set_input(convert_5.str());
//   ostringstream convert_6;
//   convert_6 << Propulsion_Rot_;
//   Input[6].set_input(convert_6.str());
//   ostringstream convert_7;
//   convert_7 << Masse_;
//   Input[7].set_input(convert_7.str());
// }
//
// Data Data::cstr_setting_1 (vector<Input> Input) {
//   vector<double> covertion_table;
//   double Result;
//   for (unsigned int i = 0; i<Input.size(); i++) {
//     istringstream convert_number(Input[i].input());
//     if (!(convert_number >> Result))
//       Result = 0;
//     covertion_table.push_back(Result);
//   }
//   Data Parametres(covertion_table[0], covertion_table[1], covertion_table[2], covertion_table[3], covertion_table[4], covertion_table[5], covertion_table[6], covertion_table[7], mode_);
//   return (Parametres);
// }

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
      if (Prometheus_.Distance(list_objet_[i].position_(), Prometheus_.position_()) < list_objet_[i].rayon_())
        test = false;
    }
  }
  if (test == false)
    mapping();
  return test;
}

void Data::Texturage () {
  Prometheus_.set_texture("V1");
  Prometheus_.assign_texture();
}

void Data::reset () {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
    Prometheus_.set_position(position_initial_);
    Vecteur vect;
    Prometheus_.set_vitesse(vect);
  }
}

void Data::sides () {
  if (Prometheus_.position_().x_() > Lx_) {
    Prometheus_.set_position(0.,Prometheus_.position_().y_());
    mapping();
    uncovering_test();
  }
  if (Prometheus_.position_().x_() < 0.) {
    Prometheus_.set_position(Lx_,Prometheus_.position_().y_());
    mapping();
    uncovering_test();
  }
  if (Prometheus_.position_().y_() > Ly_) {
    Prometheus_.set_position(Prometheus_.position_().x_(),0.);
    mapping();
    uncovering_test();
  }
  if (Prometheus_.position_().y_() < 0.) {
    Prometheus_.set_position(Prometheus_.position_().x_(),Ly_);
    mapping();
    uncovering_test();
  }
}

void Data::Game_Over () {
  Vecteur position(400, Ly_/2-200);
  game_over_.loading(0,"28 Days Later", "GAME OVER", 200, position);
}

void Data::set_mode () {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
    mode_ = 0;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
    mode_ = 1;
  }
}

void Data::ship_deplacement (bool & test) {
  Prometheus_.set_shape();
  reset();
  Prometheus_.Input_rot();
  Prometheus_.RK4_rotation(h_);
  Prometheus_.Input_prop();
  Prometheus_.RK4(h_, list_objet_);
  sides();
  for (int i = 0; i<n_; i++) {
    if(Prometheus_.Distance(list_objet_[i].position_(), Prometheus_.position_()) < list_objet_[i].rayon_() && test) {
      test = false;
    }
  }
}

void Data::planete_deplacement (bool & test, Vecteur & Diff_de_ref) {
  Vecteur position_precedente(Prometheus_.position_());
  Vecteur position_vaisseau(1900/2 - Longueur_/2 ,1200/2 - Largeur_/2);
  Prometheus_.set_shape(position_vaisseau.x_(), position_vaisseau.y_());
  reset();
  Prometheus_.Input_rot();
  Prometheus_.RK4_rotation(h_);
  Prometheus_.Input_prop();
  Prometheus_.RK4(h_, list_objet_);
  Diff_de_ref = (Prometheus_.position_() - position_initial_);
  for (int l = 0; l<n_; l++) {
    if(Prometheus_.Distance(list_objet_[l].position_(), Prometheus_.position_()) < list_objet_[l].rayon_() && test) {
      test = false;
    }
  }
}
