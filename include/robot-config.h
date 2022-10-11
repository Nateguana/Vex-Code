using namespace vex;

extern brain Brain;

using signature = vision::signature;
using code = vision::code;

// VEXcode devices
extern motor LBM;
extern motor RBM;
extern sonar Sonar;
extern bumper BallBumper;
extern line LineL;
extern line LineR;
extern signature Vision__YELL;
extern signature Vision__BLU;
extern signature Vision__RE;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern code Vision__YG;
extern vision Vision;
extern controller Controller1;
extern motor RFM;
extern motor LFM;
extern digital_out DigitalOutH;
extern motor SM;
extern motor ConveyM;
extern motor BrushM;
extern bumper Bumper;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );