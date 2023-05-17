#include "display/command.h"
#include "domain/restaurant.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

CommandControl::CommandControl(vector<Restaurant> restaurant_list) {
  this->restaurant_list = restaurant_list;
}

vector<string> command_list = {
    "View Restaurant list", "Add Restaurant", "View Restaurant details",
    "Add menu item",        "Help",           "Exit"};

void printCommandList(vector<string> &command_list) {
  for (int i = 0; i < command_list.size(); i++) {
    cout << i + 1 << "." << command_list[i] << endl;
  }
}

bool checkEmptyInput(string input) {
  if (input == "") {
    cout << "Cannot accept empty input..." << endl;
    return 1;
  }
  return 0;
}

static void addRestaurant(vector<Restaurant> &restaurant_list) {
  string name, address, phone_number;
  cout << "Enter name of new restaurant: ";
  getline(cin, name);
  if (checkEmptyInput(name)) {
    return;
  }
  int rest_size = restaurant_list.size();
  for (int i = 0; i < rest_size; i++) {
    if (restaurant_list[i].getName() == name) {
      cout << "Error: Restaurant with the same name already exists." << endl;
      return;
    }
  }

  cout << "Enter address of new restaurant: ";
  getline(cin, address);
  if (checkEmptyInput(address)) {
    return;
  }

  cout << "Enter phone number of new restaurant: ";
  getline(cin, phone_number);
  if (checkEmptyInput(phone_number)) {
    return;
  }

  Restaurant new_restaurant(name, address, phone_number);
  restaurant_list.push_back(new_restaurant);
  cout << "New restaurant added successfully." << endl;
}

void viewRestaurantDetail(vector<Restaurant> &restaurant_list) {
  int rest_size = restaurant_list.size();
  for (int i = 0; i < rest_size; i++) {
    cout << restaurant_list[i].toString() << endl;
  }
}
void viewRestaurantList(vector<Restaurant> &restaurant_list) {
  int rest_size = restaurant_list.size();
  for (int i = 0; i < rest_size; i++) {
    cout << i << "." << restaurant_list[i].getName() << endl;
  }
}

void addMenuItem(vector<Restaurant> &restaurant_list) {
  string choice_str;
  int choice;
  viewRestaurantList(restaurant_list);

  cout << "Choose a restaurant to add menu item: ";
  cin >> choice_str;
  try {
    choice = stoi(choice_str);
  } catch (exception &e) {
    cout << "Only select using number!" << endl;
    return;
  }

  if (choice >= 1 && choice <= restaurant_list.size()) {
    string name, description;
    float price;

    cout << "Enter name of menu item: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter price of menu item: $";
    cin >> price;
    cout << "Enter description of menu item: ";
    cin.ignore();

    getline(cin, description);
    MenuItem new_item(name, price, description);

    restaurant_list[choice - 1].addMenuItem(new_item);

    cout << "\n";
    cout << "New item info :" << endl;
    cout << new_item.toString() << endl;
    cout << "New menu item added successfully." << endl;
    // Update the restaurant list with the modified restaurant object
  } else {
    cout << "Invalid Restaurant choice." << endl;
    return;
  }
}

int RestaurantCommandControl(int command, vector<Restaurant> &restaurant_list) {
  switch (command) {
  case 1:
    cout << "Avialable Restaurant:" << endl;
    viewRestaurantList(restaurant_list);
    break;
  case 2:
    cout << "Adding new restaurant..." << endl;
    addRestaurant(restaurant_list);
    break;
  case 3:
    cout << "View restaurant Detail:" << endl;
    viewRestaurantDetail(restaurant_list);
    break;
  case 4:
    addMenuItem(restaurant_list);
    break;
  case 5:
    cout << "Available commands :" << endl;
    printCommandList(command_list);
    break;
  case 6:
    cout << "Exiting program..." << endl;
    return 0;
    break;
  case 999:
    cout << "Invalid command choice !\nWe only accept integer available in "
            "our command list."
         << endl;
    cout << "Type 5 to see our supported commands!" << endl;
    break;

  default:
    cout << "fallback!!" << endl;
    break;
  }
  return 1;
}

int CommandControl::select(int choice) {
  int signal = RestaurantCommandControl(choice, this->restaurant_list);
  return signal;
}
