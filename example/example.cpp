#include "dirsystem/app_dirs.h"
#include "dirsystem/dirsystem.h"

#include <iostream>

#define PrintL(x) std::cout << #x ": " << x << "\n";
int main() {
  PrintL(dirsystem::has_home());
  PrintL(dirsystem::home());
  PrintL(dirsystem::cache());
  PrintL(dirsystem::config());
  PrintL(dirsystem::data());
  PrintL(dirsystem::state());
  PrintL(dirsystem::runtime().value());
  PrintL(dirsystem::download());

  dirsystem::App_dirs app_dir{"fun"};
  PrintL(app_dir.home());
  PrintL(app_dir.cache());
  PrintL(app_dir.config());
  PrintL(app_dir.data());
  PrintL(app_dir.state());
  PrintL(app_dir.runtime());
  PrintL(app_dir.download());
}