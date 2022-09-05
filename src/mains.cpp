#include "mains.h"
#include "Robot.h"
#include "RobotTest.h"
#include "SensorTest.h"
#include "vex.h"
#include <iostream>
int mains(int version) {
  vexcodeInit();
  Robot robot;
  RobotTest rTest(&robot);

  std::cout << "Robot Version " << version << std::endl;
  Brain.Screen.print("Hello, World!");
  Brain.Screen.newLine();
  // std::cout << "Hello, World!" << std::endl;
  // robot.StaticArm();
  // rTest.Draw6Square();

  return 0;
}