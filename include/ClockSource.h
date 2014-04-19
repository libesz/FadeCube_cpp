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

class ClockSource {
protected:
  std::vector<Schedulable *> observers;
  void update();
public:
  ClockSource();
  void reg(Schedulable *s);
  void dereg(Schedulable *s);
  virtual ~ClockSource();
};

} /* namespace FadeCube */

#endif /* CLOCKSOURCE_H_ */
