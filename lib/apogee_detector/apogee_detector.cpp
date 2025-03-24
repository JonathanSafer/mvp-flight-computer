#include "apogee_detector.h"

bool check_apogee(double last_altitude) {
    // Check if the altitude has decreased from the last measurement
    // If it has, we assume apogee has been reached
    // This is a simple check and can be improved with more sophisticated logic

    static double previous_altitude = 0.0;

    if (last_altitude <= previous_altitude - 1) {
        previous_altitude = last_altitude;
        return true; // Apogee detected
    }

    previous_altitude = last_altitude;
    return false; // No apogee detected
}