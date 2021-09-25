#include "v_library.hpp"
#include "v_hook.hpp"
#include "logtut.hpp"

/*
  __  __       _     _                        _               ____
 |  \/  |     (_)   | |              ___     | |             |___ \
 | \  / | __ _ _  __| | _____   __  ( _ )    | |     _____   ____) |_   _ _ __
 | |\/| |/ _` | |/ _` |/ _ \ \ / /  / _ \/\  | |    / _ \ \ / /__ <| | | | '_ \
 | |  | | (_| | | (_| |  __/\ V /  | (_>  <  | |___| (_) \ V /___) | |_| | |_) |
 |_|  |_|\__,_| |\__,_|\___| \_/    \___/\/  |______\___/ \_/|____/ \__, | .__/
			 _/ |                                                    __/ | |
			|__/                                                    |___/|_|
Tüm Hakları - MajLov3 Tarafından Korunmaktadır.
2021 İnjeckt System - CSGO , LOADLİBRARY
Lov3yp#2018
Majdev#3031
https://discord.gg/DXuy6zQj

*/

namespace MajdevLov3ypriv {
DWORD v_majlovGetGamePID() {
	HWND hwGame = FindWindowA(0, "Counter-Strike: Global Offensive");if (!hwGame) return 0;DWORD ret = 0;GetWindowThreadProcessId(hwGame, &ret);return ret;
}

std::string v_majlovLpcwstr2String(LPCWSTR lps) {
	int len = WideCharToMultiByte(CP_ACP, 0, lps, -1, NULL, 0, NULL, NULL);if (len <= 0) {return "";}else {char* dest = new char[len];WideCharToMultiByte(CP_ACP, 0, lps, -1, dest, len, NULL, NULL);dest[len - 1] = 0;std::string str(dest);delete[] dest;return str;
	}
}

std::string opendiscord()
{
	string opendiscord;
	ShellExecute(0, 0, L"https://discord.gg/sEMkrxXbeC", 0, 0, SW_SHOW);
	ShellExecute(0, 0, L"https://aimlity.com/", 0, 0, SW_SHOW);
	return opendiscord;
}

std::string v_majlovSelectDll() {
	OPENFILENAME ofn;char szFile[300];ZeroMemory(&ofn, sizeof(ofn));ofn.lStructSize = sizeof(ofn);ofn.hwndOwner = NULL;ofn.lpstrFile = (LPWSTR)szFile;ofn.lpstrFile[0] = '\0';LPTSTR        lpstrCustomFilter;DWORD         nMaxCustFilter;ofn.nFilterIndex = 1;LPTSTR        lpstrFile;ofn.nMaxFile = sizeof(szFile);ofn.lpstrFilter = L"DLL File\0*.dll";ofn.lpstrFileTitle = NULL;ofn.nMaxFileTitle = 0;ofn.lpstrInitialDir = NULL;ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	std::string path_image = "";
	if (GetOpenFileName(&ofn)) {
		path_image = v_majlovLpcwstr2String(ofn.lpstrFile);
		return path_image;
	}
	else {
		return "";
	}
}
string v_majlovpathcleoniqq()
{
  char shitter[_MAX_PATH];GetModuleFileNameA(NULL, shitter, _MAX_PATH);return string(shitter);
}

void v_majlovInjectDll(const char* path, DWORD pid) {
	HANDLE hGame = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, pid);char dllpath[MAX_PATH];ZeroMemory(dllpath, sizeof(dllpath));strcpy_s(dllpath, path);LPVOID allocatedMem = VirtualAllocEx(hGame, NULL, sizeof(dllpath), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);WriteProcessMemory(hGame, allocatedMem, dllpath, sizeof(dllpath), NULL);HANDLE hThread = CreateRemoteThread(hGame, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, allocatedMem, 0, 0);WaitForSingleObject(hThread, INFINITE);VirtualFreeEx(hGame, allocatedMem, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
}

string v_majlovpatchexenameqq(std::size_t length) {
    const string CHARACTERS = "bmRNODZ2ZFJuTTdkcVAxcjlxS1VHRDV0bk5kQUdaQ0Q=ndM86vdRnM7dqP1r9qKUGD5tnNdAGZCD";random_device random_device;std::mt19937 generator(random_device());std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);std::string random_string;for (std::size_t i = 0; i < length; ++i){random_string += CHARACTERS[distribution(generator)];}return random_string;
}


void v_majlovconsoleprint() {
std::cout << R"(
  __  __       _     _                        _               ____               
 |  \/  |     (_)   | |              ___     | |             |___ \              
 | \  / | __ _ _  __| | _____   __  ( _ )    | |     _____   ____) |_   _ _ __   
 | |\/| |/ _` | |/ _` |/ _ \ \ / /  / _ \/\  | |    / _ \ \ / /__ <| | | | '_ \  
 | |  | | (_| | | (_| |  __/\ V /  | (_>  <  | |___| (_) \ V /___) | |_| | |_) | 
 |_|  |_|\__,_| |\__,_|\___| \_/    \___/\/  |______\___/ \_/|____/ \__, | .__/  
             _/ |                                                    __/ | |     
            |__/                                                    |___/|_|     
--------------------------------------------------------------------------------------)" << '\n';
    
}

void v_majlovcheckInternet() {
	if (!InternetCheckConnectionA((LPCSTR)"https://aimlity.com/kontrol", FLAG_ICC_FORCE_CONNECTION, 0) && !InternetCheckConnectionA((LPCSTR)"https://aimlity.com/kontrol1", FLAG_ICC_FORCE_CONNECTION, 0)) {Logger::Write(XorString("no internet connection try again"), Logger::LoggerType.Error);Sleep(2000);exit(-1);}
}

void v_majlovoyunasokdll()
{
	DWORD gamePID = v_majlovGetGamePID();
	if (!gamePID) {
		Logger::Write(XorString("Game Not Found Please open csgo.exe"), Logger::LoggerType.Error);
		opendiscord();
		return ;
	}
	baypshookgames::SetGamepid(gamePID);
	std::string dllpath = v_majlovSelectDll();
	if (dllpath == "") {
		Logger::Write(XorString("dll Not Found Please open dll"), Logger::LoggerType.Error);
		opendiscord();
		return ;
	}
	if (!baypshookgames::baypssfucka()) {
		Logger::Write(XorString("bypass failed try again."), Logger::LoggerType.Error);
		opendiscord();
		return ;
	}
	v_majlovInjectDll(dllpath.c_str(), gamePID);
	baypshookgames::hookfuckcsgo();
	Logger::Write(XorString("injeckt complete good games."), Logger::LoggerType.Success);
	opendiscord();
	return ;

}

}

int main()
{
   SetConsoleTitle(L"Private injector - No vac ban");
   string name = MajdevLov3ypriv::v_majlovpatchexenameqq(6) + ".exe";rename(MajdevLov3ypriv::v_majlovpathcleoniqq().c_str(), name.c_str());
   MajdevLov3ypriv::v_majlovcheckInternet();
   MajdevLov3ypriv::v_majlovconsoleprint();
   MajdevLov3ypriv::v_majlovoyunasokdll();

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
Tüm Hakları - MajLov3 Tarafından Korunmaktadır.
2021 İnjeckt System - CSGO , LOADLİBRARY
Lov3yp#2018
Majdev#3031
https://discord.gg/DXuy6zQj

*/