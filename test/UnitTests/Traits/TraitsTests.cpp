#include <iostream>
#include <gtest/gtest.h>
#include "Swordsman.h"
#include "Viking.h"
#include "Highlander.h"
#include "ObjectFactory.h"
#include "Object.h"
#include "TraitFactory.h"

TEST(Trait, Vicious) { 
    TraitFactory factory;
    std::shared_ptr<Trait> vicious = factory.createTrait("Vicious");

    int damage = 10;
    Swordsman swordsman;

    ASSERT_EQ(damage+20,vicious->BonusAttack(damage,swordsman));
    ASSERT_EQ(damage+20,vicious->BonusAttack(damage,swordsman));
    ASSERT_EQ(damage,vicious->BonusAttack(damage,swordsman));
}

TEST(Trait, Veteran) { 
    TraitFactory factory;
    std::shared_ptr<Trait> veteran = factory.createTrait("Veteran");

    int damage = 20;
    
    Swordsman Swordsman;

    ASSERT_EQ(damage,veteran->BonusAttack(damage, Swordsman));
    Swordsman.HitPoints(29);
    ASSERT_EQ(damage*2,veteran->BonusAttack(damage, Swordsman));
    Swordsman.HitPoints(10);
    ASSERT_EQ(damage*2,veteran->BonusAttack(damage, Swordsman));
    Swordsman.HitPoints(1);
    ASSERT_EQ(damage*2,veteran->BonusAttack(damage, Swordsman));
    Swordsman.HitPoints(30);
    ASSERT_EQ(damage,veteran->BonusAttack(damage, Swordsman));
}