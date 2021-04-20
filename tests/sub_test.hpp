#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/sub.hpp"
#include "eight_times_seven_mock.hpp"
#include "rand_mock.hpp"
#include "two_divides_four_mock.hpp"

TEST(SubTest, BasicSubsTwoPosOps) {
    Op* test1 = new Op(8);
    Op* test2 = new Op(6);
    Sub* minus = new Sub(test1, test2);
    EXPECT_EQ(minus->evaluate(), 2);
    EXPECT_EQ(minus->stringify(), "(8-6)");
}

TEST(SubTest, BasicSubTwoNegOps) {
    Op* test1 = new Op(-7);
    Op* test2 = new Op(-9);
    Sub* minus = new Sub(test1, test2);
    EXPECT_EQ(minus->evaluate(), 2);
    EXPECT_EQ(minus->stringify(), "(-7--9)");
}

TEST(SubTest, MultSubOps) {
    Op* test1 = new Op(13);
    Op* test2 = new Op(7);
    Op* test3 = new Op(12);
    Op* test4 = new Op(6);

    Sub* minus1 = new Sub(test1, test2);
    Sub* minus2 = new Sub(test3, test4);
    Sub* minus3 = new Sub(minus1, minus2);


    EXPECT_EQ(minus3->evaluate(), 0);
    EXPECT_EQ(minus3->stringify(), "((13-7)-(12-6))");
}

TEST(SubTest, SubMinusOp) {
    Op* test1 = new Op(-4);
    Op* test2 = new Op(20);
    Op* test3 = new Op(19);
    Sub* minus1 = new Sub(test1, test2);
    Sub* minus2 = new Sub(test3, minus1);
    EXPECT_EQ(minus2->evaluate(), 43);
    EXPECT_EQ(minus2->stringify(), "(19-(-4-20))");
}



TEST(SubTest, OpMinus56Mock) {
    Op* test = new Op(17);
    EightTimesSevenMock* fiftySix = new EightTimesSevenMock();
    Sub* minus = new Sub(test,fiftySix);
    EXPECT_EQ(minus->evaluate(), -39);
    EXPECT_EQ(minus->stringify(), "(17-(8*7))");
}

TEST(SubTest,ZeroMinus2Mock ) {
    Op* test = new Op(0);
    TwoDividesFourMock* two = new TwoDividesFourMock();
    Sub* minus = new Sub(test,two);
    EXPECT_EQ(minus->evaluate(), -2);
    EXPECT_EQ(minus->stringify(), "(0-(4/2))");
}

TEST(SubTest, RandMinusOp) {
    Op* test = new Op(-12);
    RandMock* rand = new RandMock();
    Sub* minus = new Sub(rand,test);
    EXPECT_EQ(minus->evaluate(), 43);
    EXPECT_EQ(minus->stringify(), "(31--12)");
}

TEST (SubTest, RandMinusDiffOfMultAndDiv) {
    RandMock* rand = new RandMock();
    EightTimesSevenMock* fiftySix = new EightTimesSevenMock();
    TwoDividesFourMock* two = new TwoDividesFourMock();
    Sub* minus1 = new Sub(fiftySix, two);
    Sub* minus2 = new Sub(rand, minus1);
    EXPECT_EQ(minus2->evaluate(), -23);
    EXPECT_EQ(minus2->stringify(), "(31-((8*7)-(4/2)))");
}
#endif //__SUB_TEST_HPP__

