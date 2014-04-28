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
  s.start(0, 0, 0, Direction::FORWARD);
  s.tick();
  EXPECT_TRUE(Point(0,1,0,0) == s.getHead());
}

TEST(SnakeTest, TestSizeIsOneAfterStarted) {
  Snake s(10,10,10);
  s.start(0, 0, 0, Direction::FORWARD);
  std::vector<Point> p = s.render();
  EXPECT_EQ(1, p.size());
  EXPECT_EQ(0, p.begin()->getX());
  EXPECT_EQ(0, p.begin()->getY());
  EXPECT_EQ(0, p.begin()->getZ());
  EXPECT_EQ(255, p.begin()->getBr());
}

TEST(SnakeTest, TestTailIsMoving) {
  Snake s(10,10,10, 2);
  s.start(0, 0, 0, Direction::FORWARD);
  s.tick();
  s.tick();
  std::vector<Point> p = s.render();
  EXPECT_EQ(2, p.size());
  EXPECT_TRUE(Point(0,1,0,0) == p[0]);
  EXPECT_TRUE(Point(0,2,0,0) == p[1]);
}

TEST(SnakeTest, TestCreateThrowsWhenGivesCrazyConstParams) {
  EXPECT_THROW(Snake s(10,10,10, 0), std::logic_error);
  EXPECT_THROW(Snake s(0,10,10, 10), std::logic_error);
  EXPECT_THROW(Snake s(10,0,10, 10), std::logic_error);
  EXPECT_THROW(Snake s(10,10,0, 10), std::logic_error);
}

TEST(SnakeTest, TestMove) {
  Snake s(10,10,10);
  s.start(0, 0, 0, Direction::FORWARD);
  s.tick();
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
  s.start(0, 0, 0, Direction::FORWARD);
  s.tick();
  s.setDirection(Direction::LEFT);
  s.tick();
  s.setDirection(Direction::UP);
  s.tick();
  s.tick();
  s.setDirection(Direction::RIGHT);
  s.tick();
  s.setDirection(Direction::BACKWARD);
  s.tick();
  s.setDirection(Direction::DOWN);
  s.tick();

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

TEST(SnakeTest, TestNothingHappensOnOppositeDirectionFB) {
  Snake s(3,3,3);
  s.start(0, 0, 0, Direction::FORWARD);
  s.tick();
  s.setDirection(Direction::BACKWARD);
  s.tick();
  EXPECT_TRUE(Point(0,2,0,0) == s.getHead());
}

TEST(SnakeTest, TestNothingHappensOnOppositeDirectionUD) {
  Snake s(3,3,3);
  s.start(0, 0, 0, Direction::UP);
  s.tick();
  s.setDirection(Direction::DOWN);
  s.tick();
  EXPECT_TRUE(Point(0,0,2,0) == s.getHead());
}

TEST(SnakeTest, TestNothingHappensOnOppositeDirectionLR) {
  Snake s(3,3,3);
  s.start(0, 0, 0, Direction::LEFT);
  s.tick();
  s.setDirection(Direction::RIGHT);
  s.tick();
  EXPECT_TRUE(Point(2,0,0,0) == s.getHead());
}

TEST(SnakeTest, TestCrashToWall) {
  Snake s(3,3,3);
  s.start(0, 0, 0, Direction::FORWARD);
  s.tick();
  EXPECT_EQ(Snake::MoveResult::OK, s.getLastMoveResult());
  s.tick();
  EXPECT_EQ(Snake::MoveResult::OK, s.getLastMoveResult());
  s.tick();
  EXPECT_EQ(Snake::MoveResult::WALL, s.getLastMoveResult());
}

TEST(SnakeTest, TestCatchTail) {
  Snake s(3,3,3);
  s.start(0, 0, 0, Direction::FORWARD);
  s.tick();
  EXPECT_EQ(Snake::MoveResult::OK, s.getLastMoveResult());
  s.setDirection(Direction::UP);
  s.tick();
  EXPECT_EQ(Snake::MoveResult::OK, s.getLastMoveResult());
  s.setDirection(Direction::BACKWARD);
  s.tick();
  EXPECT_EQ(Snake::MoveResult::OK, s.getLastMoveResult());
  s.setDirection(Direction::DOWN);
  s.tick();
  EXPECT_EQ(Snake::MoveResult::TAIL, s.getLastMoveResult());
}

TEST(SnakeTest, TestNotMovingAfterWallReached) {
  Snake s(3,3,3);
  s.start(0, 0, 0, Direction::FORWARD);
  s.tick();
  s.tick();
  s.tick();
  EXPECT_EQ(Snake::MoveResult::WALL, s.getLastMoveResult());
  EXPECT_TRUE(Point(0,2,0,0) == s.getHead());
  s.tick();
  EXPECT_EQ(Snake::MoveResult::WALL, s.getLastMoveResult());
  EXPECT_TRUE(Point(0,2,0,0) == s.getHead());
}

} /* namespace FadeCube */
