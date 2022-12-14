#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LBM = motor(PORT7, ratio18_1, true);
motor RBM = motor(PORT20, ratio18_1, false);
sonar Sonar = sonar(Brain.ThreeWirePort.A);
bumper BallBumper = bumper(Brain.ThreeWirePort.F);
line LineL = line(Brain.ThreeWirePort.D);
line LineR = line(Brain.ThreeWirePort.E);
/*vex-vision-config:begin*/
signature Vision__YELL = signature (1, 1643, 2325, 1984, -3605, -3203, -3404, 2.5, 1);
signature Vision__BLU = signature (2, -1237, -745, -991, 5405, 7143, 6274, 2.5, 1);
signature Vision__RE = signature (3, 7163, 8427, 7795, -481, -181, -331, 4.8, 0);
code Vision__YG = code (Vision__YELL, Vision__BLU );
vision Vision = vision (PORT2, 50, Vision__YELL, Vision__BLU, Vision__RE);
/*vex-vision-config:end*/
controller Controller1 = controller(primary);
motor RFM = motor(PORT3, ratio18_1, false);
motor LFM = motor(PORT1, ratio18_1, true);
digital_out DigitalOutH = digital_out(Brain.ThreeWirePort.H);
motor SM = motor(PORT5, ratio18_1, false);
motor ConveyM = motor(PORT9, ratio18_1, true);
motor BrushM = motor(PORT8, ratio18_1, true);
bumper Bumper = bumper(Brain.ThreeWirePort.C);

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