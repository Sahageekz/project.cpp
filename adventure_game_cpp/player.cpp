#include "player.h"
#include "item.h"
#include <iostream>

Player::Player(const std::string& n)
    : Character(n, "A brave adventurer", 100, 15) {}

void Player::addItem(std::shared_ptr<Item> item) {
    inventory.push_back(item);
    std::cout << "Added " << item->getName() << " to inventory.\n";
}

void Player::showInventory() const {
    std::cout << "--- Inventory ---\n";
    if (inventory.empty()) std::cout << "Empty\n";
    else for (const auto& item : inventory)
        std::cout << item->getName() << ": " << item->getDescription() << "\n";
    std::cout << "-----------------\n";
}

void Player::attack(Character& target) {
    std::cout << name << " attacks " << target.getName() << "!\n";
    target.takeDamage(attackPower);
}