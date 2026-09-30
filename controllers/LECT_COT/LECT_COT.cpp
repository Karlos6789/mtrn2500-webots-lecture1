// File:          LECT_COT.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <iostream>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>

const int TIME_STEP {64};
const double MAX_SPEED {6.28};
const double WHEEL_RADIUS {0.02};

const double AXLE_LENGTH {0.052};


// All the webots classes are defined in the "webots" namespace


// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  
  webots::Robot robot {};
  
  webots::Motor* leftMotor {robot.getMotor("left wheel motor")};
  webots::Motor* rightMotor {robot.getMotor("right wheel motor")};
  
  webots::PositionSensor* leftEncoder {robot.getPositionSensor("left wheel sensor")};
  webots::PositionSensor* rightEncoder {robot.getPositionSensor("right wheel sensor")};
  
  leftEncoder->enable(TIME_STEP);
  rightEncoder->enable(TIME_STEP);
  
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);
  
 
  
  leftMotor->setVelocity(0.1 * MAX_SPEED);
  rightMotor->setVelocity(0.1 * MAX_SPEED);
  
  
  
  while(robot.step(TIME_STEP) != -1) {
    double leftPosition {leftEncoder->getValue()};
    double rightPosition {rightEncoder->getValue()};
    
    std::cout << leftPosition << ' ' << rightPosition << ' ';
    std::cout << (leftPosition + rightPosition) * WHEEL_RADIUS / 2 << ' ' ;
    std::cout << (rightPosition - leftPosition) * WHEEL_RADIUS / AXLE_LENGTH << '\n' ;
    
  
  };


  
  return 0;
}
