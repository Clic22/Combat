#include "Object.h"
#include "Warrior.h"
#include <iostream>

Object::Object(std::string name, int damage, type type){
    name_=name;
    damage_=damage;
    type_=type;
}

std::string Object::Name(){
    return name_;
}

int Object::Damage(){
    return damage_;
}

type Object::Type(){
    return type_;
}

int  Object::BasicAttack(Warrior& attacker, Warrior& opponent, int penality){
    int damage = damage_;
    auto trait = attacker.GetTrait();
    if (trait != nullptr){
       damage = attacker.GetTrait()->BonusAttack(damage,attacker);
    }
    damage = damage - penality;
    for(const auto& [type, object] : opponent.Inventory()){
        damage -= object->Defense(std::make_shared<Object>(*this),damage);
    }

    if (damage < 0 )
    {
        damage = 0;
    }

    return damage;
}