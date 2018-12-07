/*
 * DisplayDumper.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <DisplayDumper.h>
#include <iostream>

namespace FadeCube {

DisplayDumper::~DisplayDumper() {
	// TODO Auto-generated destructor stub
}

void DisplayDumper::draw(const std::vector<Point> data) const {
	for (auto it : data) {
		std::cout << it.getX() << ", "
							<< it.getY() << ", "
							<< it.getZ() << ", "
							<< it.getBr() << std::endl;
	}
	std::cout << std::endl;
}

} /* namespace FadeCube */
