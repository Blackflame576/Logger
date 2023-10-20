#include "Logger.hpp"

void Logger::Debug(string LogText)
{   
    string text = DebugStr + "::[" + GetTime() + "]" + ":::" + LogText;
    if (toWrite == true)
    {
        WriteFile(LogPath,text);
    }
    else
    {
        cout << text << endl;
    }
}

void Logger::Error(string LogText)
{
    string text = ErrorStr + "::[" + GetTime() + "]" + ":::" + LogText;
    if (toWrite == true)
    {
        WriteFile(LogPath,text);
    }
    else
    {
        cout << text << endl;
    }
}

void Logger::Info(string LogText)
{
    string text = InfoStr + "::[" + GetTime() + "]" + ":::" + LogText;
    if (toWrite == true)
    {
        WriteFile(LogPath,text);
    }
    else
    {
        cout << text << endl;
    }
}
void Logger::Warning(string LogText)
{
    string text = WarningStr + "::[" + GetTime() + "]" + ":::" + LogText;
    if (toWrite == true)
    {
        WriteFile(LogPath,text);
    }
    else
    {
        cout << text << endl;
    }
}
void Logger::Success(string LogText)
{
    string text = SuccessStr + "::[" + GetTime() + "]" + ":::" + LogText;
    if (toWrite == true)
    {
        WriteFile(LogPath,text);
    }
    else
    {
        cout << text << endl;
    }
}
void Logger::SendError(string Architecture,string Channel,string OS_NAME,string FunctionName,string LogText)
{
    string data = R"({
        "Entries":
        [
        {
        "Architecture":")" + Architecture + R"(",
        "Channel":")" + Channel + R"(",
        "OS_NAME":")" + OS_NAME + R"(",
        "FunctionName":")" + FunctionName + R"(",
        "LogText":")" + LogText + R"(",
        }
        ]
    })";
    ofstream file("./tmp.json",ios::out | ios::binary);
    file << data << endl;
    file.close();
    UDP_CLIENT.SEND_JSON_ARRAY(data);
}



int main()
{
    string s_1 = "12byte";
    string name = "dfdfdfdf";
    string r_1 = "123";
    Logger logger(&name,&s_1);
    Json::Value ErrorValue;
    logger.SendError(name,name,name,name,r_1);

    system("pause");
    return 0;
}