/*
 * CondVarClockSource.cpp
 *
 *  Created on: Jul 29, 2014
 *      Author: libesz
 */

#include <CondVarClockSource.h>

namespace FadeCube {

CondVarClockSource::CondVarClockSource(std::mutex &newM, std::condition_variable &newCv, bool &newReady,
                                       ClockSourceExitCondition &newCond) :
    ClockSource(newCond), m(newM), cv(newCv), ready(newReady) {
}

CondVarClockSource::~CondVarClockSource() {
  // TODO Auto-generated destructor stub
}

void CondVarClockSource::loop() {
  while (!cond.cond()) {
    std::unique_lock<std::mutex> lk(m);

    while(!ready)
      cv.wait(lk);

    update();
    ready = 0;
  }
}

} /* namespace FadeCube */
