/*
 * ClockDivider.cpp
 *
 *  Created on: Apr 20, 2014
 *      Author: libesz
 */

#include <ClockDivider.h>
#include <stdexcept>

namespace FadeCube {

ClockDivider::ClockDivider(int newDivider, Schedulable &newS):
                           d(newDivider), tickCount(0), s(newS) {
  if(d<=0)
    throw std::logic_error("can not divide clock with zero");
}

ClockDivider::~ClockDivider() {
  // TODO Auto-generated destructor stub
}

void ClockDivider::tick() {
  if(++tickCount == d) {
    tickCount = 0;
    s.tick();
  }
}

} /* namespace FadeCube */
