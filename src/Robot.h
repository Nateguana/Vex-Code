#pragma once
#include "vex.h"
#include <cmath>
#include <iostream>

class Robot {
  double dim = 10.5;
  double track = 29;
  double gearRatio = 5;

public:
  // Robot() { this->dim = dim; }

  void Forward(double dist, double velocity = 360) {
    double turnDeg = dist * 360 * gearRatio / dim / M_PI;
    std::cout << turnDeg << std::endl;
    LeftM.spinFor(turnDeg, deg, velocity, dps, 0);
    RightM.spinFor(turnDeg, deg, velocity, dps);
  }
  void TurnLeft(double angle, double velocity = 360) {

    // Angle∆ = 2 * Diameter * θ / track
    // Angle∆*track/2 * Diameter = θ
    double turn = angle * track / dim * gearRatio;
    std::cout << turn << std::endl;
    LeftM.spinFor(-turn, deg, velocity, dps, 0);
    RightM.spinFor(turn, deg, velocity, dps);
  }

  void TurnRight(double angle, double velocity = 360) {
    TurnLeft(-angle, velocity);
  }
  void TurnLeft1(double angle, double velocity = 360) {
    double turn = angle * track / dim * gearRatio*2;
    std::cout << turn << std::endl;
    RightM.spinFor(turn, deg, velocity, dps);
  }
  
   void TurnRight1(double angle, double velocity = 360) {
    double turn = angle * track / dim * gearRatio*2;
    std::cout << turn << std::endl;
    LeftM.spinFor(turn, deg, velocity, dps);
  }

  void StaticArm() {
    ArmM.setMaxTorque(.5, Nm);
    // ArmM.setStopping((-100000, deg, 360, dps);
    //ArmM.setPosition(0, deg);
    ArmM.spin(reverse,120,rpm);
  }
  void WaitForPress(bumper b) {
    while (!b.pressing()) {
      vex::task::sleep(100);
    }
  }
};