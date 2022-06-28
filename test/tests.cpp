#include <iostream>
#include <gtest/gtest.h>
#include "../src/hello.h"

TEST(AssertHelloTest, True) { 
    auto hello = std::make_unique<Hello>();
    ASSERT_EQ("Hello World !", hello->printHello());
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}