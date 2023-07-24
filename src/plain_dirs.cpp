#include "dirsystem/plain_dirs.h"
#include "dirsystem/app_dirs.h"
dirsystem::Plain_dirs::Plain_dirs(Dir home, Dir config, Dir data, Dir cache,
                                  Dir state, Dir runtime, Dir download) {
  home_ = home;
  config_ = config;
  data_ = data;
  cache_ = cache;
  state_ = state;
  runtime_ = runtime;
  download_ = download;
}
dirsystem::Plain_dirs::Plain_dirs(std::string app_name, bool need_run_dir) {
  dirsystem::App_dirs app_dirs(app_name, need_run_dir);
  home_ = app_dirs.home();
  config_ = app_dirs.config();
  data_ = app_dirs.data();
  cache_ = app_dirs.cache();
  state_ = app_dirs.state();
  runtime_ = app_dirs.runtime();
  download_ = app_dirs.download();
}
