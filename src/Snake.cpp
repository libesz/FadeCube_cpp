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

Snake::Snake(int newSpaceX, int newSpaceY, int newSpaceZ) :
    spaceX(newSpaceX), spaceY(newSpaceY), spaceZ(newSpaceZ), d(
        direction::FORWARD) {
}

Snake::~Snake() {
  // TODO Auto-generated destructor stub
}

const std::vector<Point> Snake::render() const {
  if (!body.size())
    throw std::logic_error("Snake is not started.");
  return body;
}

void Snake::start(int x, int y, int z, direction d) {
  body.push_back(Point(x, y, z, 255));
}

void Snake::move() {
  auto tail = body.end();
  body.push_back(Point(tail->getX()+1, tail->getY(), tail->getZ(), 255));
}

} /* namespace FadeCube */
