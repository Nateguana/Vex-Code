using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor ArmM;
extern motor LeftM;
extern motor RightM;
extern sonar Sonar;
extern bumper Bumper;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );