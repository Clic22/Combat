#include "TraitFactory.h"
#include "Vicious.h"
#include "Veteran.h"
#include <iostream>

std::shared_ptr<Trait> TraitFactory::createTrait(const std::string& trait) const {
    if (trait == "Vicious")
    {
        return std::make_shared<Vicious>();
    }
    else if (trait == "Veteran")
    {
        return std::make_shared<Veteran>();
    }
    else{
        return nullptr;
    }
}