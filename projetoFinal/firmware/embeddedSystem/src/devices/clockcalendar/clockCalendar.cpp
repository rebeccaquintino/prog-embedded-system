#include "../clockCalendar/clockCalendar.hpp"

// Initialization function
void ClockCalendar::init() {
    // Connecting to WiFi
    //Serial.println();
    //Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    int i = 0;

    // Wait for WiFi connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        //Serial.print(".");
        
        // Restart if connection takes too long
        if (i > 20) {
            ESP.restart();
        }
        i++;
    }

    //Serial.println("WiFi connected");
    //Serial.print("IP address: ");
    //Serial.println(WiFi.localIP());

    // Configuring time with NTP server
    //Serial.println("Contacting Time Server");
    configTime(3600 * timezone, daysavetime * 3600, "time.nist.gov", "0.pool.ntp.org", "1.pool.ntp.org");
    //Serial.println("----------------------------------------------");
}

// Constructor for the ClockCalendar class
std::string ClockCalendar::now() {
    // Create a struct to store time information
    struct tm tmstruct;
    tmstruct.tm_year = 0; // Initialize year to 0
    // Get the local time from the system
    getLocalTime(&tmstruct);
    // Formatting and printing date and time
    // Convert year, month, and day to a string in the format "YYYY-MM-DD"
    std::string clockCalendar = "Date: " + std::to_string((tmstruct.tm_year) + 1900) + "-" + std::to_string((tmstruct.tm_mon) + 1) + "-" + std::to_string(tmstruct.tm_mday) + " - Time: " + std::to_string(tmstruct.tm_hour) + ":" + std::to_string(tmstruct.tm_min) + ":" + std::to_string(tmstruct.tm_sec);
    // Introduce a delay of 1000 milliseconds (1 second)
    return clockCalendar;
}