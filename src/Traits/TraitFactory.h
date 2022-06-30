#pragma once
#include <string>
#include <memory>
#include "Trait.h"

class TraitFactory{
    public:
        TraitFactory() = default;
        std::shared_ptr<Trait> createTrait(const std::string& trait) const;
};