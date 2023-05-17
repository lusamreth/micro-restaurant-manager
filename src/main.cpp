#include <iostream>
using namespace std;
#include "domain/restaurant.h"

// follow this comprehensive folder structure
// https://github.com/tiernemi/meson-sample-project/tree/master
// some documentation from meson :
// https://mesonbuild.com/Include-directories.html
// https://mesonbuild.com/Localisation.html
// build target options : https://mesonbuild.com/Build-targets.html
// build static_library for linker :
// https://mesonbuild.com/Reference-manual_functions.html#static_library
//
int main() {
  cout << "TiA" << endl;
  Restaurant roba("lobaba", "pp", "012201820");
  Restaurant loba("kaka cafe", "pp", "012201820");
  Restaurant moba("moba", "pp", "012201820");

  cout << roba.getName() << endl;

  Rate okRate(4);
  Rate badRate(1);
  Rate medRate(2);

  roba.addRate(okRate);
  roba.addRate(badRate);
  roba.addRate(medRate);

  cout << roba.getRate() << endl;

  string command_list;

  while (true) {
    string input;
    getline(cin, input);

    if (input.compare("END") == 0)
      break;
    else
      command_list.append(input);
  }
  return 0;
}
