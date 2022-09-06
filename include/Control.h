#pragma once
#include "Robot.h"
#include "vex.h"
#include <cmath>
#include <iostream>
class Control {
  Robot *robot;

public:
  Control (Robot *robot) : robot(robot) {}
};