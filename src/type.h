#ifndef RIVER_TYPE_H
#define RIVER_TYPE_H

#define river_callback __stdcall

#include <Windows.h>

namespace river {
using result = LRESULT;
using wparameter = WPARAM;
using lparameter = LPARAM;
using rectangle = RECT;
}

#endif // RIVER_TYPE_H
