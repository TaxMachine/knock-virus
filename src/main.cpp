#include <iostream>
#include <random>
#include <windows.h>

void playSound() {
    BOOL played = PlaySound("knock_sound", nullptr, SND_RESOURCE | SND_SYNC);
    if (!played) {
        std::cerr << "Error: " << GetLastError() << std::endl;
    }
}

long getRandomHour() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3600);
    return dis(gen) * 1000;
}

int main() {
    while (true) {
        const long randomInterval = getRandomHour();
        std::cout << "Next knock in " << randomInterval / 1000 << " seconds" << std::endl;
        Sleep(randomInterval);
        playSound();
    }
}
