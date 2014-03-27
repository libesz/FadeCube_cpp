/*
 * Display.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <vector>
#include <Point.h>

namespace FadeCube {

class Display {
public:
	virtual void draw(const std::vector<Point>) const = 0;
	virtual ~Display();
};

} /* namespace FadeCube */

#endif /* DISPLAY_H_ */
