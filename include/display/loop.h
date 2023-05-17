#ifndef DISPLAY_LOOP_H
#define DISPLAY_LOOP_H

#include "display/command.h"
#include <string>
using namespace std;

typedef void (*TransFuncPtr)();

class DisplayLoop {
public:
  void loop(CommandControl controller);
  DisplayLoop();
  string getCommand();
};

#endif
