#pragma once
#include "vex.h"
#include <cmath>
#include <iostream>
class RobotTest {
public:
  void PrintMotorRot(motor m) {
    while (1) {
      PrintAndWait(m.position(degrees));
    }
  }
  
  void PrintSonar(sonar s) {
    while (1) {
      PrintAndWait(s.distance(distanceUnits::cm));
    }
  }
  
  void PrintBumber(bumper b) {
    while (1) {
      PrintAndWait(b.pressing());
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