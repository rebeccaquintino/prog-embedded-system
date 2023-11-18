#include <string>
#include <iostream>

// Class representing a clock
class Clock {
protected:
    int hr, min, sec, is_pm; // Hour, minute, second, and AM/PM indicator
public:
    Clock(int h, int s, int m, int pm); // Constructor
    ~Clock(); // Destructor
    void advance(int elapsedSeconds); // Function to advance the clock
};

// Class representing a calendar
class Calendar {
protected:
    int mo, day, yr; // Month, day, and year
public:
    Calendar(int m, int d, int y); // Constructor
    ~Calendar(); // Destructor
    void advance(); // Function to advance the calendar
};

// Class representing a clock and calendar combination
class ClockCalendar : public Clock, public Calendar {
private:
    uint64_t lastAdvanceTime; // Last time the clock was advanced
public:
    ClockCalendar(); // Constructor
    ~ClockCalendar(); // Destructor
    void advance(); // Function to advance both clock and calendar
    
    // Function to convert an integer to a string
    String intToString(int num) const {
        String result = "";
        if (num == 0) {
            result = "0";
        } else {
            while (num > 0) {
                char digit = '0' + (num % 10);
                result = digit + result;
                num /= 10;
            }
        }
        return result;
    }

    // Overloaded + operator to concatenate date and time as a string
    String operator+() const {
        return intToString(mo) + "/" + intToString(day) + "/" + intToString(yr) + " " + intToString(hr) + ":" + intToString(min) + ":" + intToString(sec);
    }
};
