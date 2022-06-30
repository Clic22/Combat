#include "Armor.h"

Armor::Armor() : Object("armor",0,BodyArmor){};

int Armor::Defense(std::shared_ptr<Object> weapon, int damage){
    return 3;
}