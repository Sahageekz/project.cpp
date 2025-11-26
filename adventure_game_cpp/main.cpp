#include <iostream>
#include <memory>
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "room.h"

int main() {
    std::string pname;
    std::cout << "Enter your name: ";
    std::getline(std::cin, pname);

    Player player(pname);

    auto potion = std::make_shared<Potion>(30);
    auto goblin = std::make_shared<Enemy>("Goblin", 50, 8);

    Room room1("Starting Room", "A small little room to begin your adventure.");
    Room room2("Monster Room", "A dangerous monster waits here...");

    room1.addItem(potion);
    room2.addEnemy(goblin);
    room1.connect(&room2);
    room2.connect(&room1);

    Room* current = &room1;

    while (true) {
        current->describe();
        std::cout << "Command (look/inventory/attack/go/quit): ";
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "look") current->describe();
        else if (cmd == "inventory") player.showInventory();
        else if (cmd == "go") {
            if (current->nextRoom()) current = current->nextRoom();
            else std::cout << "Can't go anywhere!\n";
        }
        else if (cmd == "attack" && current == &room2) {
            if (goblin->alive()) player.attack(*goblin);
            else std::cout << "No living enemies.\n";
        }
        else if (cmd == "quit") break;
        else std::cout << "Unknown command.\n";
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}