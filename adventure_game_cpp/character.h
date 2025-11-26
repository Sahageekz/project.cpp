#pragma once
#include "entity.h"
#include <iostream>

class Character : public Entity {
protected:
    int health;
    int maxHealth;
    int attackPower;
    bool isAlive;
public:
    Character(const std::string& n, const std::string& d, int hp, int atk);
    virtual ~Character() {}
    int getHealth() const;
    bool alive() const;
    void takeDamage(int dmg);
    void heal(int amt);
    virtual void attack(Character& target) = 0;
};