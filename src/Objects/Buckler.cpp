#include "Buckler.h"


Buckler::Buckler() : Object("buckler",DAMAGE){};

int Buckler::Attack(Warrior& opponent, int penality){
    return 0;
}

int Buckler::Defense(std::shared_ptr<Object> weapon){
    if (durability_ > 0 && block_){
        block_ = false;
        if (weapon->Name() == "axe"){
            durability_--;
        }
        return weapon->Damage();
    }
    else{
        block_ = true;
        return 0;
    }  
}