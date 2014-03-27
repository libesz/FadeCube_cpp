/*
 * Point.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <Point.h>

namespace FadeCube {

Point::Point(int newX, int newY, int newZ, int newBr) :
    x(newX), y(newY), z(newZ), br(newBr) {
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

} /* namespace FadeCube */

int FadeCube::Point::getBr() const {
	return br;
}

void FadeCube::Point::setBr(int br) {
	this->br = br;
}

int FadeCube::Point::getX() const {
	return x;
}

void FadeCube::Point::setX(int x) {
	this->x = x;
}

int FadeCube::Point::getY() const {
	return y;
}

void FadeCube::Point::setY(int y) {
	this->y = y;
}

int FadeCube::Point::getZ() const {
	return z;
}

void FadeCube::Point::setZ(int z) {
	this->z = z;
}
