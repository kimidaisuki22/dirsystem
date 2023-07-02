#pragma once

#include <optional>
#include <string>
namespace dirsystem {
using Dir = std::string;

bool has_home();

// if not home present, it is not defined.
Dir home();
Dir config();
Dir data();
Dir cache();
Dir state();
std::optional<Dir> runtime();

Dir download();

} // namespace dirsystem