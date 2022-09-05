#pragma once
#include "Robot.h"
#include "vex.h"
#include <cmath>
#include <iostream>

class RobotTest {
  Robot *robot;

public:
  RobotTest(Robot *robot) : robot(robot) {}

  void DrawSquare() {
    for (int j = 0; j < 4; j++) {
      robot->Forward(50.8 / 4);
      robot->TurnLeft(90);
    }
  }
  void DrawStar() {
    for (int j = 0; j < 5; j++) {
      robot->Forward(50.8);
      robot->TurnLeft(180 - 36);
    }
  }

  void Draw6Square() {
    for (int j = 0; j < 6; j++) {
      DrawSquare();
    }
  }

  void DriveMaze() {
    robot->Forward(55);
    robot->TurnLeft1(90);
    robot->Forward(45);
    robot->TurnRight1(90);
    robot->Forward(21.5);
    robot->TurnRight1(90);
    robot->Forward(5);
  }

  void TurnTest() {
    robot->TurnLeft(90);
    robot->WaitForPress();
    robot->TurnRight(90);
    robot->WaitForPress();
    robot->TurnLeft1(90);
    robot->WaitForPress();
    robot->TurnRight1(90);
    robot->WaitForPress();
    robot->Forward(10);
  }
};