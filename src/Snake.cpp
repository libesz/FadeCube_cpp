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

Snake::Snake(int newSpaceX, int newSpaceY, int newSpaceZ):
	spaceX(newSpaceX), spaceY(newSpaceY), spaceZ(newSpaceZ){
}

Snake::~Snake() {
	// TODO Auto-generated destructor stub
}

const std::vector<Point> Snake::render() const {
	throw std::logic_error("Snake is not placed yet.");
	std::vector<Point> result;
	return result;
}

void Snake::start(int x, int y, int z, direction d) {
}

} /* namespace FadeCube */
