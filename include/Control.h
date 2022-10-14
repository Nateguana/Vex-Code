#pragma once
#include "Robot.h"
#include "vex.h"
#include <cmath>
#include <iostream>

/**
    A class for lab 2
*/
class Control {
  Robot *robot;

public:
  /**
    Control contructor
  */
  Control(Robot *robot) : robot(robot) {}

  /**
   Run Teleop with a kp and and base robot speed in motor rpm
   Does not return
 */
  void Teleop(double k, double velocity);

  // void LineFollow(uint8_t cutoff = 170, double k = 0.1, double velocity =
  // 90); void Standoff(double cm, double k, double velocity = 180); void
  // WallFollow(double cm, double range, double cutoff, double k,
  //                 double velocity = 180);
  // void VisionStandoff(signature &s, double fk, double sk, double velocity);
};