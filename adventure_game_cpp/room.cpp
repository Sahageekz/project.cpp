#include "room.h"
#include <iostream>

Room::Room(const std::string& n, const std::string& d): name(n), description(d) {}

void Room::addItem(std::shared_ptr<Item> item) { items.push_back(item); }

void Room::addEnemy(std::shared_ptr<Enemy> enemy) { enemies.push_back(enemy); }

void Room::connect(Room* room) { connectedRoom = room; }

Room* Room::nextRoom() const { return connectedRoom; }

void Room::describe() const {
    std::cout << "\n=== " << name << " ===\n" << description << "\n";
    if (!items.empty()) {
        std::cout << "Items: ";
        for (const auto& item : items) std::cout << item->getName() << " ";
        std::cout << "\n";
    }
    if (!enemies.empty()) {
        std::cout << "Enemies: ";
        for (const auto& enemy : enemies) std::cout << enemy->getName() << " ";
        std::cout << "\n";
    }
}