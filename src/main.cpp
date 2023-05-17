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
int main() {
  cout << "TiA" << endl;
  Restaurant roba("lobaba", "pp", "BRUH");
  cout << roba.getName() << endl;
  return 0;
}
