#pragma once

#include "dirsystem/dirs.h"
#include "dirsystem/types.h"
#include <filesystem>
#include <memory>
#include <optional>
#include <string>

namespace dirsystem {

bool has_home();

// if not home present, it is not defined.
Dir home();
Dir config();
Dir data();
Dir cache();
Dir state();
std::optional<Dir> runtime();

Dir download();

std::shared_ptr<Dirs>
get_portable_dirs_or_normal(std::filesystem::path current_path,
                            std::string app_name, bool *is_portable = nullptr);
} // namespace dirsystem