#pragma once
#include "vex.h"
#include <cmath>
#include <iostream>

class Robot {
  double track = 29;
  double gRatio = 5;
  double tRatio = 0;

public:
  Robot(double diameter = 10.5, double trackLength = 29, double gearRatio = 5);

  void Forward(double dist, double velocity = 360, bool blocking = 1);
  void Stop();

  void TurnLeft(double angle, double velocity = 360, bool blocking = 1);
  void TurnRight(double angle, double velocity = 360, bool blocking = 1);

  void TurnLeft1(double angle, double velocity = 360, bool blocking = 1);
  void TurnRight1(double angle, double velocity = 360, bool blocking = 1);

  void TurnLeftArc(double dist, double angle, double velocity = 360,
                   bool blocking = 1);
  void TurnRightArc(double dist, double angle, double velocity = 360,
                    bool blocking = 1);

  void TurnLeftArc1(double dist, double angle, double velocity = 360,
                   bool blocking = 1);

  void TurnRightArc1(double dist, double angle, double velocity = 360,
                    bool blocking = 1);

  void Control(double dist, double error, double velocity = 360);
  void Move(double turnL,double turnR,double velocity = 360, bool blocking=1);

  void StaticArm() {
    ArmM.setMaxTorque(.5, Nm);
    // ArmM.setStopping((-100000, deg, 360, dps);
    // ArmM.setPosition(0, deg);
    ArmM.spin(reverse, 120, rpm);
  }

  void WaitForPress() {
    while (!Bumper.pressing()) {
      vex::task::sleep(10);
    }
     vex::task::sleep(500);
  }

private:
  double GetTurn(double angle);
};