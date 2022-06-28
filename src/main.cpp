#include <iostream>
#include <memory>
#include "hello.h"

int main(){
    auto hello = std::make_unique<Hello>();
    std::cout << hello->printHello() << std::endl;
    return 0;
}