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
  bool printToBrain = true;
  bool printToController = false;
  controller *con = 0;
  unsigned flushMillis = 250;

  std::stringstream ss;

  unsigned long last = 0;

  template <typename T> void Add(T val) {
    ss << val;
    if (printToBrain)
      Brain.Screen.print(val);
    if (printToController && con)
      con->Screen.print(val);
  }
  
  void NewLine() {
    ss << "\n";
    if (printToBrain)
      Brain.Screen.newLine();
    if (printToController && con)
      con->Screen.newLine();
  }

public:
  void PrintToBrain(bool b) { printToBrain = b; }
  void PrintToContorller(bool b) { printToController = b; }
  void SetController(controller *con) { this->con = con; }
  void FlushTime(unsigned millis) { flushMillis = millis; }

  void Update() {
    unsigned long now = Brain.timer(sec);
    if (last - now > flushMillis) {
      last = now;
      std::cout << ss;
      ss.str("");
    }
  }

  //void operator<<(endl) = delete;

  template <typename T> Serial2 &operator<<(T val) {
    Add(val);
    Update();
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