/*
 * TimerClockSource.h
 *
 *  Created on: Apr 20, 2014
 *      Author: libesz
 */

#ifndef TIMERCLOCKSOURCE_H_
#define TIMERCLOCKSOURCE_H_

#include <ClockSource.h>

namespace FadeCube {

class TimerClockSourceExitCondition {
public:
  virtual bool cond() = 0;
  virtual ~TimerClockSourceExitCondition() {}
};

class TimerClockSource: public ClockSource {
  int sleepTime;
  TimerClockSourceExitCondition *cond;
public:
  TimerClockSource(int newSleepTime, TimerClockSourceExitCondition *newCond);
  void loop();
  virtual ~TimerClockSource();
};

} /* namespace FadeCube */

#endif /* TIMERCLOCKSOURCE_H_ */
