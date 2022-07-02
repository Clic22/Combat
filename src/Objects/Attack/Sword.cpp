#include "Sword.h"
#include "ObjectFactory.h"
#include "Warrior.h"

constexpr int weaponDamage = 5;

Sword::Sword() : Object("sword", weaponDamage,ObjectType::OneHandedWeapon){};

int Sword::Attack(const Warrior& attacker,const Warrior& opponent, int penality){
   return this->BasicAttack(attacker,opponent,penality);
}