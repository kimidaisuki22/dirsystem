#include "dirsystem/app_dirs.h"
#include "dirsystem/dirsystem.h"
#include "dirsystem/portable_app_dirs.h"

#include <filesystem>
#include <fstream>
#include <iostream>

#define PrintL(x) std::cout << #x ": " << x << "\n";
#define PrintLT(t, x) std::cout << t << ": " << #x << "(" << x << ")\n";

auto print_dirs(auto type_name, auto &type) {
  PrintLT(type_name, type.home());
  PrintLT(type_name, type.cache());
  PrintLT(type_name, type.config());
  PrintLT(type_name, type.data());
  PrintLT(type_name, type.state());
  PrintLT(type_name, type.runtime());
  PrintLT(type_name, type.download());
}
int main() {
  PrintL(dirsystem::has_home());
  PrintL(dirsystem::home());
  PrintL(dirsystem::cache());
  PrintL(dirsystem::config());
  PrintL(dirsystem::data());
  PrintL(dirsystem::state());
  std::string runtime =
      dirsystem::runtime() ? dirsystem::runtime().value().string() : "no runtime.";
  PrintL(runtime);
  PrintL(dirsystem::download());

  dirsystem::App_dirs app_dir{"fun"};
  print_dirs("App_dirs", app_dir);

  dirsystem::Portable_dirs portable_dir{std::filesystem::current_path(), "fun"};
  print_dirs("Portable_dirs", portable_dir);
  if (!portable_dir.is_portable()) {
    std::cout << "Not portable\n";
    std::cout << "Make it portable dir(create .portable)\n";

    std::ofstream file{".portable", std::ios::app};
    file.close();
    portable_dir =
        dirsystem::Portable_dirs{std::filesystem::current_path(), "fun"};
    print_dirs("Portable_dirs", portable_dir);
  }

  auto ptr = dirsystem::get_portable_dirs_or_normal(
      std::filesystem::current_path(), "fun");

  print_dirs("get_portable_dirs_or_normal", *ptr);
  std::filesystem::remove(".portable");

  ptr = dirsystem::get_portable_dirs_or_normal(std::filesystem::current_path(),
                                               "fun");

  print_dirs("get_portable_dirs_or_normal", *ptr);

  return 0;
}
