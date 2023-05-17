#include "display/loop.h"
#include "display/command.h"
#include "domain/menu.h"
#include "domain/restaurant.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

DisplayLoop::DisplayLoop() {}

void DisplayLoop::loop(CommandControl controller) {
  string command_list;
  int command_choice;
  int continuation = 1;
  while (true && continuation) {
    string input;
    cout << "input>";
    getline(cin, input);
    try {
      command_choice = stoi(input);
      /* RestaurantCommandControl(command_choice); */
    } catch (exception &err) {
      command_choice = 999;
    }
    continuation = controller.select(command_choice);
    if (input.compare("END") == 0)
      break;
    else
      command_list.append(input);
  }
}

string DisplayLoop::getCommand() { return ""; }
