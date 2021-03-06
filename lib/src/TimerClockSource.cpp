/*
 * TimerClockSource.cpp
 *
 *  Created on: Apr 20, 2014
 *      Author: libesz
 */

#include <TimerClockSource.h>
#include <unistd.h>

namespace FadeCube {

TimerClockSource::TimerClockSource(int newSleepTime,
    ClockSourceExitCondition &newCond) :
    ClockSource(newCond), sleepTime(newSleepTime) {
}

void TimerClockSource::loop() {
  while (!cond.cond()) {
    update();
    usleep(sleepTime);
  }
}

TimerClockSource::~TimerClockSource() {
  // TODO Auto-generated destructor stub
}

} /* namespace FadeCube */
