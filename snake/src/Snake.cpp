/*
 * Snake.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <Snake.h>
#include <vector>
#include <stdexcept>
#include <CubeProp.h>

namespace FadeCube {

Snake::Snake(const CubeProp newCubeProp, int newSize) :
             cubeProp(newCubeProp), lastDirection(Direction::FORWARD),
             nextDirection(Direction::FORWARD),
             size(newSize), lastMoveResult(MoveResult::OK) {
  checkInitValues();
#if ( DEBUG )
  std::cout << "start: " << lastDirection << std::endl;
#endif
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
  if(lastMoveResult != MoveResult::OK)
    return lastMoveResult;

  auto oldHead = body.back();
  Point newHead(oldHead);
#if ( DEBUG )
  std::cout << "move: " << lastDirection << std::endl;
#endif
  switch (getDirection()) {
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

  storeDirection();

  if (newHead.getX() < 0 || newHead.getX() >= cubeProp.getSpaceX()
   || newHead.getY() < 0 || newHead.getY() >= cubeProp.getSpaceY()
   || newHead.getZ() < 0 || newHead.getZ() >= cubeProp.getSpaceZ()) {
    return MoveResult::WALL;
  }

  for (auto bodyPiece : body) {
    if (bodyPiece == newHead) {
      return MoveResult::TAIL;
    }
  }

  body.push_back(newHead);
  while(body.size() > size)
    body.erase(body.begin());
  return MoveResult::OK;
}

void Snake::setDirection(Direction newD) {
  std::lock_guard<std::mutex> lock(dLock);
#if ( DEBUG )
  std::cout << "setDirection old: " << lastDirection << std::endl;
  std::cout << "setDirection new: " << newD << std::endl;
#endif

  if ((newD == Direction::FORWARD  && lastDirection == Direction::BACKWARD)
   || (newD == Direction::BACKWARD && lastDirection == Direction::FORWARD)
   || (newD == Direction::LEFT     && lastDirection == Direction::RIGHT)
   || (newD == Direction::RIGHT    && lastDirection == Direction::LEFT)
   || (newD == Direction::UP       && lastDirection == Direction::DOWN)
   || (newD == Direction::DOWN     && lastDirection == Direction::UP)
   || (newD == Direction::UNKNOWN)) {
    return;
  }
  nextDirection = newD;
}

void Snake::checkInitValues() {
  if(cubeProp.getSpaceX() <= 0 || cubeProp.getSpaceY() <= 0 || cubeProp.getSpaceZ() <= 0 || size == 0)
    throw std::logic_error("invalid size passed");
}

void Snake::tick() {
  lastMoveResult = move();
}

Point FadeCube::Snake::getHead() const {
  return body.back();
}

Snake::MoveResult FadeCube::Snake::getLastMoveResult() {
  return lastMoveResult;
}

} /* namespace FadeCube */

unsigned int FadeCube::Snake::getSize() const {
  return size;
}

FadeCube::Direction FadeCube::Snake::getDirection() const {
  std::lock_guard<std::mutex> lock(dLock);
  return nextDirection;
}

void FadeCube::Snake::storeDirection() {
  std::lock_guard<std::mutex> lock(dLock);
   lastDirection = nextDirection;
}

void FadeCube::Snake::setSize(unsigned int size) {
  this->size = size;
}
