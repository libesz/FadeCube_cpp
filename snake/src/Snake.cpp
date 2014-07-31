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
             cubeProp(newCubeProp), lastDirection(KeyboardCommand::FORWARD),
             nextDirection(KeyboardCommand::FORWARD),
             size(newSize), lastMoveResult(MoveResult::OK),
             exitRequested(false) {
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

void Snake::start(int newX, int newY, int newZ, KeyboardCommand newD) {
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
  case KeyboardCommand::FORWARD:
    newHead.setY(newHead.getY() + 1);
    break;
  case KeyboardCommand::BACKWARD:
    newHead.setY(newHead.getY() - 1);
    break;
  case KeyboardCommand::LEFT:
    newHead.setX(newHead.getX() + 1);
    break;
  case KeyboardCommand::RIGHT:
    newHead.setX(newHead.getX() - 1);
    break;
  case KeyboardCommand::UP:
    newHead.setZ(newHead.getZ() + 1);
    break;
  case KeyboardCommand::DOWN:
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

void Snake::setDirection(KeyboardCommand newD) {
  std::lock_guard<std::mutex> lock(dLock);
#if ( DEBUG )
  std::cout << "setDirection old: " << lastDirection << std::endl;
  std::cout << "setDirection new: " << newD << std::endl;
#endif

  if ((newD == KeyboardCommand::FORWARD  && lastDirection == KeyboardCommand::BACKWARD)
   || (newD == KeyboardCommand::BACKWARD && lastDirection == KeyboardCommand::FORWARD)
   || (newD == KeyboardCommand::LEFT     && lastDirection == KeyboardCommand::RIGHT)
   || (newD == KeyboardCommand::RIGHT    && lastDirection == KeyboardCommand::LEFT)
   || (newD == KeyboardCommand::UP       && lastDirection == KeyboardCommand::DOWN)
   || (newD == KeyboardCommand::DOWN     && lastDirection == KeyboardCommand::UP)
   || (newD == KeyboardCommand::UNKNOWN)) {
    return;
  }
  if(newD == KeyboardCommand::EXIT) {
    exitRequested = true;
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

FadeCube::KeyboardCommand FadeCube::Snake::getDirection() const {
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

bool FadeCube::Snake::isExitRequested() const {
  return exitRequested;
}
