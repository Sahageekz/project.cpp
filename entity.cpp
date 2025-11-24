#pragma once
#include <string>
class Entity {
protected:
    std::string name;
    std::string description;
public:
    Entity(const std::string& n, const std::string& d) : name(n), description(d) {}
    virtual ~Entity() {}
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
};
