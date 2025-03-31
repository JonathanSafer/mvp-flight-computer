#include <gtest/gtest.h>
#include "apogee_detector.h"
// uncomment line below if you plan to use GMock
// #include <gmock/gmock.h>

// TEST(...)
// TEST_F(...)

// verify that apogee detector does not detect apogee immidiately on first measurement
TEST(ApogeeDetection, Initialization) {
    // You can do assertion like this
    double initial_alt = 1;
    bool result = check_apogee(initial_alt);
    EXPECT_FALSE(result);
}

// verify that apogee detector detects apogee after apogee has been reached (altitude decreasing)
TEST(ApogeeDetection, SimpleFlight) {
    // You can do assertion like this
    double basic_trajectory[] = {1, 1, 1, 10, 20, 30, 50, 50, 40, 30, 10, 0};
    for (int i = 0; i < 12; i++) {
        bool apogee_detected = false;
        if(check_apogee(basic_trajectory[i]))
            apogee_detected = true;
        if (i < 6) {
            EXPECT_FALSE(apogee_detected); // Apogee should not be detected while climbing
        } else if (i > 7) {
            EXPECT_TRUE(apogee_detected); // Apogee should have been detected at least once after descent begins
        }
    }
}

#if defined(ARDUINO)
#include <Arduino.h>

void setup()
{
    // should be the same value as for the `test_speed` option in "platformio.ini"
    // default value is test_speed=115200
    Serial.begin(115200);

    ::testing::InitGoogleTest();
    // if you plan to use GMock, replace the line above with
    // ::testing::InitGoogleMock();
}

void loop()
{
  // Run tests
  if (RUN_ALL_TESTS())
  ;

  // sleep for 1 sec
  delay(1000);
}

#else
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    // if you plan to use GMock, replace the line above with
    // ::testing::InitGoogleMock(&argc, argv);

    if (RUN_ALL_TESTS())
    ;

    // Always return zero-code and allow PlatformIO to parse results
    return 0;
}
#endif