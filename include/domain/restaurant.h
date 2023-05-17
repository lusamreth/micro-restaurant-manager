#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "domain/menu.h"
#include "domain/rate.h"
#include <string>
#include <vector>
using namespace std;

class Restaurant {
private:
  std::string name;
  std::string address;
  std::vector<MenuItem> menu;
  string phone_number;

public:
  // Constructors
  Restaurant();
  ~Restaurant() {}
  Restaurant(string name, string location, string phone_number);

  // Accessors and mutators
  std::string getName();
  void setName(std::string name);
  std::string getLocation();
  void setAddress(std::string address);
  std::vector<MenuItem> getMenuItems();
  string toString();
  void addMenuItem(MenuItem menu);
  float getRate();
  float addRate(Rate rate);
};

#endif // RESTAURANT_H
