#include <Windows.h>
#include <ShlObj.h>
#include <shlwapi.h>
#include <TlHelp32.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <time.h>
#include <string>
#include <iostream>
#include <random>
#include <thread>
#include <Windows.h>
#include <ShlObj.h>
#include <shlwapi.h>
#include <TlHelp32.h>
#include <wininet.h>
#pragma comment(lib,"Wininet.lib") 
#pragma comment(lib, "Shlwapi.lib")
#define ERASE_ENTRY_POINT    TRUE
using namespace std;
#include <TlHelp32.h>
#pragma once


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

template <int X> struct EnsureCompileTime {
    enum : int {
        Value = X
    };
};

#define Seed ((__TIME__[7] - '0') * 1  + (__TIME__[6] - '0') * 10  + \
              (__TIME__[4] - '0') * 60   + (__TIME__[3] - '0') * 600 + \
              (__TIME__[1] - '0') * 3600 + (__TIME__[0] - '0') * 36000)

constexpr int LinearCongruentGenerator(int Rounds) {
    return 1013904223 + 1664525 * ((Rounds > 0) ? LinearCongruentGenerator(Rounds - 1) : Seed & 0xFFFFFFFF);
}
#define Random() EnsureCompileTime<LinearCongruentGenerator(10)>::Value
#define RandomNumber(Min, Max) (Min + (Random() % (Max - Min + 1)))

template <int... Pack> struct IndexList {};

template <typename IndexList, int Right> struct Append;
template <int... Left, int Right> struct Append<IndexList<Left...>, Right> {
    typedef IndexList<Left..., Right> Result;
};

template <int N> struct ConstructIndexList {
    typedef typename Append<typename ConstructIndexList<N - 1>::Result, N - 1>::Result Result;
};
template <> struct ConstructIndexList<0> {
    typedef IndexList<> Result;
};

const char XORKEY = static_cast<char>(RandomNumber(0, 0xFF));
constexpr char EncryptCharacter(const char Character, int Index) {
    return Character ^ (XORKEY + Index);
}

template <typename IndexList> class CXorString;
template <int... Index> class CXorString<IndexList<Index...> > {
private:
    char Value[sizeof...(Index) + 1];
public:
    constexpr CXorString(const char* const String)
        : Value{ EncryptCharacter(String[Index], Index)... } {}

    char* decrypt() {
        for (int t = 0; t < sizeof...(Index); t++) {
            Value[t] = Value[t] ^ (XORKEY + t);
        }
        Value[sizeof...(Index)] = '\0';
        return Value;
    }

    char* get() {
        return Value;
    }
};
#define XorS(X, String) CXorString<ConstructIndexList<sizeof(String)-1>::Result> X(String)
#define XorString( String ) ( CXorString<ConstructIndexList<sizeof( String ) - 1>::Result>( String ).decrypt() )


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