#include "v_library.hpp"


/*
  __  __       _     _                        _               ____
 |  \/  |     (_)   | |              ___     | |             |___ \
 | \  / | __ _ _  __| | _____   __  ( _ )    | |     _____   ____) |_   _ _ __
 | |\/| |/ _` | |/ _` |/ _ \ \ / /  / _ \/\  | |    / _ \ \ / /__ <| | | | '_ \
 | |  | | (_| | | (_| |  __/\ V /  | (_>  <  | |___| (_) \ V /___) | |_| | |_) |
 |_|  |_|\__,_| |\__,_|\___| \_/    \___/\/  |______\___/ \_/|____/ \__, | .__/
             _/ |                                                    __/ | |
            |__/                                                    |___/|_|
Tüm Haklarý - MajLov3 Tarafýndan Korunmaktadýr.
2021 Ýnjeckt System - CSGO , LOADLÝBRARY
Lov3yp#2018
Majdev#3031
https://discord.gg/DXuy6zQj

*/

namespace Logger {
    HANDLE  Console = GetStdHandle(STD_OUTPUT_HANDLE);

    struct _LogType {
        int Default = 15;
        int Warning = 6;
        int Success = 2;
        int Error = 4;
        int Info = 11;
    }LoggerType;

    void Write(std::string Message, int LogType = 15) {
        SYSTEMTIME lt;
        GetLocalTime(&lt);
        SetConsoleTextAttribute(Console, 8);
        printf("[%02d/%02d/%02d %02d:%02d:%02d] ", lt.wMonth, lt.wDay, lt.wYear, lt.wHour, lt.wMinute, lt.wSecond);
        SetConsoleTextAttribute(Console, LogType);
        std::cout << Message << std::endl;
        SetConsoleTextAttribute(Console, 15);
    }


  
}


/*
  __  __       _     _                        _               ____
 |  \/  |     (_)   | |              ___     | |             |___ \
 | \  / | __ _ _  __| | _____   __  ( _ )    | |     _____   ____) |_   _ _ __
 | |\/| |/ _` | |/ _` |/ _ \ \ / /  / _ \/\  | |    / _ \ \ / /__ <| | | | '_ \
 | |  | | (_| | | (_| |  __/\ V /  | (_>  <  | |___| (_) \ V /___) | |_| | |_) |
 |_|  |_|\__,_| |\__,_|\___| \_/    \___/\/  |______\___/ \_/|____/ \__, | .__/
             _/ |                                                    __/ | |
            |__/                                                    |___/|_|
Tüm Haklarý - MajLov3 Tarafýndan Korunmaktadýr.
2021 Ýnjeckt System - CSGO , LOADLÝBRARY
Lov3yp#2018
Majdev#3031
https://discord.gg/DXuy6zQj

*/