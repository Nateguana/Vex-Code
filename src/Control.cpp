#include "Control.h"
void Control::LineFollow(uint8_t cutoff, double k, double velocity) {
  // bool intersection = 0;
  while (1) {
    int32_t left = LineL.value(range8bit);
    int32_t right = LineR.value(range8bit);
    if (left > cutoff && right > cutoff) {
      break;
    }
    double error = right - left;
    LeftM.spin(forward, velocity + velocity * error * k, rpm);
    RightM.spin(forward, velocity - velocity * error * k, rpm);
  }
  robot->Stop();
  robot->TurnLeft(90);
}
void Control::Standoff(double cm, double k, double velocity) {
  while (1) {
    double dist = Sonar.distance(distanceUnits::cm);
    double error = dist - cm;

    LeftM.spin(forward, velocity * error * k, rpm);
    RightM.spin(forward, velocity * error * k, rpm);
  }
}
void Control::WallFollow(double cm, double range, double cutoff, double k,
                         double velocity) {
  // true = left
  bool dir = 1;
  bool first = 0;
  // double average = cm;
  while (1) {
    double dist = Sonar.distance(distanceUnits::cm);
    double error = cm - dist;
    // if (first && fabs(average - dist) > cutoff) {
    //   robot->TurnRight(45 * 7);
    //   robot->Forward(40);
    // }
    if ((error > 0) == dir) {
      dir = !dir;
      first = 1;
    }
    // average = dist / 10.0 + average * 9 / 10.0;

    // std::cout << "Dir: " << (dir?"left":"right") << std::endl;
    Brain.Screen.print("Dir: ");
    Brain.Screen.print(dir ? "left" : "right");
    Brain.Screen.print(" Dist: ");
    Brain.Screen.print(dist);
    Brain.Screen.newLine();
    LeftM.spin(forward, velocity + velocity * k * (dir * -2 + 1), rpm);
    RightM.spin(forward, velocity - velocity * k * (dir * -2 + 1), rpm);
  }
}

void Control::VisionStandoff(signature &s, double fk, double sk,
                             double velocity) {
  while (1) {
    Vision.takeSnapshot(s);
    double fError,sError;
    if(Vision.objectCount>0){
     fError = 30 - Vision.largestObject.width;

     //camra is left is 0, right is 320

     //left is negative, right is posative
     sError = Vision.largestObject.centerX - 320 / 2;

    }else{
      fError= sError=0;   
    }
    LeftM.spin(forward, velocity + (velocity * fError * fk)+(velocity * sError * sk), rpm);
    RightM.spin(forward, velocity + (velocity * fError * fk)-(velocity * sError * sk), rpm);
  }
}