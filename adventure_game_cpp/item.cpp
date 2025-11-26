#include "item.h"
#include "character.h"
#include <iostream>

Item::Item(const std::string& n, const std::string& d) : Entity(n, d) {}

Potion::Potion(int amt) : Item("Potion", "Restores health"), healAmount(amt) {}

void Potion::use(Character& c) {
    std::cout << "You use a potion to heal.\n";
    c.heal(healAmount);
}