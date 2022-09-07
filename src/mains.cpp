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
  // SensorTest::PrintLine(LineR);
  //robot.Forward(10);
  //double d = .1;
  //rTest.ControlTest();
  // while(100){

  //    LeftM.spin(forward,100,pm);
  //    RightM.spin(forward,100,rpm);
  // }
  con.WallFollow(40,1/10.0,90);
  //con.LineFollow(150,5/1000.0,480);
  // while (1) {
  //   std::cout << "K=" << d << std::endl;
  //   robot.WaitForPress();
  //   con.Standoff(150, d);
  //   d /= 10;
  // }
  // Brain.Screen.print("Hello, World!");
  // Brain.Screen.newLine();

  // rTest.MoveTest();
  // rTest.ControlTest();
  // robot.WaitForPress();
  // robot.Control(10,1);
  //  robot.WaitForPress();
  //  robot.Control(10,0);
  //  robot.WaitForPress();
  //  robot.Control(10,-1);

  // Speaker.set(false);
  // std::cout << "Hello, World!" << std::endl;
  // robot.StaticArm();
  // rTest.Draw6Square();
  // Line.reflectivity();
  return 0;
}