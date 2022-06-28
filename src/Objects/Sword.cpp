#include "Sword.h"
#include "ObjectFactory.h"
#include "Warrior.h"

constexpr int DAMAGE = 5;

Sword::Sword() : Object("sword", DAMAGE){};

int Sword::Attack(Warrior& opponent){
    int damage = DAMAGE;

    for(std::shared_ptr<Object> object : opponent.Inventory()){
        damage -= object->Defense(std::make_shared<Object>(*this));
    }

    if (damage < 0 )
    {
        damage = 0;
    }

    return damage;
}

int Sword::Defense(std::shared_ptr<Object> weapon){
    return 0;
}