#include "mains.h"
#include "Control.h"
#include "Robot.h"
#include "RobotTest.h"
#include "SensorTest.h"
#include "vex.h"
#include <iostream>

int mains(int version) {
  vexcodeInit();
  Robot robot;
  RobotTest rTest(&robot);
  Control con(&robot);
  LeftM.setMaxTorque(10000,amp);
  RightM.setMaxTorque(10000,amp);
  std::cout << "Robot Version " << version << std::endl;
  //con.WallFollow(40,5,40*4,1/2.0,360);
  //con.LineFollow(150,5/1000.0,180);
  robot.Forward(100,360);
  return 0;
}