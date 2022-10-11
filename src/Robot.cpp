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
  Turns turns(turn, turn, turn, turn, 0);
  Move(turns, velocity, blocking);
}

void Robot::StrafeLeft(double dist, double velocity, bool blocking) {
  double turn = dist * gRatio * (360 / M_PI);
  Turns turns(0, 0, 0, 0, turn);
  Move(turns, velocity, blocking);
}
void Robot::StrafeRight(double dist, double velocity, bool blocking) {
  Robot::StrafeLeft(-dist, velocity, blocking);
}

void Robot::TurnLeft(double angle, double velocity, bool blocking) {

  double turn = angle * tRatio;
  Turns turns(turn, -turn, turn, -turn, 0);
  // Move(-turn, turn, velocity, blocking);
  Move(turns, velocity, blocking);
}

void Robot::TurnRight(double angle, double velocity, bool blocking) {
  TurnLeft(-angle, velocity, blocking);
}

// void Robot::Catch(bool blocking) {

//   CRM.spin(forward, 360, rpm);
//   CLM.spin(forward, 360, rpm);
// }

// void Robot::Uncatch(bool blocking) {
//   CRM.spin(reverse, 360, rpm);
//   CLM.spin(reverse, 360, rpm);
// }

// void Robot::TurnLeft1(double angle, double velocity, bool blocking) {
//   double turn = angle * tRatio * 2;
//   Move(0, turn, velocity, blocking);
// }

// void Robot::TurnRight1(double angle, double velocity, bool blocking) {
//   double turn = angle * tRatio * 2;
//   Move(turn, 0, velocity, blocking);
// }

// void Robot::TurnLeftArc(double dist, double angle, double velocity,
//                         bool blocking) {
//   double turnD = dist * gRatio * (360 / M_PI);
//   double turnA = angle * tRatio;
//   Move(turnD - turnA, turnD + turnA, velocity, blocking);
// }

// void Robot::TurnRightArc(double dist, double angle, double velocity,
//                          bool blocking) {
//   TurnLeftArc(dist, -angle, velocity, blocking);
// }

// void Robot::TurnLeftArc1(double dist, double angle, double velocity,
//                          bool blocking) {
//   double turnD = dist * gRatio * (360 / M_PI);
//   double turnA = angle * tRatio * 2;
//   Move(turnD, turnD + turnA, velocity, blocking);
// }

// void Robot::TurnRightArc1(double dist, double angle, double velocity,
//                           bool blocking) {
//   double turnD = dist * gRatio * (360 / M_PI);
//   double turnA = angle * tRatio * 2;
//   Move(turnD + turnA, turnD, velocity, blocking);
// }

void Robot::Stop() {
  for (unsigned char j = 0; j < 5; j++)
    Motors[j]->stop();
}

void Robot::Control(Turns &turns) {
   for (unsigned char j = 0; j < 5; j++) {
    Motors[j]->spin(forward,turns.turns[j],rpm);
  }
}

void Robot::Move(Turns &turns, double velocity, bool blocking) {
  double maxTurn = fabs(turns.turns[0]);
  for (unsigned char j = 0; j < 5; j++)
    std::cout << "Turn[" << (int)j << "] = " << turns.turns[j] << std::endl;

  for (unsigned char j = 1; j < 5; j++) {
    maxTurn = fmax(maxTurn, fabs(turns.turns[j]));
  }
  double vel = velocity / maxTurn;
  std::cout << "vel:" << vel << " maxTurn:" << maxTurn << std::endl;
  // print
  // std::cout << "Left: " << turnL << " at " << lVel << " "
  //           << (lBlock ? "" : "non-") << "blocking " << std::endl;
  // std::cout << "Right: " << turnR << " at " << rVel << " "
  //           << (rBlock ? "" : "non-") << "blocking " << std::endl;

  // /bool  = turnBL || turnBR || turnFL || turnFR;
  char blockIndex = 4;
  for (; blockIndex >= 0 && !turns.turns[(unsigned)blockIndex]; blockIndex--)
    ;
  std::cout << "block:" << (int)blockIndex << std::endl;

  // spin
  for (unsigned char j = 0; j < 5; j++) {
    Motors[j]->spinFor(turns.turns[j], deg, turns.turns[j] * vel, dps,
                       j == blockIndex);
    if (!turns.turns[j])
      Motors[j]->stop();
  }
}

// void Robot::Move(double turnL, double turnR, double velocity, bool
// blocking)
// {
//   double lVel = velocity;
//   double rVel = lVel;
//   double percent = fabs(turnL / turnR);
//   bool lBlock = 0;
//   bool rBlock = blocking;

//   // if Right wheel does not turn then block left;
//   if (!turnR) {
//     lBlock = blocking;
//     rBlock = 0;
//   }

//   // make percent less than 1
//   if (percent > 1)
//     percent = 1 / percent;
//   if (std::isnan(percent));
//   else if (turnR > turnL) {
//     lVel *= percent;
//   } else {
//     rVel *= percent;
//   }

//   // print
//   std::cout << "Left: " << turnL << " at " << lVel << " "
//             << (lBlock ? "" : "non-") << "blocking " << std::endl;
//   std::cout << "Right: " << turnR << " at " << rVel << " "
//             << (rBlock ? "" : "non-") << "blocking " << std::endl;

//   // spin
//   LeftM.spinFor(turnL, deg, lVel, dps, lBlock);
//   RightM.spinFor(turnR, deg, rVel, dps, rBlock);

//   // stop motors cause vex stuupid
//   if (!turnL) {
//     LeftM.stop();
//   }
//   if (!turnR) {
//     RightM.stop();
//   }
// }