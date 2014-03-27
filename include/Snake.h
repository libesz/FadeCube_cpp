/*
 * Snake.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include <Renderable.h>

namespace FadeCube {

class Snake: public Renderable {
	int spaceX;
	int spaceY;
	int spaceZ;
public:
	enum class direction{
		UP,
		DOWN,
		RIGHT,
		LEFT,
		FORWARD,
		BACKWARD
	};
	Snake(int newSpaceX, int newSpaceY, int newSpaceZ);
	virtual ~Snake();
	const std::vector<Point> render() const;
	void start(int x, int y, int z, direction d);
};

} /* namespace FadeCube */

#endif /* SNAKE_H_ */
