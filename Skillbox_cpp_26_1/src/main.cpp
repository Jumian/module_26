#include <iostream>
#include "player.h"

int main() {
    Player* player = new Player;
    player->addTrack(Track::createTrack("Sting",std::time(nullptr),200));
    player->addTrack(Track::createTrack("Scorpions",std::time(nullptr),300));
    player->addTrack(Track::createTrack("Rammstein",std::time(nullptr),250));
    player->turnOn();
    std::cout << "Hello, World!" << std::endl;
    delete player;
    player= nullptr;
}
