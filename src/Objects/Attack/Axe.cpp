#include "Axe.h"
#include "ObjectFactory.h"
#include "Warrior.h"
#include <iostream>

constexpr int weaponDamage = 6;

Axe::Axe() : Object("axe", weaponDamage,ObjectType::OneHandedWeapon){};

int Axe::Attack(const Warrior& attacker,const Warrior& opponent, int penality){
    return this->BasicAttack(attacker,opponent,penality);

}