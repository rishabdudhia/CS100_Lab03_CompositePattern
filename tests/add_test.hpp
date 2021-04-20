#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/add.hpp"
#include "eight_times_seven_mock.hpp"
#include "rand_mock.hpp"
#include "two_divides_four_mock.hpp"

TEST(AddTest, BasicAddTwoPosOps) {
    Op* test1 = new Op(8);
    Op* test2 = new Op(6);
    Add* plus = new Add(test1, test2);
    EXPECT_EQ(plus->evaluate(), 14);
    EXPECT_EQ(plus->stringify(), "(8+6)");
}

TEST(AddTest, BasicAddTwoNegOps) {
    Op* test1 = new Op(-7);
    Op* test2 = new Op(-9);
    Add* plus = new Add(test1, test2);
    EXPECT_EQ(plus->evaluate(), -16);
    EXPECT_EQ(plus->stringify(), "(-7+-9)");
}

TEST(AddTest, MultAddOps) {
    Op* test1 = new Op(13);
    Op* test2 = new Op(7);
    Op* test3 = new Op(12);
    Op* test4 = new Op(6);

    Add* plus1 = new Add(test1, test2);
    Add* plus2 = new Add(test3, test4);
    Add* plus3 = new Add(plus1, plus2);


    EXPECT_EQ(plus3->evaluate(), 38);
    EXPECT_EQ(plus3->stringify(), "((13+7)+(12+6))");
}

TEST(AddTest, AddPlusOp) {
    Op* test1 = new Op(-4);
    Op* test2 = new Op(20);
    Op* test3 = new Op(19);
    Add* plus1 = new Add(test1, test2);
    Add* plus2 = new Add(test3, plus1);
    EXPECT_EQ(plus2->evaluate(), 35);
    EXPECT_EQ(plus2->stringify(), "(19+(-4+20))");
}



TEST(AddTest, OpPlus56Mock) {
    Op* test = new Op(17);
    EightTimesSevenMock* fiftySix = new EightTimesSevenMock();
    Add* plus = new Add(test,fiftySix);
    EXPECT_EQ(plus->evaluate(), 73);
    EXPECT_EQ(plus->stringify(), "(17+(8*7))");
}

TEST(AddTest,ZeroPlus2Mock ) {
    Op* test = new Op(0);
    TwoDividesFourMock* two = new TwoDividesFourMock();
    Add* plus = new Add(test,two);
    EXPECT_EQ(plus->evaluate(), 2);
    EXPECT_EQ(plus->stringify(), "(0+(4/2))");
}

TEST(AddTest, RandPlusOp) {
    Op* test = new Op(-12);
    RandMock* rand = new RandMock();
    Add* plus = new Add(rand,test);
    EXPECT_EQ(plus->evaluate(), 19);
    EXPECT_EQ(plus->stringify(), "(31+-12)");
}

TEST (AddTest, RandPlusSumOfMultAndDiv) {
    RandMock* rand = new RandMock();
    EightTimesSevenMock* fiftySix = new EightTimesSevenMock();
    TwoDividesFourMock* two = new TwoDividesFourMock();
    Add* plus1 = new Add(fiftySix, two);
    Add* plus2 = new Add(rand, plus1);
    EXPECT_EQ(plus2->evaluate(), 89);
    EXPECT_EQ(plus2->stringify(), "(31+((8*7)+(4/2)))");
}
#endif //__ADD_TEST_HPP__

