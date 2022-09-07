#include "Robot.h"

// Robot::Robot(double diameter, double trackLength, double gearRatio)
//     : dim(diameter), track(trackLength), ratio(gearRatio) {
//   turnR = track / dim * ratio;
// }

Robot::Robot(double diameter, double trackLength, double gearRatio)
    : track(trackLength) {
  gRatio = gearRatio / diameter;
  tRatio = track * gRatio;
}

void Robot::Forward(double dist, double velocity, bool blocking) {
  double turn = dist * gRatio * (360 / M_PI);
  Move(turn, turn, velocity, blocking);
}

void Robot::TurnLeft(double angle, double velocity, bool blocking) {

  double turn = angle * tRatio;
  Move(-turn, turn, velocity, blocking);
}

void Robot::TurnRight(double angle, double velocity, bool blocking) {
  TurnLeft(-angle, velocity, blocking);
}

void Robot::TurnLeft1(double angle, double velocity, bool blocking) {
  double turn = angle * tRatio * 2;
  Move(0, turn, velocity, blocking);
}

void Robot::TurnRight1(double angle, double velocity, bool blocking) {
  double turn = angle * tRatio * 2;
  Move(turn, 0, velocity, blocking);
}

void Robot::TurnLeftArc(double dist, double angle, double velocity,
                        bool blocking) {
  double turnD = dist * gRatio * (360 / M_PI);
  double turnA = angle * tRatio;
  Move(turnD - turnA, turnD + turnA, velocity, blocking);
}

void Robot::TurnRightArc(double dist, double angle, double velocity,
                         bool blocking) {
  TurnLeftArc(dist, -angle, velocity, blocking);
}

void Robot::TurnLeftArc1(double dist, double angle, double velocity,
                         bool blocking) {
  double turnD = dist * gRatio * (360 / M_PI);
  double turnA = angle * tRatio * 2;
  Move(turnD, turnD + turnA, velocity, blocking);
}

void Robot::TurnRightArc1(double dist, double angle, double velocity,
                          bool blocking) {
  double turnD = dist * gRatio * (360 / M_PI);
  double turnA = angle * tRatio * 2;
  Move(turnD + turnA, turnD, velocity, blocking);
}

void Robot::Stop() { Move(0, 0, 0, 0); }

// void Robot::Control(double error, double velocity=360) {

//   // double err = std::fmax(std::fmin(error, 1), -1);
//   // double turn = dist * gRatio * (360 / M_PI);
//   // double lTurn = turn * fmin(1 - err, 1);
//   // double rTurn = turn * fmin(err + 1, 1);

//   // Move(lTurn, rTurn, velocity, 0);
// LeftM.spin(forward,360,rpm);
// RightM.spin(forward,360,rpm);
// }

void Robot::Move(double turnL, double turnR, double velocity, bool blocking) {
  double lVel = velocity;
  double rVel = lVel;
  double percent = fabs(turnL / turnR);
  bool lBlock = 0;
  bool rBlock = blocking;

  // if Right wheel does not turn then block left;
  if (!turnR) {
    lBlock = blocking;
    rBlock = 0;
  }

  // make percent less than 1
  if (percent > 1)
    percent = 1 / percent;
  if (std::isnan(percent));
  else if (turnR > turnL) {
    lVel *= percent;
  } else {
    rVel *= percent;
  }

  // print
  std::cout << "Left: " << turnL << " at " << lVel << " "
            << (lBlock ? "" : "non-") << "blocking " << std::endl;
  std::cout << "Right: " << turnR << " at " << rVel << " "
            << (rBlock ? "" : "non-") << "blocking " << std::endl;

  // spin
  LeftM.spinFor(turnL, deg, lVel, dps, lBlock);
  RightM.spinFor(turnR, deg, rVel, dps, rBlock);
  
  // stop motors cause vex stuupid
  if (!turnL) {
    LeftM.stop();
  }
  if (!turnR) {
    RightM.stop();
  }
}

