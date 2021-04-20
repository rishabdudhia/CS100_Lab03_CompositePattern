#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/rand.hpp"

TEST(RandTest, RandEvaluate) {
    Rand* test = new Rand();
   //EXPECT_WITHIN_INCLUSIVE(0,99,test->evaluate());
   //EXPECT_STREQ(test->stringify(),
  //EXPECT_THAT(test->evaluate(), AllOf(Ge(0),Le(99)));
	EXPECT_TRUE((test->evaluate() >= 0) && (test->evaluate() <= 99));
}

#endif 
