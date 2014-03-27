/*
 * Point.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef POINT_H_
#define POINT_H_

namespace FadeCube {

class Point {
	int x;
	int y;
	int z;
	int br;
public:
  Point(int newX, int newY, int newZ, int newBr);
	virtual ~Point();
	int getBr() const;
	void setBr(int br);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	int getZ() const;
	void setZ(int z);
};

} /* namespace FadeCube */

#endif /* POINT_H_ */
