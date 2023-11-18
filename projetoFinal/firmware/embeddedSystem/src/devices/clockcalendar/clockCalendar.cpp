#include <Arduino.h>
#include "../clockcalendar/clockCalendar.hpp" // Assuming the correct path to the header file

// Implementation of the Clock class
Clock::Clock(int h, int s, int m, int pm){
    hr = h;
    min = m;
    sec = s;
    is_pm = pm;
}

// Destructor for the Clock class
Clock::~Clock(){}
// Function to advance the clock by a given number of elapsed seconds
void Clock::advance(int elapsedSeconds){
    if (elapsedSeconds > 0) {
        sec += elapsedSeconds;
        int extraMinutes = sec / 60;
        sec %= 60;
        min += extraMinutes;
        int extraHours = min / 60;
        min %= 60;
        hr += extraHours;
        hr %= 24;
        is_pm = (hr >= 12);
    }
}

// Implementation of the Calendar class
Calendar::Calendar(int m, int d, int y){
    mo = m;
    day = d;
    yr = y;
}

// Destructor for the Calendar class
Calendar::~Calendar(){}
// Function to advance the calendar by one day, handling month and year transitions
void Calendar::advance(){
    if(++day > 30){
        day = 1;
        if(++mo > 12){
            mo = 1;
            yr++;
        }
    }
}

// Implementation of the ClockCalendar class
ClockCalendar::ClockCalendar() : Clock(0, 0, 0, 0), Calendar(11, 16, 2023), lastAdvanceTime(0) {}

// Destructor for the ClockCalendar class
ClockCalendar::~ClockCalendar(){}

// Function to advance both the clock and the calendar
void ClockCalendar::advance(){
    int was_pm = is_pm;
    
    int64_t currentTime = micros(); // Get current time in microseconds
    int64_t elapsedTime = currentTime - lastAdvanceTime;
    int elapsedSeconds = elapsedTime / 1000000; // Convert to seconds
    
    // Advance the clock
    Clock::advance(elapsedSeconds);
    // If the AM/PM indicator changed, advance the calendar
    if (was_pm && !is_pm)
        Calendar::advance();
    lastAdvanceTime = currentTime; // Update the last advance time
}
