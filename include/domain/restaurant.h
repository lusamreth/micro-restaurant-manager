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
  std::vector<Rate> rate_list;

public:
  // Constructors
  Restaurant();
  ~Restaurant() {}
  Restaurant(string name, string location, string phone_number);

  // Accessors and mutators
  std::string getName();
  std::string getLocation();

  void setName(std::string name);
  void setAddress(std::string address);

  std::vector<MenuItem> getMenuItems();
  void addMenuItem(MenuItem menu);

  string toString();

  int getRate();
  void addRate(Rate rate);
};

#endif // RESTAURANT_H
