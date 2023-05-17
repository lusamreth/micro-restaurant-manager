#include "domain/restaurant.h"
#include "domain/menu.h"
using namespace std;

// Default constructor
Restaurant::Restaurant() {
  name = "";
  address = "";
  phone_number = "";
  menu = {};
}

// Constructor with arguments
Restaurant::Restaurant(string name, string address, string phone_number) {
  this->name = name;
  this->address = address;
  this->phone_number = phone_number;

  vector<MenuItem> emptyMenu = {};
  this->menu = emptyMenu;
}

std::string Restaurant::getName() { return name; }

void Restaurant::setName(string name) { this->name = name; }

std::string Restaurant::getLocation() { return address; }

void Restaurant::setAddress(string location) { this->address = location; }

std::vector<MenuItem> Restaurant::getMenuItems() { return this->menu; }

void Restaurant::addMenuItem(MenuItem item) { this->menu.push_back(item); }

string Restaurant::toString() {
  string rest_template = "";

  string name_template = "The restaurant name is called " + this->name + "\n";
  string addrs_str = "Location : " + this->address + "\n";
  string phone_number_str = "Contact : " + this->phone_number + "\n";

  rest_template = name_template + addrs_str + phone_number;
  return rest_template;
}
