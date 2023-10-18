#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <exception>
#include <filesystem>
#include <cmath>
#include <concepts>
#if defined(__linux__) || __APPLE__
#include "./include/Client_UNIX.hpp"
using namespace UNIX;
#elif _WIN32
#include "./include/Client_POSIX.hpp"
using namespace POSIX;
#endif

using namespace std;

class Logger
{
public:
    bool getFile = false;
    ofstream file;
    string PathFile = "";
    long size;
    long size_KB;
    long size_MB;
    long size_GB;
    long size_TB;
    ifstream get_file_size;
    long limit_size;
    char limit_value;
    const string DebugStr = "☑️[DEBUG]";
    const string ErrorStr = "❌[ERROR]";
    const string InfoStr = "🆗[INFO]";
    const string WarningStr = "⚠️[WARNING]";
    const string SuccessStr = "✅[SUCCESS]";

    Logger()
    {
        Client UDP_CLIENT;
    }
    const string GetTime()
    {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        // for more information about date/time format
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
        return buf;
    }

    void Debug(string LogText);
    void Error(string LogText);
    void Info(string LogText);
    void Warning(string LogText);
    void Success(string LogText);

private:
};