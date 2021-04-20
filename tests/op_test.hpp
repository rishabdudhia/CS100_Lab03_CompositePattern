#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/op.hpp"

TEST(OpTest, OpEvaluatePositiveWhole) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
    EXPECT_EQ(test->stringify(), "8");
}

TEST(OpTest, OpEvaluatePosititveDecimal) {
    Op* test = new Op(18.4);
    EXPECT_EQ(test->evaluate(), 18.4);
    EXPECT_EQ(test->stringify(), "18.4");
}

TEST(OpTest, OpZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ (test->stringify(), "0");
}

TEST(OpTest, OpNegativeWhole) {
    Op* test = new Op(-12);
    EXPECT_EQ(test->evaluate(), -12);
    EXPECT_EQ(test->stringify(), "-12");
}

TEST (OpTest, OpNegativeDecimal) {
    Op* test = new Op(-2.8);
    EXPECT_EQ(test->evaluate(), -2.8);
    EXPECT_EQ(test->stringify(), "-2.8");
}
#endif //__OP_TEST_HPP__
