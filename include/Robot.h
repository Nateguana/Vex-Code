#pragma once
#include "vex.h"
#include <algorithm>
#include <cmath>
#include <iostream> //33 - 38
enum Ball {
  RED,
  BLUE,
  YELLOW,
};
static const char *BallColors[] = {"Red", "Blue", "Yellow"};

static motor *Motors[5] = {&LBM, &RBM, &LFM, &RFM, &SM};
static signature *Sigs[3] = {&Vision__RE, &Vision__BLU, &Vision__YELL};
static code *Code = &Vision__YG;
struct Turns {
  Turns(double turnBL, double turnBR, double turnFL, double turnFR,
        double turnS = 0) {
    turns[0] = turnBL;
    turns[1] = turnBR;
    turns[2] = turnFL;
    turns[3] = turnFR;
    turns[4] = turnS;
  }
  Turns &operator+=(const Turns &tick) {
    for (int j = 0; j < 5; j++)
      turns[j] += tick.turns[j];
    return *this;
  }
  Turns &operator-=(const Turns &tick) {
    for (int j = 0; j < 5; j++)
      turns[j] -= tick.turns[j];
    return *this;
  }
  Turns &operator*=(const Turns &tick) {
    for (int j = 0; j < 5; j++)
      turns[j] *= tick.turns[j];
    return *this;
  }
  Turns &operator*=(const double &d) {
    for (int j = 0; j < 5; j++)
      turns[j] *= d;
    return *this;
  }
  double turns[5];
};
class Robot {
  double track = 0;
  double gRatio = 0;
  double tRatio = 0;

public:
  Robot(double diameter = 10.5, double trackLength = 35, double gearRatio = 5);

  void Forward(double dist, double velocity = 360, bool blocking = 1);
  void Stop();

  void StrafeLeft(double dist, double velocity = 360, bool blocking = 1);
  void StrafeRight(double dist, double velocity = 360, bool blocking = 1);

  void TurnLeft(double angle, double velocity = 360, bool blocking = 1);
  void TurnRight(double angle, double velocity = 360, bool blocking = 1);

  // void Catch(bool blocking = 1);
  // void Uncatch(bool blocking = 1);

  // void TurnLeft1(double angle, double velocity = 360, bool blocking = 1);
  // void TurnRight1(double angle, double velocity = 360, bool blocking = 1);

  // void Control(double dist, double error, double velocity = 360);
  void Control(Turns &turns);
  void Move(Turns &turns, double velocity, bool blocking);

  void WaitForPress() {
    while (!Bumper.pressing()) {
      vex::task::sleep(10);
    }
    vex::task::sleep(500);
  }
};