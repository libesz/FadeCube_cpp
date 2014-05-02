/*
 * CubeProp.h
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 */

#ifndef CUBEPROP_H_
#define CUBEPROP_H_

namespace FadeCube {
class CubeProp {
  int spaceX;
  int spaceY;
  int spaceZ;
  int depth;
public:
  CubeProp(int newSpaceX, int newSpaceY, int newSpaceZ, int newDepth = 4);
  CubeProp(int newSpaceX = 10, int newDepth = 4);
  virtual ~CubeProp();
  int getDepth() const;
  int getSpaceX() const;
  int getSpaceY() const;
  int getSpaceZ() const;
};

} /* namespace FadeCube */

#endif /* CUBEPROP_H_ */
