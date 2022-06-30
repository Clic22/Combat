#include <iostream>
#include <memory>
#include "Swordsman.h"
#include "Viking.h"
#include "Highlander.h"


static void SwordsmanVsViking()
{
    Swordsman swordsman;
    Viking viking;
    swordsman.Engage(viking);

    std::cout << "Swordsman (0) = " << swordsman.HitPoints() << std::endl;
    std::cout << "Viking (35) = " << viking.HitPoints() << std::endl;
    std::cout << std::endl;
}

static void SwordsmanWithBucklerVsVikingWithBuckler()
{
    Swordsman swordsman;
    swordsman.Equip("buckler");
    Viking viking;
    viking.Equip("buckler");
    swordsman.Engage(viking);

    std::cout << "SwordsmanWithBuckler (0) = " << swordsman.HitPoints() << std::endl;
    std::cout << "VikingWithBuckler (70) = " << viking.HitPoints() << std::endl;
    std::cout << std::endl;
}

static void ArmoredSwordsmanVsHighlander()
{
    Highlander highlander;
    Swordsman swordsman;
    swordsman.Equip("buckler");
    swordsman.Equip("armor");
    swordsman.Engage(highlander);

    std::cout << "ArmoredSwordsman (0) = " << swordsman.HitPoints() << std::endl;
    std::cout << "Highlander (10) = " << highlander.HitPoints() << std::endl;
    std::cout << std::endl;
}

static void ViciousSwordsmanVsVeteranHighlander()
{
    Swordsman swordsman("Vicious");
    swordsman.Equip("axe");
    swordsman.Equip("buckler");
    swordsman.Equip("armor");
    Highlander highlander("Veteran");
    swordsman.Engage(highlander);
    
    std::cout << "ViciousSwordsman (1) = " << swordsman.HitPoints() << std::endl;
    std::cout << "VeteranHighlander (0) = " << highlander.HitPoints() << std::endl;
    std::cout << std::endl;
}

int main(int ac, char** av)
{
    
    SwordsmanVsViking();
    
    SwordsmanWithBucklerVsVikingWithBuckler();
    
    ArmoredSwordsmanVsHighlander();
    
    ViciousSwordsmanVsVeteranHighlander();
    
    return 0;
}