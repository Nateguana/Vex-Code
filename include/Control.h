#pragma once
#include "Robot.h"
#include "vex.h"
#include <cmath>
#include <iostream>
class Control {
  Robot *robot;
public:
  Control (Robot* robot) : robot(robot) {}
  void LineFollow(uint8_t cutoff=170,double k=0.1,double velocity=90);
void Standoff(double cm,double k, double velocity=180);
void WallFollow(double cm,double range,double cutoff, double k, double velocity=180);
};