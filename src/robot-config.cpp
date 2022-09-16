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
/*vex-vision-config:begin*/
signature Vision__YELL = signature (1, 1643, 2325, 1984, -3605, -3203, -3404, 2.5, 0);
signature Vision__BLU = signature (2, -1237, -745, -991, 5405, 7143, 6274, 2.5, 0);
signature Vision__RE = signature (3, 7163, 8427, 7795, -481, -181, -331, 4.8, 0);
vision Vision = vision (PORT2, 50, Vision__YELL, Vision__BLU, Vision__RE);
/*vex-vision-config:end*/
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}