#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

// UART class for handling serial communication
class UART {
private:
    HANDLE serialHandle;  // Handle to the serial port

public:
    // Constructor: Opens the serial port and configures its parameters
    UART(const std::string& portName) : serialHandle(INVALID_HANDLE_VALUE) {
        // Open the serial port
        serialHandle = CreateFileA(portName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        // Check if the serial port was opened successfully
        if (serialHandle == INVALID_HANDLE_VALUE) {
            std::cerr << "Error opening the serial port." << std::endl;
            return;
        }

        // Configure the serial port settings
        DCB dcbSerialParams = { 0 };
        dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
        if (!GetCommState(serialHandle, &dcbSerialParams)) {
            std::cerr << "Error getting the state of the serial port." << std::endl;
            CloseHandle(serialHandle);
            return;
        }

        // Set serial port parameters
        dcbSerialParams.BaudRate = CBR_9600;
        dcbSerialParams.ByteSize = 8;
        dcbSerialParams.StopBits = ONESTOPBIT;
        dcbSerialParams.Parity = NOPARITY;

        // Apply the configured settings
        if (!SetCommState(serialHandle, &dcbSerialParams)) {
            std::cerr << "Error configuring the state of the serial port." << std::endl;
            CloseHandle(serialHandle);
            return;
        }
     }

    // Destructor: Closes the serial port
    ~UART() {
        if (serialHandle != INVALID_HANDLE_VALUE) {
            CloseHandle(serialHandle);
        }
    }

    // Read data from the serial port
    std::vector<char> readData() {
        const int bufferSize = 82;
        std::vector<char> buffer(bufferSize);

        DWORD bytesRead = 0;
        // Read data from the serial port into the buffer
        if (ReadFile(serialHandle, buffer.data(), bufferSize, &bytesRead, NULL)) {
            return buffer;
        } else {
            std::cerr << "Error reading from the serial port." << std::endl;
            return {};
        }
    }

    // Check if the serial port is open and valid
    bool isValid() const {
        return serialHandle != INVALID_HANDLE_VALUE;
    }
};

// DataLogger class for logging data to a file
class DataLogger {
private:
    std::ofstream file;

public:
    // Constructor: Opens the file for writing and appending data
    DataLogger(const std::string& filename) {
        file.open(filename, std::ios::out | std::ios::app);
        if (!file.is_open()) {
            std::cerr << "Error opening the file." << std::endl;
        }
    }

    // Destructor: Closes the file
    ~DataLogger() {
        if (file.is_open()) {
            file.close();
        }
    }

    // Log data to the file
    void logData(const std::vector<char>& data) {
        if (file.is_open()) {
            // Write data to the file
            file.write(data.data(), data.size());    
            file.flush();

            // Display data in the console
            for (char c : data) {
                std::cout << c;
            }
        } else {
            std::cerr << "File is not open." << std::endl;
        }
    }

    // Check if the file is open and valid
    bool isValid() const {
        return file.is_open();
    }
};
