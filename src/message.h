#ifndef RIVER_MESSAGE_H
#define RIVER_MESSAGE_H

#include "type.h"
#include "window.h"
#include <Windows.h>
#include <optional>
#include <functional>

namespace river {

enum class window_message {
  destory = WM_DESTROY,
  paint = WM_PAINT
};

class message_identifier {
  window_message msg_;
  window win_;
  std::optional<std::function<result(wparameter, lparameter)>> func_;
  public:
  message_identifier(unsigned msg, window::window_handle_t win);
  message_identifier(window_message msg, window::window_handle_t win);

  template<typename TFunc>
  auto on_destroy(TFunc func) -> bool {
    if (msg_ == window_message::destory) {
      func_ = std::make_optional([=](wparameter, lparameter){ return func(); });
      return true;
    }
    return false;
  }

  template<typename TFunc>
  auto on_paint(TFunc func) -> bool {
    if (msg_ == window_message::paint) {
      func_ = std::make_optional([=](wparameter, lparameter){ return func(win_); });
      return true;
    }
    return false;
  }

  template<typename TFunc>
  auto on_default(TFunc func) -> bool {
    if (!func_.has_value()) {
      func_ = std::make_optional([=](wparameter, lparameter){ return func(); });
      return true;
    }
    return false;
  }
  auto dispatch(wparameter wp, lparameter lp) -> result;
};

class message {
  public:
  using message_t = MSG;

  static auto run_loop() -> void;
  static auto get(message& msg) -> bool;
  static auto post_quit(int code = 0) -> void;

  message();
  message(message_t msg);
  auto translate() -> void;
  auto dispatch() -> void;
  protected:
  message_t msg_;
};

}

#endif // RIVER_MESSAGE_H
