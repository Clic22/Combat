#include "Armor.h"

Armor::Armor() : Object("armor",0){};

int Armor::Attack(Warrior& opponent, int penality){
    return 0;
}

int Armor::Defense(std::shared_ptr<Object> weapon){
    return 3;
}