#include "vex.h"
#include <iostream>
#include <sstream>

typedef std::ostream &(*endl)(std::ostream &);

namespace {
class Serial2;
extern Serial2 *serial2;
} // namespace

class Serial {
  friend Serial2;

private:
  std::stringstream ss;
  unsigned long last = 0;
  bool brain = true;
  unsigned flushMillis = 250;
  template <typename T> void Add(T val) {
    ss << val;
    if (brain)
      Brain.Screen.print(val);
  }
  void NewLine() {
    ss << "\n";
    if (brain)
      Brain.Screen.newLine();
  }

public:
  void PrintToBrain(bool b) { brain = b; }
  void FlushTime(unsigned millis) { flushMillis = millis; }

  void operator<<(endl) = delete;

  template <typename T> Serial2 &operator<<(T val) {
    ss << val;
    unsigned long now = Brain.timer(sec);
    if (last - now > flushMillis) {
      last = now;
      std::cout << ss;
      ss.str("");
    }
    return *serial2;
  }
};
static Serial Serial;

namespace {
class Serial2 {
public:
  Serial2 &operator<<(endl) {
    Serial.NewLine();
    return *this;
  }
  template <typename T> Serial2 &operator<<(T val) { Serial.Add(val); }
};
static Serial2 s;
static Serial2 *serial2 = &s;
} // namespace