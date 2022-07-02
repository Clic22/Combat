#include "Trait.h"
#include "Warrior.h"

Trait::Trait(const std::string& name) : name_(name){
}

std::string Trait::Name() const{
    return name_;
}