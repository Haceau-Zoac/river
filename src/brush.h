#ifndef RIVER_BRUSH_H
#define RIVER_BRUSH_H

#include <Windows.h>

namespace river {
class brush {
  public:
  using brush_handle_t = HBRUSH;

  brush(int color);

  auto get() -> brush_handle_t;

  protected:
  brush_handle_t brush_;
};
}

#endif // RIVER_BRUSH_H
