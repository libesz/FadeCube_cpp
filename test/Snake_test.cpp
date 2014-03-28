/*
 * Snake_test.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <Snake.h>
#include <gtest/gtest.h>
#include <stdexcept>

namespace FadeCube {

TEST(SnakeTest, TestCreateAndThrowsBeforeStarted) {
	Snake s(10,10,10);
	EXPECT_THROW(s.render(), std::logic_error );
}

TEST(SnakeTest, TestSizeIsOneAfterStarted) {
	Snake s(10,10,10);
	s.start(0, 0, 0, Snake::direction::FORWARD);
  std::vector<Point> p = s.render();
  EXPECT_EQ(1, p.size());
  EXPECT_EQ(0, p.begin()->getX());
  EXPECT_EQ(0, p.begin()->getY());
  EXPECT_EQ(0, p.begin()->getZ());
  EXPECT_EQ(255, p.begin()->getBr());
}

TEST(SnakeTest, TestMove) {
  Snake s(10,10,10);
  s.start(0, 0, 0, Snake::direction::FORWARD);
  s.move();
  std::vector<Point> p = s.render();
  EXPECT_EQ(2, p.size());
}
} /* namespace FadeCube */
