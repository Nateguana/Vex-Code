/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Nateg                                            */
/*    Created:      Mon Aug 29 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ArmM                 motor         11
// LeftM                motor         1
// RightM               motor         10
// ---- END VEXCODE CONFIGURED DEVICES ----
#define dist(a) vex::distanceUnits::cm

#include "Robot.h"
#include "vex.h"
#include <iostream>

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  Robot robot(10.5, dist(cm));
  vexcodeInit();
  Brain.Screen.print("Hello, World!");
  Brain.Screen.newLine();
  robot.ForwardBlock(12);
  // vex::task::sleep(1000);
  // obot.ForwardBlock(-2);
  // robot.PrintMotorRot(LeftM);
  // vex::task::sleep(250);
  // motor motor_name = ArmM;
  // std::cout << "Starting at: " << motor_name.rotation(deg) << std::endl;
  // motor_name.rotateTo(1200, deg, 1000000, dps);
  // std::cout << "Finished at: " << motor_name.rotation(deg) << std::endl;
  // dist(cm);
  // LeftM.rotateTo(360, deg, 180, dps,0);
  // RightM.rotateTo(360, deg, 180, dps);
  // LeftM.spinFor(5000, deg, 360, dps, 0);
  // RightM.spinFor(5000, deg, 360, dps);
  // vex::task::sleep(1000);

  robot.ForwardBlock(100000000);
  while (LeftM.isSpinning()) {
    std::cout << LeftM.velocity(rpm) << '\t' << LeftM.power(watt) << std::endl;
    task::sleep(100);
  }
}
