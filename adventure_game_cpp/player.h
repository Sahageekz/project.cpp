#pragma once
#include "character.h"
#include <vector>
#include <memory>

class Item; // Forward declaration

class Player : public Character {
    std::vector<std::shared_ptr<Item>> inventory;
public:
    Player(const std::string& n);
    void addItem(std::shared_ptr<Item> item);
    void showInventory() const;
    void attack(Character& target) override;
};