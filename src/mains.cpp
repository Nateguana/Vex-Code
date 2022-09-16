#include "mains.h"
#include "Control.h"
#include "Robot.h"
#include "RobotTest.h"
#include "SensorTest.h"
#include "Serial.h"
#include "vex.h"
#include <iostream>


int mains(int version) {
  vexcodeInit();
  Robot robot;
  RobotTest rTest(&robot);
  Control con(&robot);
  LeftM.setMaxTorque(10000, amp);
  RightM.setMaxTorque(10000, amp);
  // std::cout << "Robot Version " << version << std::endl;
  Serial << "Robot Version " << version << std::endl;
  //Serial << "asd" << "asdf";// << std::endl;
  //Serial << std::endl;

  // con.LineFollow(150,5/1000.0,180);
  // robot.Forward(100,360);
  // SensorTest::DetectObject(Vision,Vision__BLU);
  //con.VisionStandoff(Vision__RE, 1 / 100.0, 1 / 1000.0, 180);
  return 0;
}