#pragma once
#include "Robot.h"
#include "vex.h"
#include <cmath>
#include <iostream>

class RobotTest {
  Robot *robot;

public:
  RobotTest(Robot *robot) : robot(robot) {}
  void PrintMotorRot(motor m, int num = 999999) {
    for (int j = 0; j < num; j++) {
      PrintAndWait(m.position(degrees));
    }
  }

  void PrintSonar(sonar s, int num = 999999) {
    vex::task::sleep(100);
    for (int j = 0; j < num; j++) {
      PrintAndWait(s.distance(distanceUnits::cm));
    }
  }

  void DrawSquare() {
    for (int j = 0; j < 4; j++) {
      robot->Forward(50.8/4);
      robot->TurnLeft(90);
    }
  }
  void DrawStar() {
    for (int j = 0; j < 5; j++) {
      robot->Forward(50.8);
      robot->TurnLeft(180-36);
    }
  }
void Draw6Square() {
    for (int j = 0; j < 6; j++) {
      DrawSquare();
    }
  }
  void PrintBumber(bumper b, int num = 999999) {
    for (int j = 0; j < num; j++) {
      PrintAndWait(b.pressing());
    }
  }

private:
  template <typename T> void PrintAndWait(T distance) {
    std::cout << distance << std::endl;
    Brain.Screen.print(distance);
    Brain.Screen.newLine();
    vex::task::sleep(100);
  }
};