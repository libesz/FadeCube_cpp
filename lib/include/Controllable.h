/*
 * Controllable.h
 *
 *  Created on: Apr 7, 2014
 *      Author: libesz
 */

#ifndef CONTROLLABLE_H_
#define CONTROLLABLE_H_

#include <iostream>

namespace FadeCube {

enum class Direction{
  UNKNOWN,
  UP,
  DOWN,
  RIGHT,
  LEFT,
  FORWARD,
  BACKWARD,
};

#if ( DEBUG )
std::ostream& operator<<(std::ostream &out, const Direction &d);
#endif

class Controllable {
public:
  virtual ~Controllable(){}
  virtual void setDirection(Direction newD) = 0;
};

} /* namespace FadeCube */

#endif /* CONTROLLABLE_H_ */
