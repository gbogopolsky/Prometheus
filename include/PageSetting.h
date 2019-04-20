#ifndef PageSetting_h
#define PageSetting_h
#include <SFML/Graphics.hpp>
#include <vector>
#include "Vecteur.h"
#include "Text.h"
#include "Input.h"

using namespace std;

class PageSetting : public Input {
public:
  PageSetting ();
  PageSetting (int N);
  PageSetting (int N, int M);
  PageSetting (int N, vector<Text> TEXTS, vector<Input> INPUT_ZONES);

  int n ();
  int m ();
  vector<Text> texts ();
  vector<Input> input_zones ();

  void setting_1 (int mode);

private:
  int n_;
  vector<Text> texts_;
  vector<Input> input_zones_;
};

#endif
