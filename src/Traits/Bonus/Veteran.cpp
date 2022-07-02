#include "Veteran.h"
#include "Warrior.h"

Veteran::Veteran() : Trait("Veteran"){};

int Veteran::BonusAttack(int damage,const Warrior& attacker){
    if (attacker.HitPoints() < attacker.MaxHealth()*0.3){
        damage *= 2;
    }
    return damage;
}