#include "mains.h"
#include "Auto.h"
#include "Control.h"
#include "Robot.h"
#include "RobotTest.h"
#include "SensorTest.h"
#include "Serial.h"
#include "vex.h"
#include "Controller.h"
#include <iostream>

int mains(int version) {
  vexcodeInit();
  Robot robot;
  Control con(&robot);
  // Serial.SetController(&Controller1);
  //std::cout << "Robot Version " << version << std::endl;
  Serial << "Robot Version " << version << std::endl;


  Auto au(&robot);
  while (!Controller::pads[0].Down()) {
    au.Tick();
  }
  con.Teleop(0,180);
  return 0;
}