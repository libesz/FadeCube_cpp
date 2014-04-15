/*
 * Snake.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <Snake.h>
#include <vector>
#include <stdexcept>

namespace FadeCube {

Snake::Snake(int newSpaceX, int newSpaceY, int newSpaceZ, int newSize) :
    spaceX(newSpaceX), spaceY(newSpaceY), spaceZ(newSpaceZ), d(
        Direction::FORWARD), size(newSize) {
}

Snake::~Snake() {
  // TODO Auto-generated destructor stub
}

const std::vector<Point> Snake::render() const {
  if (!body.size())
    throw std::logic_error("Snake is not started.");
  return body;
}

void Snake::start(int newX, int newY, int newZ, Direction newD) {
  setDirection(newD);
  body.push_back(Point(newX, newY, newZ, 255));
}

Snake::MoveResult Snake::move() {
  auto oldHead = body.back();
  Point newHead(oldHead);

  switch (d) {
  case Direction::FORWARD:
    newHead.setY(newHead.getY() + 1);
    break;
  case Direction::BACKWARD:
    newHead.setY(newHead.getY() - 1);
    break;
  case Direction::LEFT:
    newHead.setX(newHead.getX() + 1);
    break;
  case Direction::RIGHT:
    newHead.setX(newHead.getX() - 1);
    break;
  case Direction::UP:
    newHead.setZ(newHead.getZ() + 1);
    break;
  case Direction::DOWN:
    newHead.setZ(newHead.getZ() - 1);
    break;
  default:
    break;
  }

  if (newHead.getX() < 0 || newHead.getX() >= spaceX
   || newHead.getY() < 0 || newHead.getY() >= spaceY
   || newHead.getZ() < 0 || newHead.getZ() >= spaceZ) {
    return MoveResult::WALL;
  }

  for (auto bodyPiece : body) {
    if (bodyPiece == newHead) {
      return MoveResult::TAIL;
    }
  }

  body.push_back(newHead);
  return MoveResult::OK;
}

void Snake::setDirection(Direction newD) {
  if ((newD == Direction::FORWARD  && d == Direction::BACKWARD)
   || (newD == Direction::BACKWARD && d == Direction::FORWARD)
   || (newD == Direction::LEFT     && d == Direction::RIGHT)
   || (newD == Direction::RIGHT    && d == Direction::LEFT)
   || (newD == Direction::UP       && d == Direction::DOWN)
   || (newD == Direction::DOWN     && d == Direction::UP)
   || (newD == Direction::UNKNOWN)) {
    return;
  }
  d = newD;
}

Point FadeCube::Snake::getHead() const {
  return body.back();
}

} /* namespace FadeCube */
