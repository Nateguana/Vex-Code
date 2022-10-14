#include "vex.h"
#include <iostream>
#include <sstream>

// type of std::endl
typedef std::ostream &(*endl)(std::ostream &);

namespace {
class Serial2;
extern Serial2 *serial2;
} // namespace

/**
   a class for easier c++ like printing to both brain, console, and controller
*/
class Serial {
  friend Serial2;

private:
  bool printToBrain = true;
  bool printToComputer = true;
  bool printToController = false;
  controller *con = 0;
  unsigned flushMillis = 250;

  std::stringstream ss;

  unsigned long last = 0;
  unsigned long num = 0;

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
  /**
   Whether Serial should print to the screen on the brain
 */
  inline void PrintToBrain(bool b) { printToBrain = b; }

  /**
    Whether Serial should print to the screen on the controller
  */
  inline void PrintToController(bool b) { printToController = b; }

  /**
    Whether Serial should print to the computer
  */
  inline void PrintToComputer(bool b) { printToComputer = b; }
  /**
    Set the controller to print to
  */
  inline void SetController(controller *con) { this->con = con; }
  /**
    set the minimum interval to flush to computer
  */
  inline void FlushTime(unsigned millis) { flushMillis = millis; }

  /**
    Flush to computer if timer expired
  */
  void Update() {
    unsigned long now = Brain.timer(msec);
    if (printToComputer && now - last > flushMillis) {
      last = now;
      std::cout << ss.str() << std::flush;
      ss.str("");
    }
  }

  /**
   Block std::endl from being the first thing entered
 */
  void operator<<(endl) = delete;

  /**
    Print
    returns Serial2
  */
  template <typename T> Serial2 &operator<<(T val) {
    Add(val);
    Update();
    return *serial2;
  }
};
static Serial Serial;

namespace {
/**
  A hidden class to cause checking timer expired one per line
  unable to flush stream
*/
class Serial2 {
public:
  /**
    catches new line
    returns Serial2
  */
  Serial2 &operator<<(endl) {
    Serial.NewLine();
    return *this;
  }
  /**
    Print
    returns Serial2
  */
  template <typename T> Serial2 &operator<<(T val) {
    Serial.Add(val);
    return *this;
  }
};
static Serial2 s;
static Serial2 *serial2 = &s;
} // namespace