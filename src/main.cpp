#include "display/command.h"
#include "display/loop.h"
#include "domain/menu.h"
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

vector<MenuItem> getDefaultMenuItem() {
  MenuItem cheeseBurger("Classic Cheeseburger", 9.99,
                        "A juicy beef patty topped with melted ");
  MenuItem fishAndChip("Fish and Chips", 13.99,
                       "Golden-fried cod fillets served with crispy French "
                       "fries and tartar sauce");

  MenuItem baconCheeseFries(
      "Bacon Cheese Fries", 13.99,
      "Crispy French fries loaded with melted cheddar cheese ");

  MenuItem grilledChicken(
      "Grilled Chicken Sandwich", 9.99,
      "A juicy grilled chicken breast topped with melted Swiss cheese");

  MenuItem caesarSalad("Caesar Salad", 8.99,
                       "Crisp romaine lettuce, Parmesan cheese, crunchy "
                       "croutons, and zesty Caesar dressing");

  MenuItem viggieBurger(
      "Veggie Burger", 10.99,
      "A delicious vegetarian option featuring a homemade veggie patty made "
      "with black beans, mushrooms");

  MenuItem margherita("Margherita Pizza", 20.00,
                      "A classic Neapolitan-style pizza topped with San "
                      "Marzano tomato sauce, fresh mozzarella cheese");

  return {cheeseBurger,     fishAndChip,    grilledChicken,
          baconCheeseFries, grilledChicken, caesarSalad,
          viggieBurger,     margherita,     baconCheeseFries};

  /* {, "cheddar cheese, crispy lettuce, ripe tomato, and tangy ", */
  /*  "pickles, served on a toasted sesame seed bun. Price: $9.99"}; */
}
vector<Restaurant> initialization() {

  vector<MenuItem> menuItems = getDefaultMenuItem();
  Restaurant roba("ronaldo bay cha songdek pdous", "pp", "012 111 222");
  Restaurant loba("messi-cafe louk nhom koam", "pp", "096 696 969");
  Restaurant moba("Zlatan Ibrahimović pop tart 168", "pp", "012 420 420");

  roba.addMenuItem(menuItems[0]);
  roba.addMenuItem(menuItems[1]);
  roba.addMenuItem(menuItems[2]);

  loba.addMenuItem(menuItems[3]);
  loba.addMenuItem(menuItems[4]);
  loba.addMenuItem(menuItems[5]);

  moba.addMenuItem(menuItems[6]);
  moba.addMenuItem(menuItems[7]);
  moba.addMenuItem(menuItems[8]);
  vector<Restaurant> restaurant_list = {roba, loba, moba};
  for (unsigned int i = 0; i < restaurant_list.size(); i++) {
    randomRating(restaurant_list[i]);
  }

  return restaurant_list;
}

int main() {
  vector<Restaurant> Rest = initialization();
  CommandControl controller(Rest);
  DisplayLoop mainLoop;
  mainLoop.loop(controller);
}
