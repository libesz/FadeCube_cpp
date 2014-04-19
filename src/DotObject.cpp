/*
 * DotObject.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <DotObject.h>

namespace FadeCube {

DotObject::DotObject(int newX, int newY, int newZ, int newBr) :
		data(newX, newY, newZ, newBr) {
}

DotObject::~DotObject() {
	// TODO Auto-generated destructor stub
}

const std::vector<Point> DotObject::render() const {
  std::vector<Point> result;
  result.push_back(data);
  return result;
}

} /* namespace FadeCube */
