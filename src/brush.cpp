#include "brush.h"

namespace river {
brush::brush(int color) : brush_(reinterpret_cast<brush_handle_t>(color)) {}

auto brush::get() -> brush_handle_t {
  return brush_;
}
}
