#pragma once
#include "vex.h"
#include <cmath>
#include <iostream>

class Robot {
  double track = 29;
  double ratio = 5;
  double turnR=0;
public:
  Robot(double diameter=10.5, double trackLength=29, double gearRatio=5);

  void Forward(double dist, double velocity = 360);

  void TurnLeft(double angle, double velocity = 360);
  void TurnRight(double angle, double velocity = 360);

  void TurnLeft1(double angle, double velocity = 360);
  void TurnRight1(double angle, double velocity = 360);

  void StaticArm() {
    ArmM.setMaxTorque(.5, Nm);
    // ArmM.setStopping((-100000, deg, 360, dps);
    //ArmM.setPosition(0, deg);
    ArmM.spin(reverse,120,rpm);
  }

  void WaitForPress() {
    while (!Bumper.pressing()) {
      vex::task::sleep(100);
    }
  }
  private:
  double GetTurn(double angle);
};