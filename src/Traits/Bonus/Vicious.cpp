#include "Vicious.h"
#include "Warrior.h"
#include <iostream>


Vicious::Vicious() : Trait("Vicious"){};

int Vicious::BonusAttack(int damage,const Warrior& attacker){
    if (blows < maxBlow)
    {
        damage += bonusDamage;
        blows++;
    }
    return damage;
}