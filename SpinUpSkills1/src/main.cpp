/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// backleft             motor         20              
// centerleft           motor         16              
// frontleft            motor         11              
// backright            motor         10              
// centerright          motor         6               
// frontright           motor         1               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void setallright (double speed) { //sets velocity of all the right-side motors on the robot base
  frontright.setVelocity(speed, percent);
  centerright.setVelocity(speed, percent);
  backright.setVelocity(speed, percent);
}

void setallleft (double speed) { //sets the velocity of all the left-side motors on the robot base
  frontleft.setVelocity(speed, percent);
  centerleft.setVelocity(speed, percent);
  backleft.setVelocity(speed, percent);
}

void spinallright () { //spins all the right-side motors on the robot base
  frontright.spin(forward);
  centerright.spin(forward);
  backright.spin(forward);
}

void spinallleft () { //spins all the left-side motors on the robot base
  frontleft.spin(forward);
  centerleft.spin(forward);
  backleft.spin(forward);
}

void spinall () { //spins all the motors on the robot base
  spinallleft();
  spinallright();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int y; //y direction (front-back) as from the joystick
int x; //x direction (turning) as from the joystick
int threshold; //"dead zone" of joysticks
int leftspeed; //calculated speed of left side of the base
int rightspeed; //calculated speed of right side of the base

void usercontrol(void) {
  while (1) {
    y = Controller1.Axis3.position(percent);
    x = Controller1.Axis4.position(percent);

    if (x <= threshold && x >= -threshold) {
      x = 0;
    }
    
    if (y <= threshold && y >= -threshold) {
      y = 0;
    }

    leftspeed = y + x;
    rightspeed = y - x;

    setallleft(leftspeed);
    setallright(rightspeed);

    spinall();

    wait(10, msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
