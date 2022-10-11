#pragma once
#include "Robot.h"

// const double CloseEnoughToBallToTurnAround = 10;
// const double FindBallTurnSpeed = 180;
const uint16_t LineAtGound=2800;//170
const uint16_t LineWhiteBound=1700;//900
const double BaseSpeed=180;
const double LineFollowK=.00025;
const double LineRampFollowK=.0005;
const double ParkSonarStopDist=1000;
const uint32_t ParkTimeMillis=10000;

const uint32_t LineBound=(LineAtGound+LineWhiteBound)/2;
//line lower bound 170
//upper 900 
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
class Auto {
  Robot *robot;
  Ball ballState = RED;
  State state = FIND_LINE;//FIND_GAME_SIDE;
  bool leftGameSide=0;

public:
  Auto(Robot *robot) : robot(robot) {}

  void Tick();

  void FindGameSide();
  void FindLine();
  void TurnToLine();
  void FollowLine();
  void RampTurn();
  void FollowRampLine();

  void FindBall();
  void GoToBall();



  void Follow(double k,int16_t* left,int16_t * right);
};