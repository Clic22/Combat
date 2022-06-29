#include "GreatSword.h"
#include "ObjectFactory.h"
#include "Warrior.h"

constexpr int DAMAGE = 12;

GreatSword::GreatSword() : Object("greatSword", DAMAGE){};

int GreatSword::Attack(Warrior& opponent, int penality){
    if (attack_ < 2){
        int damage = DAMAGE - penality;
        for(std::shared_ptr<Object> object : opponent.Inventory()){
            damage -= object->Defense(std::make_shared<Object>(*this));
        }

        if (damage < 0 )
        {
            damage = 0;
        }
        attack_++;
        return damage;
    }
    else{
        attack_ = 0;
        return 0;
    }
    
}

int GreatSword::Defense(std::shared_ptr<Object> weapon){
    return 0;
}