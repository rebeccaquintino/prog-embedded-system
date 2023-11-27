#include "uart.hpp" // Include the header file for the UART class

#include <iostream>
#include <fstream>
#include <string>

// Function to filter and print the data based on keywords
void filterAndPrintData(const std::string& line, const std::string& choice_data) {

    // Check if the line contains the data that was chosen
    if (line.find(choice_data) != std::string::npos) {
        std::cout << line << std::endl;
    }
    else{
        std::cout << "No data available" << std::endl;
    }

}

int main() {
    // Display menu options
    std::cout << "Select an option:" << std::endl;
    std::cout << "1. Read data from serial and log to file" << std::endl;
    std::cout << "2. Open file and filter data" << std::endl;

    // Get user's choice
    int choice;
    std::cin >> choice;

    // Option 1: Read data from serial and log to file
    if (choice == 1) {
        // Create instances of UART and DataLogger classes
        UART uart("COM9");
        DataLogger dataLogger("data_uart.txt");

        // Check if both UART and DataLogger are valid
        if (uart.isValid() && dataLogger.isValid()) {
            // Infinite loop to continuously read and log data
            while (true) {
                std::vector<char> receivedData = uart.readData();
                // Check if received data is not empty
                if (!receivedData.empty()) {
                    dataLogger.logData(receivedData);
                }
                // Delay for a short duration before the next iteration
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }
    // Option 2: Open file and filter data
    else if (choice == 2) {

        // Get user's choice
        std::string choice_data;
        std::cout << "Choose the date (YEAR-MOUTH-DAY): " << std::endl;
        std::cin >> choice_data;
        choice_data = "Date: " + choice_data;

        // Open the file for reading
        std::ifstream fileReader("data_uart.txt");
        // Check if the file is open
        if (fileReader.is_open()) {
            // Read each line from the file
            std::string line;
            std::cout << " " << std::endl;
            while (std::getline(fileReader, line)) {
                // Call the filterAndPrint function for each line
                filterAndPrintData(line, choice_data);
            }
            // Close the file after reading
            fileReader.close();
        } else {
            // Display an error message if the file cannot be opened
            std::cerr << "Error opening the file." << std::endl;
        }
    }
    // Invalid choice: Display an error message
    else {
        std::cerr << "Invalid choice." << std::endl;
    }

    // Exit the program
    return 0;
}
