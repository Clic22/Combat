#include "Axe.h"
#include "ObjectFactory.h"
#include "Warrior.h"
#include <iostream>

constexpr int weaponDamage = 6;

Axe::Axe() : Object("axe", weaponDamage,OneHandedWeapon){};

int Axe::Attack(Warrior& attacker, Warrior& opponent, int penality){
    return this->BasicAttack(attacker,opponent,penality);

}