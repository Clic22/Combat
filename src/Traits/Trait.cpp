#include "Trait.h"
#include "Warrior.h"

Trait::Trait(std::string name){
    name_=name;
}

std::string Trait::Name(){
    return name_;
}