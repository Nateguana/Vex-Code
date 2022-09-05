#include "Robot.h"

// Robot::Robot(double diameter, double trackLength, double gearRatio)
//     : dim(diameter), track(trackLength), ratio(gearRatio) {
//   turnR = track / dim * ratio;
// }

Robot::Robot(double diameter, double trackLength, double gearRatio)
    : track(trackLength), ratio(gearRatio) {
  ratio = gearRatio / diameter;
  turnR = track*ratio;
}

void Robot::Forward(double dist, double velocity) {
  double turnDeg = dist * ratio * (360 / M_PI);
  std::cout << turnDeg << std::endl;
  LeftM.spinFor(turnDeg, deg, velocity, dps, 0);
  RightM.spinFor(turnDeg, deg, velocity, dps);
}

void Robot::TurnLeft(double angle, double velocity) {

  double turn = angle * turnR;
  std::cout << turn << std::endl;
  LeftM.spinFor(-turn, deg, velocity, dps, 0);
  RightM.spinFor(turn, deg, velocity, dps);
}

void Robot::TurnRight(double angle, double velocity) {
  TurnLeft(-angle, velocity);
}

void Robot::TurnLeft1(double angle, double velocity) {
  double turn = angle * turnR * 2;
  std::cout << turn << std::endl;
  RightM.spinFor(turn, deg, velocity, dps);
}

void Robot::TurnRight1(double angle, double velocity) {
  double turn = angle * turnR * 2;
  std::cout << turn << std::endl;
  LeftM.spinFor(turn, deg, velocity, dps);
}