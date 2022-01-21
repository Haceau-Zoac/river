#include "message.h"
#include "type.h"
#include "window.h"

namespace river {
message_identifier::message_identifier(unsigned msg, window::window_handle_t win)
: message_identifier(static_cast<window_message>(msg), win) {}
message_identifier::message_identifier(window_message msg, window::window_handle_t win) 
: msg_(msg), win_(win) {}

auto message_identifier::dispatch(wparameter wp, lparameter lp) -> result {
  if (!func_.has_value()) {
    return DefWindowProcW(win_.get(), static_cast<unsigned>(msg_), wp, lp);
  }
  return func_.value()(wp, lp);
}


message::message() {}
message::message(message::message_t msg) : msg_(msg) {}

auto message::run_loop() -> void {
  message msg;
  while (message::get(msg)) {
    msg.translate();
    msg.dispatch();
  }
}

auto message::get(message &msg) -> bool {
  return GetMessage(&msg.msg_, nullptr, 0, 0);
}

auto message::post_quit(int code) -> void {
  PostQuitMessage(code);
}

auto message::translate() -> void {
  TranslateMessage(&msg_);
}

auto message::dispatch() -> void {
  DispatchMessageW(&msg_);
}
}
