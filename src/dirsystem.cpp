#include "dirsystem/dirsystem.h"
#include <optional>
#include "dirsystem/util.h"
 
namespace dirsystem {
bool has_home() { return env("HOME").has_value(); }

Dir home() { return env("HOME").value(); }
Dir state() {
  return choose_env_with_fall_back("XDG_STATE_HOME", ".local/state").value();
}
Dir cache() {
  return choose_env_with_fall_back("XDG_CACHE_HOME", ".cache").value();
}
Dir data() {
  return choose_env_with_fall_back("XDG_DATA_HOME", ".local/share").value();
}
Dir config() {
  return choose_env_with_fall_back("XDG_CONFIG_HOME", ".config").value();
}
std::optional<Dir> runtime() { return env("XDG_RUNTIME_DIR"); }
Dir download() {
  return choose_env_with_fall_back("XDG_DOWNLOAD_DIR", "Downloads").value();
}
} // namespace dirsystem