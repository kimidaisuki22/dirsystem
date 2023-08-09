#define _CRT_SECURE_NO_WARNINGS
#include "dirsystem/util.h"
dirsystem::Dir dirsystem::concat(dirsystem::Dir parent, dirsystem::Dir child) {
  return parent / child;
}
std::optional<dirsystem::Dir> dirsystem::env(const char *elem) {
  auto c_str = getenv(elem);
  if (c_str) {
    return c_str;
  }
  return {};
}
