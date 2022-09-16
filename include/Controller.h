#include "vex.h"
//#include <cstddef>
typedef controller::axis (*Axis)();

// template<typename T, typename U> constexpr size_t offsetOf(U T::*member)
// {
//     return (char*)&((T*)nullptr->*member) - (char*)nullptr;
// }

// template<typename T, typename U> constexpr size_t getFromOffset()
// {
//     return
// }

class Joy {
private:
  const controller::axis *x;
  const controller::axis *y;

public:
  constexpr Joy(const controller::axis *x, const controller::axis *y)
      : x(x), y(y) {}
  signed char X() { return x->value(); }
  signed char Y() { return y->value(); }
};

class Pad {
private:
  const controller::button *up;
  const controller::button *down;
  const controller::button *left;
  const controller::button *right;

public:
  constexpr Pad(const controller::button *up, const controller::button *down,
                const controller::button *left, const controller::button *right)
      : up(up), down(down), left(left), right(right) {}
  bool Up() { return up->pressing(); }
  bool Down() { return down->pressing(); }
  bool Left() { return left->pressing(); }
  bool Right() { return right->pressing(); }
};

class Trig {
private:
  const controller::button *near;
  const controller::button *far;

public:
  constexpr Trig(const controller::button *near, const controller::button *far)
      : near(near), far(far) {}
  bool Near() { return near->pressing(); }
  bool Far() { return far->pressing(); }
};

class Controller {
private:
public:
  static Joy joys[2];
  static Pad pads[2];
  static Trig trigs[2];
};