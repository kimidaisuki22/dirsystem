#include "dirsystem/app_dirs.h"
#include "dirsystem/dirsystem.h"
#include "dirsystem/util.h"
namespace dirsystem {

App_dirs::App_dirs(std::string app_name, bool need_run_dir) {

  home_ = dirsystem::home();
  config_ = concat(dirsystem::config(), app_name);
  data_ = concat(dirsystem::data(), app_name);
  cache_ = concat(dirsystem::cache(), app_name);
  state_ = concat(dirsystem::state(), app_name);
  if (auto run = dirsystem::runtime(); run) {
    runtime_ = concat(*run, app_name);
  } else {
    if (need_run_dir) {
      run.value(); // throw exception.
    }
  }
  download_ = concat(dirsystem::download(), app_name);
}
const Dir &App_dirs::runtime() const { return runtime_; }
const Dir &App_dirs::state() const { return state_; }
const Dir &App_dirs::cache() const { return cache_; }
const Dir &App_dirs::data() const { return data_; }
const Dir &App_dirs::config() const { return config_; }
const Dir &App_dirs::home() const { return home_; }
const Dir &App_dirs::download() const { return download_; }
} // namespace dirsystem