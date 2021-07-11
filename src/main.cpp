#include <iostream>
#include <string>
#include "tempclc.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // Default options
    bool    oUnits      = false;
    bool    oVerbose    = false;
    bool    oPrintHelp  = false;

    // Declaration of all possible command line options
    tempclc args("Usage: tempclc [-uv] value<c|C|f|F>");
    args.addArgument({"-u", "--units"},     &oUnits,    "Show units in output");
    args.addArgument({"-v", "--verbose"},   &oVerbose,  "Show output as XX = YY");
    args.addArgument({"-h", "--help"},      &oPrintHelp,
            "Print this help message and exit");

    // Parse command line arguments
    try
    {
        args.parse(argc, argv);
    }
    catch (std::runtime_error const& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }

    // If oPrintHelp was set to true, print a help message and exit.
    if (oPrintHelp)
    {
        args.printHelp();
        return 0;
    }
    
    // Find the temperature value in passed arguments
    string input;
    float v = 0;
    for (int i = 1; i < argc; i++)
    {
        input = argv[i];
        if ((input.find('c') != string::npos) || (input.find('C') != string::npos))
        {
            if (input.find('c') != string::npos) v = stof(input.substr(0,input.find('c')));
            if (input.find('C') != string::npos) v = stof(input.substr(0,input.find('C')));
            if (oVerbose)
            {
                float org = v;
                v = (1.8 * v) + 32;
                if (oUnits) cout << org << "°C = " << v << "°F" << endl;
                else cout << org << " = " << v << endl;
                return 0;
            }
            else
            {
                v = (1.8 * v) + 32;
                if (oUnits) cout << v << "°F" << endl;
                else cout << v << endl;
                return 0;
            }
        }
        else if ((input.find('f') != string::npos) || (input.find('F') != string::npos))
        {
            if (input.find('f') != string::npos) v = stof(input.substr(0,input.find('f')));
            if (input.find('F') != string::npos) v = stof(input.substr(0,input.find('F')));
            if (oVerbose)
            {
                float org = v;
                v = (v - 32) / 1.8;
                if (oUnits) cout << org << "°F = " << v << "°C" << endl;
                else cout << org << " = " << v << endl;
                return 0;
            }
            else
            {
                v = (v - 32) / 1.8;
                if (oUnits) cout << v << "°C" << endl;
                else cout << v << endl;
                return 0;
            }
        }
    }
    
    cout << "[ERROR] No value found" << endl;
    return 2;
}
