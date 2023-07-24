#pragma once

#include "dirsystem/types.h"
namespace dirsystem {

class Dirs {
public:
  virtual const Dir &home() const = 0;
  virtual const Dir &config() const = 0;
  virtual const Dir &data() const = 0;
  virtual const Dir &cache() const = 0;
  virtual const Dir &state() const = 0;
  virtual const Dir &runtime() const = 0;
  virtual const Dir &download() const = 0;
}; // namespace dirsystem

} // namespace dirsystem