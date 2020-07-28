#include "phones.h"
#include "gtest/gtest.h"

//TEST(parseNumber, Spaces) {
//    EXPECT_EQ(parseNumber("123"), "123");
//    EXPECT_EQ(parseNumber(" 123"), "123");
//    EXPECT_EQ(parseNumber("123 456"), "123456");
//    EXPECT_EQ(parseNumber("123 456 "), "123456");
//    EXPECT_EQ(parseNumber("123  456  "), "123456");
//}
//
//TEST(parseNumber, Simple) {
//    EXPECT_EQ(parseNumber("30 2 5 58"), "302558");
//    EXPECT_EQ(parseNumber("2 10 69 30 6 60 4"), "21069306604");
//    EXPECT_EQ(parseNumber("6 97 400 23 7 40 5"), "697400237405");
//}
//
//TEST(parseNumber, Empty) {
//    EXPECT_EQ(parseNumber(""), "");
//    EXPECT_EQ(parseNumber(" "), "");
//    EXPECT_EQ(parseNumber("  "), "");
//}
//
//TEST(parseNumber, Invalid) {
//    EXPECT_EQ(parseNumber("a"), "");
//    EXPECT_EQ(parseNumber("123a"), "");
//    EXPECT_EQ(parseNumber("123 456a"), "");
//}
//
//TEST(validatePhone, Simple) {
//    EXPECT_EQ(validatePhone("302558"), false);
//    EXPECT_EQ(validatePhone("2106930664"), true);
//    EXPECT_EQ(validatePhone("21069306604"), false);
//    EXPECT_EQ(validatePhone("00306974092252"), true);
//}

TEST(ambiguities, Simple) {
    ambiguities("200 20 5 1 400 500 50 40 5 1 500 6 5000 4");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
 0 2  0,1
 0 1  1,1
 0 0  2,1
 1 1  0,2
 1 0  2,1
 2 0  0,3

 a00 b0 c, ab0 c, abc
 
 123: 100 20 3, 120 3, 123
 */
