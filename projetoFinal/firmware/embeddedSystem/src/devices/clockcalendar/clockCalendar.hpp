#pragma once

#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

/* ClockCalendar class */
class ClockCalendar {
    protected:
        const char *ssid = "your-wifi-ssid";     // Replace with your WiFi SSID
        const char *password = "your-wifi-password"; // Replace with your WiFi password
    public:
        long timezone = -3; // Replace with your timezone offset in hours
        byte daysavetime = 1; // Daylight Saving Time (DST) offset in hours
        // Initialization function
        void init();
        // Constructor for the ClockCalendar class
        void clockCalendar();
};
