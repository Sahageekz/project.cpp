#pragma once
#include "entity.h"
#include <iostream>

class Character; // Forward declaration

class Item : public Entity {
public:
    Item(const std::string& n, const std::string& d) : Entity(n, d) {}
    virtual void use(Character& c) = 0;
};

class Potion : public Item {
    int healAmount;
public:
    Potion(int amt) : Item("Potion", "Restores health"), healAmount(amt) {}
    void use(Character& c) override;
};

class Weapon : public Item {
    int attackBonus;
public:
    Weapon(const std::string& n, int bonus) : Item(n, "Weapon"), attackBonus(bonus) {}
    void use(Character& c) override;
};
