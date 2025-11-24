#pragma once
#include "character.h"
#include <vector>
#include <memory>

class Item; // Forward declaration

class Player : public Character {
    int experience;
    int level;
    int gold;
    std::vector<std::shared_ptr<Item>> inventory;
public:
    Player(const std::string& n)
        : Character(n, "A brave adventurer", 100, 15), experience(0), level(1), gold(0) {}
    void addItem(std::shared_ptr<Item> item);
    void showInventory() const;
    void attack(Character& target) override;
    // Additional methods: useItem, gainExperience, levelUp etc.
};
