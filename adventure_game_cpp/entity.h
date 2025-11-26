#pragma once
#include <string>

class Entity {
protected:
    std::string name;
    std::string description;
public:
    Entity(const std::string& n, const std::string& d);
    virtual ~Entity() {}
    std::string getName() const;
    std::string getDescription() const;
};