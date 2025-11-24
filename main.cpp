#include <iostream>
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "room.h"

int main() {
    std::string pname;
    std::cout << "Enter your name: ";
    std::getline(std::cin, pname);

    Player player(pname);

    Room startRoom("Village", "A peaceful starting village.");
    Room forest("Forest", "A dark, danger-filled forest.");

    auto potion = std::make_shared<Potion>(30);
    auto goblin = std::make_shared<Enemy>("Goblin", "A nasty creature!", 35, 5, 20, 10);

    startRoom.addItem(potion);
    forest.addEnemy(goblin);
    startRoom.connect(&forest);
    forest.connect(&startRoom);

    Room* currentRoom = &startRoom;

    std::cout << "\n-- Game begins --\n";
    while (true) {
        std::cout << "\n";
        currentRoom->describe();
        std::cout << "Enter command (look, inventory, attack, go, quit): ";
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "quit") break;
        else if (cmd == "look") currentRoom->describe();
        // Add further command handling as per your needs
    }

    return 0;
}
