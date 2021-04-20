#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

 #include "gtest/gtest.h"
 #include "../mocks/mock_funcs.hpp"
#include "../header/div.hpp"

TEST(DivTest, DivTwoPositiveOperands) {
    SevenOpMock* var1;
    fiveOpMock* var2;
    Div* test = new Div(var1, var2);
    EXPECT_EQ(test->evaluate(), 1.5);
    EXPECT_EQ(test->stringify(), "(7.5/5)");
}

TEST(DivTest, DivPositiveNegativeOperands) {
    SevenOpMock* var1;
    NegFiveOpMock* var2;
    Div* test = new Div(var1, var2);
    EXPECT_EQ(test->evaluate(), -1.5);
    EXPECT_EQ(test->stringify(), "(7.5/-5)");
}

TEST(DivTest, DivOnePositiveOperandAndDivision) {
    SevenOpMock* var1;
   PosDivisionTwentyoneBySevenOpMock* var2;
    Div* test = new Div(var1, var2);
    EXPECT_EQ(test->evaluate(), 2.5);
    EXPECT_EQ(test->stringify(), "(7.5/(21/7))");
}

TEST(DivTest, NegDivision) {
    SevenF* var2;
    NegDivisionTwentyoneByThreeOpMock* var1;
    Div* test = new Div(var1, var2);
    EXPECT_EQ(test->evaluate(), -1);
    EXPECT_EQ(test->stringify(), "((-21/3)/7)");
}

TEST(DivTest, PowDivNegSub) {
    Negpowtwo* var1;
    NegSubtraction* var2;
    Div* test = new Div(var1, var2);
    EXPECT_EQ(test->evaluate(), 0.5714);
    EXPECT_EQ(test->stringify(), "((-2)**(2))/(-21/3))");
}


#endif
