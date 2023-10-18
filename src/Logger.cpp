#include "Logger.hpp"

class Logger {
    // Инициализация переменных класса
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

    public:
        void init(const string path_file = "",const string limit = "") {
            cout << path_file << endl;
            if (path_file != "") {
                getFile = true;
                PathFile = path_file;
                if (limit != "") {
                    // limit_size = replace("3333mb","mb","");
                    // print(limit_size);
                    print(limit);
                }
            }
            else {
                getFile = false;
            }
            // Debug("Debug");
            // Error("Eror");
            // Info("Info");
            // Success("Success");
            // Warning("Warning");
        }

        const string GetTime() {
            time_t     now = time(0);
            struct tm  tstruct;
            char       buf[80];
            tstruct = *localtime(&now);
            // for more information about date/time format
            strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
            return buf;
        }

        void Debug(string sentence) {
            auto time = GetTime();
            string text = DebugStr + "::[" + time + "]" + ":::" + sentence;
            if (getFile == true) {
                WriteFile(PathFile,text);
            }
            else {
                print(text);
            }
        }
        void Info(string sentence) {
            auto time = GetTime();
            string text = InfoStr + "::[" + time + "]" + ":::" + sentence;
            if (getFile == true) {
                WriteFile(PathFile,text);
            }
            else {
                print(text);
            }
        }

        void Error(string sentence) {
            auto time = GetTime();
            string text = ErrorStr + "::[" + time + "]" + ":::" + sentence;
            if (getFile == true) {
                WriteFile(PathFile,text);
            }
            else {
                print(text);
            }
        }
        
        void Warning(string sentence) {
            auto time = GetTime();
            string text = WarningStr + "::[" + time + "]" + ":::" + sentence;
            if (getFile == true) {
                WriteFile(PathFile,text);
            }
            else {
                print(text);
            }
        }

        void Success(string sentence) {
            auto time = GetTime();
            string text = SuccessStr + "::[" + time + "]" + ":::" + sentence;
            if (getFile == true) {
                WriteFile(PathFile,text);
            }
            else {
                print(text);
            }
        }

    private:
        void WriteFile(string filename,string sentence) {
            file.open(filename,ofstream::app);
            get_file_size.open(filename, ios::in | ios::binary);
            get_file_size.seekg(0,ios::end);
            size = get_file_size.tellg();
            get_file_size.close();
            file << sentence + "\n";
            size_KB = round(size / 1024);
            size_MB = round(size / pow(1024,2));
            size_GB = round(size / pow(1024,3));
            size_TB = round(size / pow(1024,4));
            file.close();
        }
};

int main() {
    setlocale(LC_ALL, "RU");
    auto main_logger = Logger();
    main_logger.init("text.txt","mb");
    // system("pause");
    return 0;
}