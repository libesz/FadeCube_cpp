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

TEST(SnakeTest, TestGetHead) {
  Snake s(10,10,10);
  s.start(0, 0, 0, Snake::Direction::FORWARD);
  s.move();
  EXPECT_TRUE(Point(0,1,0,0) == s.getHead());
}

TEST(SnakeTest, TestSizeIsOneAfterStarted) {
	Snake s(10,10,10);
	s.start(0, 0, 0, Snake::Direction::FORWARD);
  std::vector<Point> p = s.render();
  EXPECT_EQ(1, p.size());
  EXPECT_EQ(0, p.begin()->getX());
  EXPECT_EQ(0, p.begin()->getY());
  EXPECT_EQ(0, p.begin()->getZ());
  EXPECT_EQ(255, p.begin()->getBr());
}

TEST(SnakeTest, TestMove) {
  Snake s(10,10,10);
  s.start(0, 0, 0, Snake::Direction::FORWARD);
  s.move();
  std::vector<Point> p = s.render();
  EXPECT_EQ(2, p.size());
}

TEST(SnakeTest, TestDirectionChange) {
  Snake s(10,10,10);
  Point p0(0,0,0,0);
  Point p1(0,1,0,0);
  Point p2(1,1,0,0);
  Point p3(1,1,1,0);
  Point p4(1,1,2,0);
  Point p5(0,1,2,0);
  Point p6(0,0,2,0);
  Point p7(0,0,1,0);
  s.start(0, 0, 0, Snake::Direction::FORWARD);
  s.move();
  s.setDirection(Snake::Direction::LEFT);
  s.move();
  s.setDirection(Snake::Direction::UP);
  s.move();
  s.move();
  s.setDirection(Snake::Direction::RIGHT);
  s.move();
  s.setDirection(Snake::Direction::BACKWARD);
  s.move();
  s.setDirection(Snake::Direction::DOWN);
  s.move();

  std::vector<Point> p = s.render();
  Point pa = p[0];
  EXPECT_TRUE(p[0] == p0);
  EXPECT_TRUE(p[1] == p1);
  EXPECT_TRUE(p[2] == p2);
  EXPECT_TRUE(p[3] == p3);
  EXPECT_TRUE(p[4] == p4);
  EXPECT_TRUE(p[5] == p5);
  EXPECT_TRUE(p[6] == p6);
  EXPECT_TRUE(p[7] == p7);

}

TEST(SnakeTest, TestCrashToWall) {
  Snake s(3,3,3);
  s.start(0, 0, 0, Snake::Direction::FORWARD);
  EXPECT_EQ(Snake::MoveResult::OK, s.move());
  EXPECT_EQ(Snake::MoveResult::OK, s.move());
  EXPECT_EQ(Snake::MoveResult::WALL, s.move());
}

TEST(SnakeTest, TestCatchTail) {
  Snake s(3,3,3);
  s.start(0, 0, 0, Snake::Direction::FORWARD);
  EXPECT_EQ(Snake::MoveResult::OK, s.move());
  s.setDirection(Snake::Direction::UP);
  EXPECT_EQ(Snake::MoveResult::OK, s.move());
  s.setDirection(Snake::Direction::BACKWARD);
  EXPECT_EQ(Snake::MoveResult::OK, s.move());
  s.setDirection(Snake::Direction::DOWN);
  EXPECT_EQ(Snake::MoveResult::TAIL, s.move());
}

} /* namespace FadeCube */
