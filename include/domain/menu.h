#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
using namespace std;

class MenuItem {
private:
  std::string name;
  std::string description;
  float price;

public:
  MenuItem();
  ~MenuItem() {}
  MenuItem(string name, float price, string description);
  int getPrice() { return this->price; }
  string getName() { return this->name; }
  string getDescription() { return this->description; }
  string toString();
};

#endif
