#include "device_context.h"
#include "type.h"
#include "window.h"

namespace river {

device_context::device_context(window const& win)
: device_context(win.get()) {}
device_context::device_context(window::window_handle_t const& win)
: dc_(BeginPaint(win, &ps_))
, win_(win) {}
device_context::~device_context() {
  EndPaint(win_.get(), &ps_);
}

auto device_context::fill(rectangle& rect, brush brush) -> void {
  FillRect(dc_, &rect, brush.get());
}

auto device_context::paint_rectangle() -> rectangle& {
  return ps_.rcPaint;
}

}
