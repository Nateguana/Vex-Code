#pragma once
#include "Robot.h"

// constants
const uint16_t LineAtGound = 2800;
const uint16_t LineWhiteBound = 1700;
const double BaseSpeed = 180;
const double LineFollowK = .00025;
const double LineRampFollowK = .0005;
const double ParkSonarStopDist = 1000;
const uint32_t ParkTimeMillis = 10000;

const uint32_t LineBound = (LineAtGound + LineWhiteBound) / 2;

// states
enum State {
  // FIND_BALL,
  // GO_TO_BALL,
  // GOT_BALL,
  FIND_GAME_SIDE,
  FIND_LINE,
  TURN_TO_LINE,
  FOLLOW_LINE,
  RAMP_TURN,
  FOLLOW_RAMP_LINE,
  END,
};

/**
  A class for autonomous
*/
class Auto {
  Robot *robot;
  Ball ballState = RED;
  State state = FIND_LINE; // FIND_GAME_SIDE;
  bool leftGameSide = 0;

public:
  Auto(Robot *robot) : robot(robot) {}

  /**
   Contunally called for auto
  */
  void Tick();

  /**
   Find the game side and set the bool leftGameSide
  */
  void FindGameSide();

  /**
   Drive forward until the line is seen
  */
  void FindLine();

  /**
   Turn so the line sensors are on the line
  */
  void TurnToLine();

  /**
   Follow the line until an intersection is seen
  */
  void FollowLine();

  /**
   Turn onto the ramp so the line sensors are on the line going up the ramp
 */
  void RampTurn();

  /**
    Follow the line going up the ramp
  */
  void FollowRampLine();

  /**
    Would have spun around until a red or blue ball was spotted
  */
  [[deprecated]] void FindBall();

  /**
    Would have driven to the ball
  */
  [[deprecated]] void GoToBall();

  /**
     Abtracted line follow code
  */
  void Follow(double k, int16_t *left, int16_t *right);
};