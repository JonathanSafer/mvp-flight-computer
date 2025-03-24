#include <Arduino.h>
#include "../include/altimeter.h"
#include "../lib/apogee_detector/apogee_detector.h"

void setup() {
  // put your setup code here, to run once:
  // Once power is supplied to the board, the setup() function is called automatically

  // Initialization - What do we need to initialize?
  // set the altitude to 0
  // check that the altimeter is connected

  // print whether the altimeter is connected or not

  // Calibration - How does calibration work?
  // 
}

void loop() {
  // put your main code here, to run repeatedly:
  // read altitude from the altimeter
  // check what state of flight we're in
  
  double last_altitude = sample_altimeter();
  bool altitude_reached = check_apogee(last_altitude);
  if (altitude_reached) {
    // deploy parachute
    // print message to serial monitor
  }


  // multiple decreases in a row
  // altitude decreases by a certain amount (% or hardcoded value)

  // how do we determine if apogee has occured?
  // if current altitude is lower than prior measurement, apogee has been reached


  // if apogee_has_been_reached, deploy parachute


}
