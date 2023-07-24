#include "dirsystem/plain_dirs.h"
#include "dirsystem/portable_app_dirs.h"
#ifdef _WIN32
#include "dirsystem/dirsystem.h"
#include "dirsystem/util.h"
#include <Shlobj.h>
#include <optional>
#include <windows.h>

namespace dirsystem {

bool has_home() {
  PWSTR path = NULL;
  return SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Profile, 0, NULL, &path));
}

Dir home() {
  PWSTR path = NULL;
  SHGetKnownFolderPath(FOLDERID_Profile, 0, NULL, &path);
  Dir result = path;
  CoTaskMemFree(path);
  return result;
}

Dir state() {
  // There is no equivalent to XDG_STATE_HOME in Windows.
  // But you can use the local app data folder instead.
  PWSTR path = NULL;
  SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &path);
  Dir result = path;
  CoTaskMemFree(path);
  return result;
}

Dir cache() {
  return env("TEMP").value();
  PWSTR path = NULL;
  SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &path);
  Dir result = path;
  CoTaskMemFree(path);
  return result;
}

Dir data() {
  PWSTR path = NULL;
  SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &path);
  Dir result = path;
  CoTaskMemFree(path);
  return result;
}

Dir config() {
  PWSTR path = NULL;
  SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &path);
  Dir result = path;
  CoTaskMemFree(path);
  return result;
}

std::optional<Dir> runtime() {
  // There is no perfect equivalent for this in Windows
  // but the closest might be the Temp folder
  PWSTR path = NULL;
  if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Profile, 0, NULL, &path))) {
    Dir result = path;
    CoTaskMemFree(path);
    return result;
  }
  return std::nullopt;
}

Dir download() {
  PWSTR path = NULL;
  SHGetKnownFolderPath(FOLDERID_Downloads, 0, NULL, &path);
  Dir result = path;
  CoTaskMemFree(path);
  return result;
}

} // namespace dirsystem

#else

#include "dirsystem/dirsystem.h"
#include "dirsystem/util.h"
#include <optional>

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
#endif

namespace dirsystem {

std::shared_ptr<Dirs>
get_portable_dirs_or_normal(std::filesystem::path current_path,
                            std::string app_name, bool *is_portable) {
  auto portable_dirs = std::make_shared<Portable_dirs>(current_path, app_name);
  if (portable_dirs && portable_dirs->is_portable()) {
    if (is_portable) {
      *is_portable = portable_dirs->is_portable();
    }
    return portable_dirs;
  }
  if (is_portable) {
    *is_portable = false;
  }
  return std::make_shared<Plain_dirs>(app_name);
}
} // namespace dirsystem