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
	unsigned char br;
public:
  Point(int newX, int newY, int newZ, unsigned char newBr);
	virtual ~Point();
	unsigned char getBr() const;
	void setBr(unsigned char br);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	int getZ() const;
	void setZ(int z);
	bool operator==(const Point &theOther);
};

} /* namespace FadeCube */

#endif /* POINT_H_ */
