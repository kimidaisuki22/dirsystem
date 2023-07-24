#pragma once
#include "dirsystem/dirs.h"
namespace dirsystem {

class Plain_dirs : public Dirs {
public:
  Plain_dirs();
  Plain_dirs(Dir home, Dir config, Dir data, Dir cache, Dir state, Dir runtime,
             Dir download);
  Plain_dirs(std::string app_name);
  const Dir &home() const override { return home_; }
  const Dir &config() const override { return config_; }
  const Dir &data() const override { return data_; }
  const Dir &cache() const override { return cache_; }
  const Dir &state() const override { return state_; }
  const Dir &runtime() const override { return runtime_; }
  const Dir &download() const override { return download_; }

  Dir home_;
  Dir config_;
  Dir data_;
  Dir cache_;
  Dir state_;
  Dir runtime_;
  Dir download_;
};
} // namespace dirsystem