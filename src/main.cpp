// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ArmM                 motor         11              
// LeftM                motor         1               
// RightM               motor         10              
// Sonar                sonar         A, B            
// Bumper               bumper        C               
// Line                 line          D               
// Vision               vision        2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#define VERSION 17
#include "mains.h"
int main() {
  return mains(VERSION);
}