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

  void MoveTest() {
    for (char block = 1; block >= 0; block--) {
      robot->WaitForPress();
      robot->Move(5 * 360, 5 * 360 / 2, 360, block);

      robot->WaitForPress();
      robot->Forward(10, 360, block);
      robot->WaitForPress();
      robot->Stop();

      robot->WaitForPress();
      robot->TurnLeft(90, 360, block);
      robot->WaitForPress();
      robot->TurnRight(90, 360, block);

      robot->WaitForPress();
      robot->TurnLeft1(90, 360, block);
      robot->WaitForPress();
      robot->TurnRight1(90, 360, block);

      // robot->WaitForPress();
      // robot->TurnLeftArc(10, 90, 360, block);
      // robot->WaitForPress();
      // robot->TurnRightArc(10, 90, 360, block);

      // robot->WaitForPress();
      // robot->TurnLeftArc1(10, 90, 360, block);
      // robot->WaitForPress();
      // robot->TurnRightArc1(10, 90, 360, block);
    }
  }
  void ControlTest() {
    robot->WaitForPress();
    for (unsigned j = 0; j < 4; j++) {
      robot->Forward(10,180,0);
      vex::task::sleep(1000);
       robot->Forward(10,360,0);
      vex::task::sleep(1000);
    }
    robot->WaitForPress();
    for (unsigned j = 0; j < 4; j++) {
      robot->Forward(10,360,0);
      vex::task::sleep(1000);
       robot->Stop();
      vex::task::sleep(1000);
    }
    robot->WaitForPress();
    for (unsigned j = 0; j < 4; j++) {
      robot->TurnLeft1(90, 360, 0);
      vex::task::sleep(1000);
      robot->TurnRight1(90, 360, 0);
      vex::task::sleep(1000);
    }
    robot->Stop();
  }
};
