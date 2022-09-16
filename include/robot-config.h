using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor ArmM;
extern motor LeftM;
extern motor RightM;
extern sonar Sonar;
extern bumper Bumper;
extern line LineL;
extern line LineR;
extern signature Vision__YELL;
extern signature Vision__BLU;
extern signature Vision__RE;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );