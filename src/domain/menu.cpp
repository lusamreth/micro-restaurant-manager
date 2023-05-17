#include "domain/menu.h"
#include <string>

using namespace std;

MenuItem::MenuItem() {
  name = "";
  description = "";
  price = 0;
}

// Constructor with arguments
MenuItem::MenuItem(string name, float price, string description) {
  this->name = name;
  this->description = description;
  this->price = price;
}

string MenuItem::toString() {
  string price_str = std::to_string(this->getPrice());
  string item_template =
      "The item : " + this->getName() + " cost " + price_str + "\n";
  item_template += "description : " + this->getDescription();
  return item_template;
  /* return this.name + this->description + ; */
}
/* class Menu */
