
#pragma once
#include "dirsystem/dirs.h"
#include <optional>
#include <string>
namespace dirsystem {
class Portable_dirs : public Dirs {
public:
  Portable_dirs(std::filesystem::path current_path, std::string app_name);

  const Dir &home() const override { return home_; }
  const Dir &config() const override { return config_; }
  const Dir &data() const override { return data_; }
  const Dir &cache() const override { return cache_; }
  const Dir &state() const override { return state_; }
  const Dir &runtime() const override { return runtime_; }
  const Dir &download() const override { return download_; }

  bool is_portable() const;

private:
  static bool is_portable_dir(std::filesystem::path dir);
  Dir home_;
  Dir config_;
  Dir data_;
  Dir cache_;
  Dir state_;
  Dir runtime_;
  Dir download_;
  bool portable_flag_;
};
} // namespace dirsystem