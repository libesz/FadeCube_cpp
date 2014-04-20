/*
 * ClockDivider.h
 *
 *  Created on: Apr 20, 2014
 *      Author: libesz
 */

#ifndef CLOCKDIVIDER_H_
#define CLOCKDIVIDER_H_

#include <Schedulable.h>

namespace FadeCube {

class ClockDivider: public Schedulable {
  int d;
  int tickCount;
  Schedulable *s;
public:
  ClockDivider(int newDivider, Schedulable *newS);
  virtual ~ClockDivider();
  void tick();
};

} /* namespace FadeCube */

#endif /* CLOCKDIVIDER_H_ */
