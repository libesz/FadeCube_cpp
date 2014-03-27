/*
 * Renderable.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

#include <vector>
#include <Point.h>

namespace FadeCube {

class Renderable {
public:
	virtual const std::vector<Point> render() const = 0;
	virtual ~Renderable();
};

} /* namespace FadeCube */

#endif /* RENDERABLE_H_ */
