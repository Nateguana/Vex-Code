#pragma once
#include "vex.h"
#include <cmath>
#include <iostream>

class Robot {
  //double dim;

public:
  //Robot() { this->dim = dim; }

   void ForwardBlock(double dist, double velocity = 360 * 2,
                    velocityUnits vu = dps) {
    double turn = dist * 50;
    LeftM.spinFor(turn, deg, velocity, vu, 0);
    RightM.spinFor(turn, deg, velocity, vu);
  }
};