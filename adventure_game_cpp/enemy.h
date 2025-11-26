#pragma once
#include "character.h"

class Enemy : public Character {
public:
    Enemy(const std::string& n, int hp, int atk);
    void attack(Character& target) override;
};