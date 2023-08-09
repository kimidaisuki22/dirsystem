#pragma once

#include "dirsystem/dirsystem.h"
#include <optional>
namespace dirsystem {

std::optional<dirsystem::Dir> env(const char *elem);

template <typename T, typename... Optionals>
auto choose(const T &op, const Optionals &...ops) {
  if (op) {
    return op;
  }
  if constexpr (sizeof...(ops) == 0) {
    return T{};
  }
  return choose(ops...);
}

template <typename T, typename... Optionals>
auto chooseF(const T &op, const Optionals &...ops) {
  if (auto elem = op(); elem) {
    return elem;
  }
  if constexpr (sizeof...(ops) == 0) {
    return decltype(op()){};
  } else {
    return chooseF(ops...);
  }
}

template <typename T, typename Func> T then(T elem, Func f) {
  if (elem) {
    return f(*elem);
  } else {
    return {};
  }
}

dirsystem::Dir concat(dirsystem::Dir parent, dirsystem::Dir child);

template <typename T>
std::optional<dirsystem::Dir>
choose_env_with_fall_back(const T &env_name,
                          const std::string &dir_under_home_for_fall_back) {
  return chooseF([&] { return env(env_name); },
                 [&]() -> std::optional<dirsystem::Dir> {
                   return concat(dirsystem::home(),
                                 dir_under_home_for_fall_back);
                 });
}
} // namespace dirsystem