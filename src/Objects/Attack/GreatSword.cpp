#include "GreatSword.h"
#include "Warrior.h"
#include <iostream> 

constexpr int weaponDamage = 12;

GreatSword::GreatSword() : Object("greatSword", weaponDamage, ObjectType::TwoHandedWeapon){};

int GreatSword::Attack(const Warrior& attacker,const Warrior& opponent, int penality){
    if (attack_ < 2){
        attack_++;
        return this->BasicAttack(attacker,opponent,penality);
    }
    else{
        attack_ = 0;
        return 0;
    } 
}