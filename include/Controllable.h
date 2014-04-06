/*
 * Controllable.h
 *
 *  Created on: Apr 7, 2014
 *      Author: libesz
 */

#ifndef CONTROLLABLE_H_
#define CONTROLLABLE_H_

namespace FadeCube {

enum class Direction{
  UP,
  DOWN,
  RIGHT,
  LEFT,
  FORWARD,
  BACKWARD
};

class Controllable {
public:
  virtual ~Controllable(){}
  virtual void setDirection(Direction newD) = 0;
};

} /* namespace FadeCube */

#endif /* CONTROLLABLE_H_ */
