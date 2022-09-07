#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor ArmM = motor(PORT11, ratio18_1, false);
motor LeftM = motor(PORT1, ratio18_1, true);
motor RightM = motor(PORT10, ratio18_1, false);
sonar Sonar = sonar(Brain.ThreeWirePort.A);
bumper Bumper = bumper(Brain.ThreeWirePort.C);
line LineL = line(Brain.ThreeWirePort.D);
line LineR = line(Brain.ThreeWirePort.E);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}