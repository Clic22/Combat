#include "Object.h"

Object::Object(std::string name, int damage){
    name_=name;
    damage_=damage;
}

std::string Object::Name(){
    return name_;
}

int Object::Damage(){
    return damage_;
}