#include "mains.h"
#include "Robot.h"
#include "Test.h"
#include "vex.h"
#include <iostream>
int mains(int version) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Robot robot;//(10.5);
  RobotTest rTest(&robot);
  std::cout << "Robot Version " <<version<< std::endl; 
  Brain.Screen.print("Hello, World!");
  Brain.Screen.newLine();
  //std::cout << "Hello, World!" << std::endl;
  //robot.StaticArm();
  //rTest.Draw6Square();

  robot.Forward(55);
  robot.TurnLeft1(90);
  robot.Forward(45);
  robot.TurnRight1(90);
  robot.Forward(40-18.5);
  robot.TurnRight1(90);
  robot.Forward(5);

  return 0;
}