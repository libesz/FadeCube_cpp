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

enum class KeyboardCommand{
  UNKNOWN,
  EXIT,
  UP,
  DOWN,
  RIGHT,
  LEFT,
  FORWARD,
  BACKWARD,
};

#if ( DEBUG )
std::ostream& operator<<(std::ostream &out, const KeyboardCommand &d);
#endif

class Controllable {
public:
  virtual ~Controllable(){}
  virtual void setDirection(KeyboardCommand newD) = 0;
};

} /* namespace FadeCube */

#endif /* CONTROLLABLE_H_ */
