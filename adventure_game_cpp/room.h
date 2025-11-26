#pragma once
#include <string>
#include <vector>
#include <memory>
#include "entity.h"
#include "enemy.h"
#include "item.h"

class Room {
    std::string name, description;
    std::vector<std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<Enemy>> enemies;
    Room* connectedRoom = nullptr; // For simple link; can expand to map<string, Room*> for directions
public:
    Room(const std::string& n, const std::string& d);
    void addItem(std::shared_ptr<Item> item);
    void addEnemy(std::shared_ptr<Enemy> enemy);
    void connect(Room* room);
    void describe() const;
    Room* nextRoom() const;
};