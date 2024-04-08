/**
* @file Jedi.cpp
* @author Hudson Schumaker
* @brief This program generates a Jedi name based on user input.
* The Jedi name is created by combining parts of the user's last name, first name, mother's name, and city name.
*/
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

/**
* @brief Converts all characters in a string to lowercase.
* @param str The string to convert.
*/
void toLowerCase(std::string &str);

/**
* @brief Prints a prompt to the console and returns the user's input as a string.
* @param prompt The prompt to display.
* @return The user's input.
*/
std::string getInput(const std::string &prompt);

/**
* @brief Generates a Jedi name based on the provided names.
* @param lastName The user's last name.
* @param firstName The user's first name.
* @param motherName The user's mother's name.
* @param cityName The user's city name.
* @return The generated Jedi name.
*/
std::string generateJediName(const std::string &lastName, const std::string &firstName, const std::string &motherName, const std::string &cityName);

int main(int argc, char* argv[]) {
    std::system(CLEAR);
    std::cout << "---- Jedi Name Creation ----" << std::endl;
    std::string lastName, firstName, motherName, cityName;

    if (argc == 5) {
        lastName = argv[1];
        firstName = argv[2];
        motherName = argv[3];
        cityName = argv[4];
    } else {
        lastName = getInput("Enter your last name: ");
        firstName = getInput("Enter your first name: ");
        motherName = getInput("Enter your mother's name: ");
        cityName = getInput("Enter your city name: ");
    }

    std::string jediName = generateJediName(lastName, firstName, motherName, cityName);
    std::cout << "Your Jedi Name is: " << jediName << std::endl;
    return 0;
}

std::string getInput(const std::string &prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    std::system(CLEAR);  // Clear the terminal screen
    std::cout << "---- Jedi Name Creation ----" << std::endl;
    return input;
}

std::string generateJediName(const std::string &lastName, const std::string &firstName, const std::string &motherName, const std::string &cityName) {
    std::string jediName = lastName.substr(0, 3) + firstName.substr(0, 2) + motherName.substr(0, 2) + cityName.substr(0, 3);
    toLowerCase(jediName);
    jediName[0] = std::toupper(jediName[0]);
    return jediName;
}

void toLowerCase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}
