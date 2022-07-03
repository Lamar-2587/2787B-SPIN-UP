#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor backleft = motor(PORT20, ratio6_1, true);
motor centerleft = motor(PORT16, ratio6_1, false);
motor frontleft = motor(PORT11, ratio6_1, true);
motor backright = motor(PORT10, ratio6_1, false);
motor centerright = motor(PORT6, ratio6_1, true);
motor frontright = motor(PORT1, ratio6_1, false);
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