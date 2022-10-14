#pragma once
#include "vex.h"
#include <algorithm>
#include <cmath>
#include <iostream>

// global constants
enum Ball {
  RED,
  BLUE,
  YELLOW,
};

static const char *BallColors[] = {"Red", "Blue", "Yellow"};

static motor *Motors[5] = {&LBM, &RBM, &LFM, &RFM, &SM};
static signature *Sigs[3] = {&Vision__RE, &Vision__BLU, &Vision__YELL};
static code *Code = &Vision__YG;

/**
  A struct used for Robot::Move() and Robot::Control()
  Holds an array of length 5, one for each of the 4 actual motors
  and 1 for the center wheel (Side wheel) which never was connected to the robot.
*/
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

/**
  A class which abstacts the robot motors
*/
class Robot {
  double track = 0;
  double gRatio = 0;
  double tRatio = 0;

public:
  /**
    The contructor with robot dimensions
  */
  Robot(double diameter = 10.5, double trackLength = 35, double gearRatio = 5);

  /**
    Move robot forward a distance in cm at a certain robot velocity with optional blocking
  */
  void Forward(double dist, double velocity = 360, bool blocking = 1);

  /**
    Stop all robot motors
  */
  void Stop();

  /**
    If the center wheel existed this would move the robot left a distance in cm at a certain velocity with optional blocking
  */
  [[deprecated]] void StrafeLeft(double dist, double velocity = 360, bool blocking = 1);

  /**
    If the center wheel existed this would move the robot right a distance in cm at a certain velocity with optional blocking
  */
  [[deprecated]] void StrafeRight(double dist, double velocity = 360, bool blocking = 1);

  /**
    Turns the robot left by an angle in degrees at a certain velocity with optional blocking
  */
  void TurnLeft(double angle, double velocity = 360, bool blocking = 1);

  /**
    Turns the robot right by an angle in degrees at a certain velocity with optional blocking
  */
  void TurnRight(double angle, double velocity = 360, bool blocking = 1);

  /**
    Set the rpm for all motors with a turns refrence
  */
  void Control(Turns &turns);

  /**
    Sets the distance each motor should move in degrees
    If the distance of a motor is 0 it is stopped
    The motors speeds are set so motors stop turning at the same time
  */
  void Move(Turns &turns, double velocity, bool blocking);


  /**
    Blocks until the button is pressed
  */
  void WaitForPress();
};