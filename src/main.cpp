#include <Arduino.h>

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
  
  float last_altitude = sample_altimeter();
  float altitude = sample_altimeter();
  while (altitude >= last_altitude) {
    last_altitude = altitude;
    altitude = sample_altimeter();
  }
  deploy_parachute();

  // how do we determine if apogee has occured?
  // if current altitude is lower than prior measurement, apogee has been reached


  // if apogee_has_been_reached, deploy parachute


}