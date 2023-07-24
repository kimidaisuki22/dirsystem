#include "dirsystem/portable_app_dirs.h"
#include <filesystem>

namespace dirsystem {
Portable_dirs::Portable_dirs(std::filesystem::path current_path,
                             std::string app_name) {
  home_ = std::filesystem::absolute(current_path);
  portable_flag_ = is_portable_dir(home_);
  if (!is_portable()) {
    return;
  }
  config_ = home_ / ".local" / "config" / app_name;
  data_ = home_ / ".local" / "share" / app_name;
  cache_ = home_ / ".cache" / app_name;
  state_ = home_ / ".local" / "state" / app_name;
  runtime_ = home_ / ".local" / "run" / app_name;
  download_ = home_ / "Downloads" / app_name;
}
bool Portable_dirs::is_portable() const { return portable_flag_; }
bool Portable_dirs::is_portable_dir(std::filesystem::path dir) {
  return std::filesystem::exists(dir / ".portable");
}
} // namespace dirsystem