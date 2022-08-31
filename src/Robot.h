#pragma once
#include "vex.h"
#include <cmath>

class Robot {
  double dim;

public:
  Robot(double dim,vex::distanceUnits du) {
this->dim=dim;
  }
  void PrintMotorRot(motor m) {
    while (1) {
      Brain.Screen.print(m.position(degrees));
      Brain.Screen.newLine();
      vex::task::sleep(1000);
    }
  }
  void ForwardBlock(double dist, double velocity = 360*2,
                    velocityUnits vu = dps) {
    //double turn = dist * 360 * 1800 / dim / M_PI;
    // dist=deg*dim* M_PI/360;
    // dist*180/rad/M_PI;=deg;


    double turn=dist*50;
    LeftM.spinFor(turn, deg, velocity, vu, 0);
    RightM.spinFor(turn, deg, velocity, vu);
  }
};