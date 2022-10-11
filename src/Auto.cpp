#include "Auto.h"
#include "Serial.h"
State lastState = END;
void Auto::Tick() {
  Serial.Update();
  switch (state) {
  case FIND_GAME_SIDE:
    FindGameSide();
    break;
  case FIND_LINE:
    FindLine();
    break;
  case TURN_TO_LINE:
    TurnToLine();
    break;
  case FOLLOW_LINE:
    FollowLine();
    break;
  case RAMP_TURN:
    RampTurn();
    break;
  case FOLLOW_RAMP_LINE:
    FollowRampLine();
    break;
  case END:
    robot->Stop();
    break;
  }
  if (lastState != state) {
    Serial << "Going from " << lastState << " To " << state << std::endl;
    lastState = state;
  }
}

void Auto::FindGameSide() {
  robot->Forward(10, BaseSpeed * 4);
  robot->TurnRight(90, BaseSpeed * 4);
  double leftDist = Sonar.distance(distanceUnits::cm);
  robot->TurnLeft(180, BaseSpeed * 4);
  double rightDist = Sonar.distance(distanceUnits::cm);
  robot->TurnRight(90, BaseSpeed * 4);
  leftGameSide = leftDist < rightDist;
  state = FIND_LINE;
}

void Auto::FindLine() {
  Turns turns(1, 1, 1, 1);
  turns *= BaseSpeed / 2;
  robot->Control(turns);
  uint32_t val = LineL.value(range12bit) + LineR.value(range12bit);
  Serial << LineL.value(range12bit) << " " << LineR.value(range12bit) << " "
         << LineBound * 2 << std::endl;
  // 2800*2<
  if (val && val < LineBound * 2) {
    state = TURN_TO_LINE;
  }
  // vex::task::sleep(100);
  // Brain.Screen.newLine();
}

void Auto::TurnToLine() {
  // robot->Forward(10);
  robot->TurnRight(90 * (leftGameSide * 2 - 1));
  state = FOLLOW_LINE;
}

void Auto::FollowLine() {
  int16_t left;
  int16_t right;
  Follow(LineFollowK, &left, &right);
  if (left < LineWhiteBound && right < LineWhiteBound) {
    state = RAMP_TURN;
  }
}
// robot->Stop();
// robot->TurnLeft(90);
int32_t startTime = 0;
void Auto::RampTurn() {
  robot->Forward(-5);
  robot->TurnLeft(90 * (leftGameSide * -2 + 1));
  state = FOLLOW_RAMP_LINE;
  startTime = Brain.timer(msec);
}
void Auto::FollowRampLine() {
  int16_t left;
  int16_t right;
  Follow(LineRampFollowK, &left, &right);
  Serial << left << " " << right << " " << (right - left) * LineRampFollowK
         << std::endl;
  int16_t now = Brain.timer(msec);
  if (now - startTime > ParkTimeMillis)
    // if (Sonar.distance(distanceUnits::cm) < ParkSonarStopDist) {
    state = END;
  // }
}

void Auto::FindBall() {
  vision::object found[2];
  Ball nextB = RED;
  bool best = 0;
  bool foundAny = 1;
  int r[2];
  for (int j = 0; j < 2; j++) {
    Vision.takeSnapshot(*Sigs[j]);
    found[j] = Vision.largestObject;
    r[j] = Vision.objectCount;
  }
  Serial << found[0].exists << " " << r[0] << " " << found[1].exists << " "
         << r[1] << std::endl;
  if (!found[0].exists && !found[1].exists) {
    foundAny = 0;
  } else if ((!found[0].exists && found[1].exists) ||
             (found[0].exists && found[1].exists &&
              found[1].width > found[0].width)) {
    nextB = BLUE;
    best = 1;
  }

  if (foundAny) {
    // state = GO_TO_BALL;
    Serial << "Found " << BallColors[nextB] << " Ball";
    ballState = nextB;
    robot->Stop();
  } else {
    Turns turns(1, -1, 1, -1);
    // turns *= FindBallTurnSpeed;
    robot->Control(turns);
  }
}
void Auto::GoToBall() {
  Vision.takeSnapshot(*Sigs[ballState]);
  vision::object found = Vision.largestObject;
  if (!found.exists) {
    Serial << "Lost " << BallColors[ballState] << " Ball";
    // state = FIND_BALL;
  }
}

void Auto::Follow(double k, int16_t *left, int16_t *right) {
  *left = LineL.value(range12bit);
  *right = LineR.value(range12bit);
  double effort = (*right - *left) * k;

  Turns turns(-1 + effort, -1 - effort, -1 + effort, -1 - effort);
  turns *= BaseSpeed;
  robot->Control(turns);
}