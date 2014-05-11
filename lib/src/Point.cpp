/*
 * Point.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <Point.h>

namespace FadeCube {

Point::Point(int newX, int newY, int newZ, unsigned char newBr) :
    x(newX), y(newY), z(newZ), br(newBr) {
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

unsigned char Point::getBr() const {
	return br;
}

void Point::setBr(unsigned char br) {
	this->br = br;
}

int Point::getX() const {
	return x;
}

void Point::setX(int x) {
	this->x = x;
}

int Point::getY() const {
	return y;
}

void Point::setY(int y) {
	this->y = y;
}

int Point::getZ() const {
	return z;
}

void Point::setZ(int z) {
	this->z = z;
}

bool Point::operator ==(const Point& theOther) {
	return (x == theOther.x) && (y == theOther.y) && (z == theOther.z);
}

std::ostream& operator <<(std::ostream &out, const Point& point) {
  out << "x: " << point.getX() << ", y: " << point.getY() << ", z: " << point.getZ();
	return out;
}

} /* namespace FadeCube */
