#pragma once

#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#include <iostream>
#include <string>

/* ClockCalendar class */
class ClockCalendar {
    protected:
        const char *ssid = "SpaceLab";     // Replace with your WiFi SSID
        const char *password = "spacelab.."; // Replace with your WiFi password
    public:
        long timezone = -3; // Replace with your timezone offset in hours
        byte daysavetime = 1; // Daylight Saving Time (DST) offset in hours
        // Initialization function
        void init();
        // Constructor for the ClockCalendar class
        std::string now();
};
