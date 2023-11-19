#include <iostream>
#include <string>

#include "../clockCalendar/clockCalendar.hpp"

// Initialization function
void ClockCalendar::init() {
    // Connecting to WiFi
    Serial.println();
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    int i = 0;

    // Wait for WiFi connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        
        // Restart if connection takes too long
        if (i > 20) {
            ESP.restart();
        }
        i++;
    }

    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // Configuring time with NTP server
    Serial.println("Contacting Time Server");
    configTime(3600 * timezone, daysavetime * 3600, "time.nist.gov", "0.pool.ntp.org", "1.pool.ntp.org");
    Serial.println("----------------------------------------------");
}

// Constructor for the ClockCalendar class
void ClockCalendar::clockCalendar() {
    // Create a struct to store time information
    struct tm tmstruct;
    tmstruct.tm_year = 0; // Initialize year to 0
    // Get the local time from the system
    getLocalTime(&tmstruct);
    // Formatting and printing date and time
    // Convert year, month, and day to a string in the format "YYYY-MM-DD"
    String date = String((tmstruct.tm_year) + 1900) + "-" + String((tmstruct.tm_mon) + 1) + "-" + String(tmstruct.tm_mday);
    // Convert hour, minute, and second to a string in the format "HH:MM:SS"
    String hour = String(tmstruct.tm_hour) + ":" + String(tmstruct.tm_min) + ":" + String(tmstruct.tm_sec);
    // Print the formatted date and time
    //Serial.println("Date: " + date + " - Time: " + hour);
    std::cout << "Date: " << std::endl;
    std::cout << date << std::endl;
    std::cout << " - Time: " << std::endl;
    std::cout << hour << std::endl;
    // Introduce a delay of 1000 milliseconds (1 second)
    delay(1000);
}