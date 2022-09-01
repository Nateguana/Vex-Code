#pragma once
#include "vex.h"
#include <cmath>
#include <iostream>
class RobotTest {
public:
  void PrintMotorRot(motor m) {
    while (1) {
      float distance = m.position(degrees);
      PrintAndWait(distance);
    }
  }
  void PrintSonar(sonar s) {
    while (1) {
      double distance = s.distance(distanceUnits::cm);
      PrintAndWait(distance);
    }
  }

private:
  template <typename T> void PrintAndWait(T distance) {
    std::cout << distance << std::endl;
    Brain.Screen.print(distance);
    Brain.Screen.newLine();
    vex::task::sleep(1000);
  }
};