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
    spaceX(newSpaceX), spaceY(newSpaceY), spaceZ(newSpaceZ),
    d(Direction::FORWARD), size(newSize) {
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
	d = newD;
  body.push_back(Point(newX, newY, newZ, 255));
}

Snake::MoveResult Snake::move() {
  auto oldHead = body.back();
  Point newHead(oldHead);

  switch(d) {
  case Snake::Direction::FORWARD:
  	newHead.setY(newHead.getY()+1);
  	break;
  case Snake::Direction::BACKWARD:
  	newHead.setY(newHead.getY()-1);
  	break;
  case Snake::Direction::LEFT:
  	newHead.setX(newHead.getX()+1);
  	break;
  case Snake::Direction::RIGHT:
  	newHead.setX(newHead.getX()-1);
  	break;
  case Snake::Direction::UP:
  	newHead.setZ(newHead.getZ()+1);
  	break;
  case Snake::Direction::DOWN:
  	newHead.setZ(newHead.getZ()-1);
  	break;
  }

  if(newHead.getX() < 0 || newHead.getX() >= spaceX ||
  	 newHead.getY() < 0 || newHead.getY() >= spaceY ||
  	 newHead.getZ() < 0 || newHead.getZ() >= spaceZ) {
  	return MoveResult::WALL;
  }

  for(auto bodyPiece: body) {
    if(bodyPiece == newHead) {
      return MoveResult::TAIL;
    }
  }

  body.push_back(newHead);
  return MoveResult::OK;
}

void Snake::setDirection(Direction newD) {
	d = newD;
}

Point FadeCube::Snake::getHead() const {
  return body.back();
}

} /* namespace FadeCube */
