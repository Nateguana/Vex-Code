#pragma once
#include "vex.h"
#include <cmath>
#include <iostream>

class SensorTest {

public:

  static void PrintMotorRot(motor m, unsigned num = ~0) {
    for (unsigned j = 0; j < num; j++) {
      PrintAndWait(m.position(degrees));
    }
  }

   static void PrintSonar(sonar s,  unsigned num = ~0) {
    vex::task::sleep(100);
    for (unsigned j = 0; j < num; j++) {
      PrintAndWait(s.distance(distanceUnits::cm));
    }
  }

   static void PrintBumber(bumper b,  unsigned num = ~0) {
    for (unsigned j = 0; j < num; j++) {
      PrintAndWait(b.pressing());
    }
  }
  
  static void PrintLine(line l,  unsigned num = ~0) {
    for (unsigned j = 0; j < num; j++) {
      PrintAndWait(l.value(range8bit));
    }
  }

  
private:
  template <typename T> static void PrintAndWait(T distance) {
    std::cout << distance << std::endl;
    Brain.Screen.print(distance);
    Brain.Screen.newLine();
    vex::task::sleep(100);
  }
};