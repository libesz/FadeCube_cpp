/*
 * ClockSource.h
 *
 *  Created on: Apr 19, 2014
 *      Author: libesz
 */

#ifndef CLOCKSOURCE_H_
#define CLOCKSOURCE_H_

#include <Schedulable.h>
#include <vector>

namespace FadeCube {

class ClockSourceExitCondition {
public:
  virtual bool cond() = 0;
  virtual ~ClockSourceExitCondition() {}
};

class ClockSource {
protected:
  std::vector<Schedulable *> observers;
  ClockSourceExitCondition &cond;
  void update();
public:
  ClockSource(ClockSourceExitCondition &newCond);
  void add(Schedulable *s);
  void dereg(Schedulable *s);
  virtual ~ClockSource();
  virtual void loop() = 0;
};

} /* namespace FadeCube */

#endif /* CLOCKSOURCE_H_ */
