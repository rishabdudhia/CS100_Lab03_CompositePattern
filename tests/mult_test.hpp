#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "../mocks/mock_funcs.hpp"
#include "../header/mult.hpp"

TEST(MultTest, MultTwoPositiveOperands) {
    SevenOpMock* var1;
    fiveOpMock* var2;
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), 37.5);
    EXPECT_EQ(test->stringify(), "(7.5*5)");
}

TEST(MultTest, MultPositiveNegativeOperands) {
    SevenOpMock* var1;
    NegFiveOpMock* var2;
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), -37.5);
    EXPECT_EQ(test->stringify(), "(7.5*-5)");
}

TEST(MultTest, MultOnePositiveOperandAndDivision) {
    SevenOpMock* var1;
   PosDivisionTwentyoneBySevenOpMock* var2;
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), 22.5);
    EXPECT_EQ(test->stringify(), "(7.5*(21/7))");
}

TEST(MultTest, NegOpMultNegDivision) {
    NegFiveOpMock* var1;
    NegDivisionTwentyoneByThreeOpMock* var2;
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), 35);
    EXPECT_EQ(test->stringify(), "(-5*(-21/3))");
}

TEST(MultTest, PowTimesNegSub) {
    Negpowtwo* var1;
    NegSubtraction* var2;
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), -12);
    EXPECT_EQ(test->stringify(), "((-2)**(2))*(-21/3))");
}


#endif
