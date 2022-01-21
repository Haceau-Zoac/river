#include <windows.h>
#include "window_class.h"
#include "message.h"
#include "window.h"
#include "type.h"
#include "color.h"
#include "device_context.h"

auto river_callback window_procedure(river::window::window_handle_t hwnd, unsigned rmsg, river::wparameter wparam, river::lparameter lparam) -> river::result;

auto main() -> int {
  // Register the window class.
  wchar_t const class_name[]{ L"Sample Window Class" };

  river::window_class wc(class_name);
  wc.set_procedure(window_procedure);
  wc.reg();

  // Create the window.
  river::window_config config{};
  config.window_class = &wc;
  config.style = river::window_style::overlapped_window;
  config.text = L"Learn to Program Windows";
  auto window_opt = river::window::create(config);

  if (!window_opt.has_value()) {
    return 0;
  }
  river::window window{ window_opt.value() };
  window.show();

  // Run the message loop.
  river::message::run_loop();
}

auto river_callback window_procedure(river::window::window_handle_t hwnd, unsigned rmsg, river::wparameter wparam, river::lparameter lparam) -> river::result
{
  river::message_identifier msg(rmsg, hwnd);
  
  msg.on_destroy([](){
    river::message::post_quit();
    return 0;
  });
  msg.on_paint([](river::window win){
    river::device_context dc(win);
    dc.fill(dc.paint_rectangle(), river::color::window + 1);
    return 0;
  });
  return msg.dispatch(wparam, lparam);
}

