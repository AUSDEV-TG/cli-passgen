#include "util.h"

char pickChar(const char charSet[], const unsigned& maxIndex)
{
    return charSet[(rand() % maxIndex)];
}

void generatePassword(const char stdCharSet[62],
                      const char symCharSet[31],
                      std::string& password,
                      const unsigned& passwordSize,
                      const bool& symbolsAllowed)
{
    for (unsigned i = 0; i < passwordSize; ++i)
    {
        if (!symbolsAllowed)
        {
            password += pickChar(stdCharSet, 62);
        }
        else
        {
            unsigned stdOrSym = (rand() % 2) + 1;

            if (stdOrSym == 1)
                password += pickChar(stdCharSet, 62);
            else
                password += pickChar(symCharSet, 31);
        }
    }
}

void loadCharSet(char charSet[], const std::string& loadPath)
{
    std::ifstream inFile(loadPath);
    unsigned counter = 0;

    if (inFile.fail())
        std::cerr << loadPath << " could not be loaded.\n";

    while(inFile)
    {
        inFile >> charSet[counter];
        counter++;
    }

    inFile.close();
}

void printUsage(const std::string& programName)
{
    std::cerr << "Usage: " << programName << " <option(s)> VALUES\n"
              << "Options:\n"
              << "\t-h, --help\t\t\tShow this help message\n"
              << "\t-n, --charnum NO_OF_CHARS\tNumber of characters in the generated password\n"
              << "\t-s, --symbols\t\t\tSymbols are allowed in the generated password\n";
}
