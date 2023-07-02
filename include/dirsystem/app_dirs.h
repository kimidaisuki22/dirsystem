#pragma once
#include "dirsystem/dirsystem.h"
#include <optional>
#include <string>
namespace dirsystem {
class App_dirs {
public:
  App_dirs(std::string app_name,
           bool need_run_dir = true);

  const Dir &home() const;
  const Dir &config() const;
  const Dir &data() const;
  const Dir &cache() const;
  const Dir &state() const;
  const Dir &runtime() const;
  const Dir &download() const;

private:
  Dir home_;
  Dir config_;
  Dir data_;
  Dir cache_;
  Dir state_;
  Dir runtime_;
  Dir download_;
};
} // namespace dirsystem