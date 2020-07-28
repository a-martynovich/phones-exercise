#include "phones.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"


TEST(parseNumber, Spaces) {
    EXPECT_EQ(parseNumber("123"), "123");
    EXPECT_EQ(parseNumber(" 123"), "123");
    EXPECT_EQ(parseNumber("123 456"), "123456");
    EXPECT_EQ(parseNumber("123 456 "), "123456");
    EXPECT_EQ(parseNumber("123  456  "), "123456");
}

TEST(parseNumber, Simple) {
    EXPECT_EQ(parseNumber("30 2 5 58"), "302558");
    EXPECT_EQ(parseNumber("2 10 69 30 6 60 4"), "21069306604");
    EXPECT_EQ(parseNumber("6 97 400 23 7 40 5"), "697400237405");
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

TEST(validatePhone, Simple) {
    EXPECT_EQ(validatePhone("302558"), false);
    EXPECT_EQ(validatePhone("2106930664"), true);
    EXPECT_EQ(validatePhone("21069306604"), false);
    EXPECT_EQ(validatePhone("00306974092252"), true);
}

TEST(ambiguities, Simple) {
    EXPECT_THAT(ambiguities("2 10 6 9 30 6 6 4"), testing::ElementsAre(
       std::make_tuple("2106930664", true),
       std::make_tuple("210693664", false)
    ));
    EXPECT_THAT(ambiguities("2 10 69 30 6 6 4"), testing::ElementsAre(
        std::make_tuple("21060930664", false),
        std::make_tuple("2106930664", true),
        std::make_tuple("2106093664", true),
        std::make_tuple("210693664", false)
    ));
    EXPECT_THAT(ambiguities("0 0 30 69 700 24 1 3 50 2"), testing::ElementsAre(
        std::make_tuple("003060970020413502", false),
        std::make_tuple("00306970020413502", false),
        std::make_tuple("0030609720413502", false),
        std::make_tuple("003069720413502", false),
        std::make_tuple("003060972413502", false),
        std::make_tuple("00306972413502", true),
        std::make_tuple("00306097002041352", false),
        std::make_tuple("0030697002041352", false),
        std::make_tuple("003060972041352", false),
        std::make_tuple("00306972041352", true),
        std::make_tuple("00306097241352", false),
        std::make_tuple("0030697241352", false)
    ));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
