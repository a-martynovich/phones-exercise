#include "phones.h"
#include "gtest/gtest.h"

TEST(parseNumber, Simple) {
    EXPECT_EQ(parseNumber("123"), "123");
    EXPECT_EQ(parseNumber("123 456"), "123456");
    EXPECT_EQ(parseNumber("123 456 "), "123456");
    EXPECT_EQ(parseNumber("123  456  "), "123456");
}

TEST(parseNumber, Empty) {
    EXPECT_EQ(parseNumber(""), "");
    EXPECT_EQ(parseNumber(" "), "");
    EXPECT_EQ(parseNumber("  "), "");
}

TEST(parseNumber, Invalid) {
    EXPECT_EQ(parseNumber("a"), "");
    EXPECT_EQ(parseNumber("123a"), "");
    EXPECT_EQ(parseNumber("123 456a"), "");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
