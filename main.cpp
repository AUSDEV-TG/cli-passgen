#include <sstream>
#include "util.h"

    /**
     *  Simple CLI password generator
     *
     *  Licensed with GNU GPL v3
     *
     *  @author Tom Green
     *  @date 09/07/2020 - Created
     */

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printUsage(argv[0]);
        return 1;
    }

    unsigned numChars = 0;
    bool symbolsAllowed = false;

    char stdCharSet[62];
    char symCharSet[31];
    std::string password = "";

    loadCharSet(stdCharSet, "std-chars.txt");
    loadCharSet(symCharSet, "sym-chars.txt");

    srand(time(nullptr));

    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];

        if ((arg == "-h") || (arg == "--help"))
        {
            printUsage(argv[0]);
            return 0;
        }
        else if ((arg == "-n") || (arg == "--charnum"))
        {
            if (i + 1 < argc)
            {
                std::istringstream ss(argv[++i]);

                if (!(ss >> numChars))
                {
                    std::cerr << "Invalid number: " << argv[++i] << '\n';
                    return 1;
                }
            }
        }
        else if ((arg == "-s") || (arg == "--symbols"))
        {
            symbolsAllowed = true;
        }
    }

    if (numChars == 0)
    {
        std::cerr << "You must specify the length of the password to be generated.\n";
        printUsage(argv[0]);
        return 1;
    }

    generatePassword(stdCharSet, symCharSet, password, numChars, symbolsAllowed);

    std::cout << "Generated Password: " << password << '\n';

    return 0;
}
