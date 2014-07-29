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

class TimerClockSource: public ClockSource {
  int sleepTime;
public:
  TimerClockSource(int newSleepTime, ClockSourceExitCondition &newCond);
  void loop();
  virtual ~TimerClockSource();
};

} /* namespace FadeCube */

#endif /* TIMERCLOCKSOURCE_H_ */
