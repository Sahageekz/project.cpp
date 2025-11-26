#include "entity.h"

Entity::Entity(const std::string& n, const std::string& d) : name(n), description(d) {}

std::string Entity::getName() const { return name; }

std::string Entity::getDescription() const { return description; }
