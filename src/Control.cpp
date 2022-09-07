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
void Control::Standoff(double cm,double k, double velocity) {
  while (1) {
    double dist =  Sonar.distance(distanceUnits::cm);
    double error = dist-cm;

    LeftM.spin(forward, velocity * error * k, rpm);
    RightM.spin(forward, velocity * error * k, rpm);
  } 
}
void  Control::WallFollow(double cm,double k, double velocity) {
  while (1) {
    double dist =  Sonar.distance(distanceUnits::cm);
    double error = dist-cm;

    LeftM.spin(forward, velocity+velocity * error * k, rpm);
    RightM.spin(forward, velocity-velocity * error * k, rpm);
  } 
}