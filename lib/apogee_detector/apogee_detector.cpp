#include "apogee_detector.h"

bool check_apogee(double current_altitude) {
    // Check if the altitude has decreased from the last measurement
    // If it has, we assume apogee has been reached
    // This is a simple check and can be improved with more sophisticated logic

    static double previous_altitude = 0.0;

    if (current_altitude <= previous_altitude - 1) {
        previous_altitude = current_altitude;
        return true; // Apogee detected
    }

    previous_altitude = current_altitude;
    return false; // No apogee detected
}