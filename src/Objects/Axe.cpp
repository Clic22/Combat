#include "Axe.h"
#include "ObjectFactory.h"
#include "Warrior.h"

constexpr int DAMAGE = 6;

Axe::Axe() : Object("axe", DAMAGE){};

int Axe::Attack(Warrior& opponent, int penality){
    int damage = DAMAGE - penality;
    for(std::shared_ptr<Object> object : opponent.Inventory()){
        damage -= object->Defense(std::make_shared<Object>(*this));
    }

    if (damage < 0 )
    {
        damage = 0;
    }

    return damage;
}

int Axe::Defense(std::shared_ptr<Object> weapon){
    return 0;
}