#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/pow.hpp"
#include "eight_times_seven_mock.hpp"
#include "rand_mock.hpp"
#include "two_divides_four_mock.hpp"

TEST(PowTest, BasicPow) {
    Op* test1 = new Op(4);
    Op* test2 = new Op(2);
    Pow* plus = new Pow(test1, test2);
    EXPECT_EQ(plus->evaluate(), 16);
    EXPECT_EQ(plus->stringify(), "(4**2)");
}

TEST(PowTest, BasicPowNegBase){
    Op* test1 = new Op(-2);
    Op* test2 = new Op(3);
    Pow* plus = new Pow(test1, test2);
    EXPECT_EQ(plus->evaluate(), -8);
    EXPECT_EQ(plus->stringify(), "(-2**3)");
}

TEST(PowTest, PowPowPow) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(1);
    Op* test3 = new Op(8);

    Pow* plus1 = new Pow(test1, test2);
    Pow* plus2 = new Pow(test3, plus1);


    EXPECT_EQ(plus2->evaluate(), 64);
    EXPECT_EQ(plus2->stringify(), "(8**(2**1))");
}

TEST(PowTest, PowSum) {
    Op* test1 = new Op(-4);
    Op* test2 = new Op(20);
    Op* test3 = new Op(2);
    Add* plus1 = new Add(test1, test2);
    Pow* plus2 = new Pow(plus1,test3);
    EXPECT_EQ(plus2->evaluate(), 256);
    EXPECT_EQ(plus2->stringify(), "((-4+20)**2)");
}



TEST(PowTest, PowProduct) {
    Op* test = new Op(2);
    EightTimesSevenMock* fiftySix = new EightTimesSevenMock();
    Pow* plus = new Pow(fiftySix, test);
    EXPECT_EQ(plus->evaluate(), 3136);
    EXPECT_EQ(plus->stringify(), "((8*7)**2)");
}

TEST(PowTest,DivToZero) {
    Op* test = new Op(0);
    TwoDividesFourMock* two = new TwoDividesFourMock();
    Pow* plus = new Pow(two,test);
    EXPECT_EQ(plus->evaluate(), 1);
    EXPECT_EQ(plus->stringify(), "((4/2)**0)");
}

TEST(PowTest, ZeroToRand) {
    Op* test = new Op(0);
    RandMock* rand = new RandMock();
    Pow* plus = new Pow(test,rand);
    EXPECT_EQ(plus->evaluate(), 0);
    EXPECT_EQ(plus->stringify(), "(0**31)");
}

TEST (PowTest, PowMultMinusRandPlusDiv) {
    RandMock* rand = new RandMock();
    Op* one = new Op(1);
    EightTimesSevenMock* fiftySix = new EightTimesSevenMock();
    TwoDividesFourMock* two = new TwoDividesFourMock();
    Sub* plus1 = new Sub(fiftySix, rand);
    Add* plus2 = new Add(plus1, two);
    Pow* plus3 = new Pow(plus2,one);
    EXPECT_EQ(plus3->evaluate(), 27);
    EXPECT_EQ(plus3->stringify(), "((((8*7)-31)+(4/2))**1)");
}

TEST(PowTest, BasicPowNegExp) {
    Op* test1 = new Op(2);
    Op* test2 = new Op(-2);
    Pow* plus = new Pow(test1, test2);
    EXPECT_EQ(plus->evaluate(), 0.25);
    EXPECT_EQ(plus->stringify(), "(2**-2)");
}

#endif //__POW_TEST_HPP__

