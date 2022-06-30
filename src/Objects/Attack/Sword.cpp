#include "Sword.h"
#include "ObjectFactory.h"
#include "Warrior.h"

constexpr int weaponDamage = 5;

Sword::Sword() : Object("sword", weaponDamage,OneHandedWeapon){};

int Sword::Attack(Warrior& attacker, Warrior& opponent, int penality){
   return this->BasicAttack(attacker,opponent,penality);
}