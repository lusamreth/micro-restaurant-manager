#include "display/command.h"
#include "display/loop.h"
#include "domain/restaurant.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// follow this comprehensive folder structure
// https://github.com/tiernemi/meson-sample-project/tree/master
// some documentation from meson :
// https://mesonbuild.com/Include-directories.html
// https://mesonbuild.com/Localisation.html
// build target options : https://mesonbuild.com/Build-targets.html
// build static_library for linker :
// https://mesonbuild.com/Reference-manual_functions.html#static_library
//

void randomRating(Restaurant &restaurant) {
  srand(time(0));
  for (int i = 0; i < 3; i++) {
    int rando = rand() % 10;
    Rate random_rating = Rate(rando);
    restaurant.addRate(random_rating);
  }
}

void ItemMenu() {}

vector<Restaurant> initialization() {

  Restaurant roba("ronaldo bay cha songdek pdous", "pp", "012 111 222");
  Restaurant loba("messi-cafe louk nhom koam", "pp", "096 696 969");
  Restaurant moba("Zlatan Ibrahimović pop tart 168", "pp", "012 420 420");

  vector<Restaurant> restaurant_list = {roba, loba, moba};
  for (unsigned int i = 0; i < restaurant_list.size(); i++) {
    randomRating(restaurant_list[i]);
  }

  int rating = restaurant_list[0].getRate();
  cout << "each rating " << rating << endl;
  return restaurant_list;
}

int main() {
  vector<Restaurant> Rest = initialization();
  CommandControl controller(Rest);
  DisplayLoop mainLoop;
  mainLoop.loop(controller);
}
