/*
 * Snake.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include <vector>
#include <Renderable.h>

namespace FadeCube {

class Snake: public Renderable {
public:
  enum class Direction{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    FORWARD,
    BACKWARD
  };
  enum class MoveResult {
  	OK,
  	WALL,
  	TAIL
  };
private:
  int spaceX;
	int spaceY;
	int spaceZ;
	std::vector<Point> body;
	Direction d;
	int size;
public:
	Snake(int newSpaceX, int newSpaceY, int newSpaceZ, int newSize = 10);
	virtual ~Snake();
	const std::vector<Point> render() const;
	void start(int x, int y, int z, Direction d);
	MoveResult move();
	void setDirection(Direction newD);
};

} /* namespace FadeCube */

#endif /* SNAKE_H_ */
