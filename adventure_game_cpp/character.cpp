#include "character.h"

Character::Character(const std::string& n, const std::string& d, int hp, int atk)
    : Entity(n, d), health(hp), maxHealth(hp), attackPower(atk), isAlive(true) {}

int Character::getHealth() const { return health; }

bool Character::alive() const { return isAlive; }

void Character::takeDamage(int dmg) {
    health -= dmg;
    if (health <= 0) { health = 0; isAlive = false; }
    std::cout << name << " takes " << dmg << " damage! (" << health << "/" << maxHealth << ")\n";
}

void Character::heal(int amt) {
    health += amt;
    if (health > maxHealth) health = maxHealth;
    std::cout << name << " heals " << amt << " HP! (" << health << "/" << maxHealth << ")\n";
}