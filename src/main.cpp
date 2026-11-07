#include <windows.h>
#include <iostream>
#include <thread>

#include "memory.h"
#include "overlay.h"
#include "config.h"

int main() {
    SetConsoleTitle("Fortnite External Cheat");
    std::cout << "[*] waiting for FortniteClient-Win64-Shipping.exe" << std::endl;

    while (!Memory::Attach("FortniteClient-Win64-Shipping.exe")) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "[+] attached" << std::endl;

    Config::Load("config.json");
    Overlay::Init();
    Overlay::Run();

    return 0;
}
