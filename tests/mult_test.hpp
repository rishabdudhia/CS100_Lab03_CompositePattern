#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

 #include "gtest/gtest.h"
 #include "../mocks/mock_funcs.hpp"
#include "../header/mult.hpp"

TEST(MultTest, MultTwoPositiveOperands) {
    SevenOpMock* var1 = new SevenOpMock();
    fiveOpMock* var2 = new fiveOpMock();
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), 37.5);
    EXPECT_EQ(test->stringify(), "(7.5*5)");
}

TEST(MultTest, MultPositiveNegativeOperands) {
    SevenOpMock* var1 = new SevenOpMock();
    NegFiveOpMock* var2 = new NegFiveOpMock();
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), -37.5);
    EXPECT_EQ(test->stringify(), "(7.5*-5)");
}

TEST(MultTest, MultOnePositiveOperandAndDivision) {
    SevenOpMock* var1 = new SevenOpMock();
   PosDivisionTwentyoneBySevenOpMock* var2 = new PosDivisionTwentyoneBySevenOpMock();
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), 22.5);
    EXPECT_EQ(test->stringify(), "(7.5*(21/7))");
}

TEST(MultTest, NegOpMultNegDivision) {
    NegFiveOpMock* var1 = new NegFiveOpMock();
    NegDivisionTwentyoneByThreeOpMock* var2 = new NegDivisionTwentyoneByThreeOpMock();
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), 35);
    EXPECT_EQ(test->stringify(), "(-5*(-21/3))");
}

TEST(MultTest, PowTimesNegSub) {
    Negpowtwo* var1 = new Negpowtwo();
    NegSubtraction* var2 = new NegSubtraction();
    Mult* test = new Mult(var1, var2);
    EXPECT_EQ(test->evaluate(), -12);
    EXPECT_EQ(test->stringify(), "((-2)**(2))*(-21/3))");
}


#endif
