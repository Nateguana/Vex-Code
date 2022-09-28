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
  // LeftM.setMaxTorque(10000, amp);
  // RightM.setMaxTorque(10000, amp);
  Serial.SetController(&Controller1);
  // std::cout << "Robot Version " << version << std::endl;
  Serial << "Robot Version " << version << std::endl;
  //Serial << "asd" << "asdf";// << std::endl;
  //Serial << std::endl;

  // con.WallFollow(40,5,40*4,1/2.0,36as0);
  // con.LineFollow(150,5/1000.0,180);
  //robot.Forward(100,360);
  //robot.StrafeLeft(10,360);
  //robot.StrafeRight(10,360);
  //Turns turns(1*360*5,0,0,0,0);
  //robot.Move(turns, 360, 1);
  //robot.TurnLeft(360*4);
  // robot.Catch();
  // robot.WaitForPress();
  // robot.Uncatch();
  //Motors[0]->spin(forward,-100,rpm);
 con.Teleop(0,180);
 //Turns turns (-100,-100,-100,-100,0);
 //robot.Control(turns);
  // SensorTest::DetectObject(Vision,Vision__BLU);
  //con.VisionStandoff(Vision__RE, 4 / 100.0, 5 / 1000.0, 180);
  //con.Teleop();
  return 0;
}