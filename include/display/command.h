
#ifndef COMMAND_H
#define COMMAND_H

#include "domain/restaurant.h"
#include <string>
#include <vector>
using namespace std;

class CommandControl {
private:
  vector<Restaurant> restaurant_list;

public:
  CommandControl(vector<Restaurant> rest_list);
  int select(int choice);
};

#endif
