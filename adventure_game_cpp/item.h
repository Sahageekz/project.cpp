#pragma once
#include "entity.h"
#include <memory>

class Character; // Forward declaration

class Item : public Entity {
public:
    Item(const std::string& n, const std::string& d);
    virtual void use(Character& c) = 0;
};

class Potion : public Item {
    int healAmount;
public:
    Potion(int amt);
    void use(Character& c) override;
};