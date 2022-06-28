#pragma once
#include <string>
#include <memory>
#include "Object.h"

class ObjectFactory{
    public:
        ObjectFactory() = default;
        std::shared_ptr<Object> createObject(const std::string& object) const;
};