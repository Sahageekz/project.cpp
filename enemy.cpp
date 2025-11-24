#pragma once
#include "character.h"

class Enemy : public Character {
    int experienceValue;
    int goldDrop;
public:
    Enemy(const std::string& n, const std::string& d, int hp, int atk, int xp, int gold)
        : Character(n, d, hp, atk), experienceValue(xp), goldDrop(gold) {}
    int getExperienceValue() const { return experienceValue; }
    int getGoldDrop() const { return goldDrop; }
    void attack(Character& target) override {
        std::cout << name << " attacks you!\n";
        target.takeDamage(attackPower);
    }
};
