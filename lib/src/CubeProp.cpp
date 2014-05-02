/*
 * CubeProp.cpp
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 */

#include <CubeProp.h>

namespace FadeCube {

CubeProp::CubeProp(int newSpaceX, int newSpaceY, int newSpaceZ, int newDepth):
                   spaceX(newSpaceX), spaceY(newSpaceY), spaceZ(newSpaceZ), depth(newDepth) {
}

CubeProp::CubeProp(int newSpace, int newDepth): spaceX(newSpace), spaceY(newSpace), spaceZ(newSpace), depth(newDepth) {

}

int CubeProp::getDepth() const {
  return depth;
}

int CubeProp::getSpaceX() const {
  return spaceX;
}

int CubeProp::getSpaceY() const {
  return spaceY;
}

int CubeProp::getSpaceZ() const {
  return spaceZ;
}

CubeProp::~CubeProp() {
}

} /* namespace FadeCube */
