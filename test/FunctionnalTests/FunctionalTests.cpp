#include <iostream>
#include <gtest/gtest.h>
#include "Swordsman.h"
#include "Viking.h"
#include "Highlander.h"

TEST(SwordsmanVsViking, Default) { 
    Swordsman swordsman;
    Viking viking;
    swordsman.Engage(viking);
    ASSERT_EQ(0,swordsman.HitPoints());
    ASSERT_EQ(35,viking.HitPoints());
}

TEST(SwordsmanWithBucklerVsVikingWithBuckler, Default) {
    Swordsman swordsman;
    swordsman.Equip("buckler");
    Viking viking;
    viking.Equip("buckler");
    swordsman.Engage(viking);

    ASSERT_EQ(0,swordsman.HitPoints());
    ASSERT_EQ(70,viking.HitPoints());
}

TEST(ArmoredSwordsmanVsHighlander, Default){
    Highlander highlander;
    Swordsman swordsman;
    swordsman.Equip("buckler");
    swordsman.Equip("armor");
    swordsman.Engage(highlander);

    ASSERT_EQ(0,swordsman.HitPoints());
    ASSERT_EQ(10,highlander.HitPoints());
}

TEST(ViciousSwordsmanVsVeteranHighlander, Default){
    Swordsman swordsman("Vicious");
    swordsman.Equip("axe");
    swordsman.Equip("buckler");
    swordsman.Equip("armor");
    Highlander highlander("Veteran");
    swordsman.Engage(highlander);
    
    ASSERT_EQ(0,highlander.HitPoints());
    ASSERT_EQ(1,swordsman.HitPoints());
}