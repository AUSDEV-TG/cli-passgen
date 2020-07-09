#ifndef UTIL_H
#define UTIL_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

    /**
     *  @author Tom Green
     *  @date 09/07/2020 - Created
     */

    /**
     *  @brief Picks a random character from the provided character set
     *  @param charSet - The provided character set (array of characters)
     *  @param maxIndex - The maximum possible index of the character set
     *  @return char
     */
char pickChar(const char charSet[], const unsigned& maxIndex);

    /**
     *  @brief Generates a password
     *  The function pickChar and user specifications are used to generate a password
     *
     *  @param stdCharSet - The standard character set (0-9 & a-z & A-Z)
     *  @param symCharSet - The symbol character set (consisting of commonly accepted symbols)
     *  @param password - string reference to store the password
     *  @param passwordSize - The size of the desired password
     *  @param symbolsAllowed - Boolean to determine if symbols should be used in generation
     */
void generatePassword(const char stdCharSet[62],
                      const char symCharSet[31],
                      std::string& password,
                      const unsigned& passwordSize,
                      const bool& symbolsAllowed);

    /**
     *  @brief Loads a character set
     *  @param charSet - char array to store the character set in
     *  @param loadPath - file to load the charSet from
     */
void loadCharSet(char charSet[], const std::string& loadPath);

    /**
     *  @brief Prints the command usage
     *  @param programName - string representing the program name
     */
void printUsage(const std::string& programName);

#endif // UTIL_H
