#include "enemy.h"
#include <iostream>

Enemy::Enemy(const std::string& n, int hp, int atk)
    : Character(n, "A scary monster!", hp, atk) {}

void Enemy::attack(Character& target) {
    std::cout << name << " attacks you!\n";
    target.takeDamage(attackPower);
}