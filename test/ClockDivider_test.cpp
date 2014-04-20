/*
 * ClockDivider_test.cpp
 *
 *  Created on: Apr 20, 2014
 *      Author: libesz
 */

#include <ClockDivider.h>
#include "dummy.cpp"
#include <gtest/gtest.h>

namespace FadeCube {
TEST(ClockDividerTest, TestNormal) {
  DummySchedulable *s = new DummySchedulable();
  ClockDivider cd(2, s);
  cd.tick();
  cd.tick();
  EXPECT_EQ(1, s->getTickCount());
}

TEST(ClockDividerTest, TestWithZero) {
  DummySchedulable *s = new DummySchedulable();
  EXPECT_THROW(ClockDivider cd(0, s), std::logic_error);
}

} /* namespace FadeCube */
