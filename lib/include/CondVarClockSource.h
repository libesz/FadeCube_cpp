/*
 * CondVarClockSource.h
 *
 *  Created on: Jul 29, 2014
 *      Author: libesz
 */

#ifndef CONDVARCLOCKSOURCE_H_
#define CONDVARCLOCKSOURCE_H_

#include <ClockSource.h>
#include <condition_variable>
#include <mutex>

namespace FadeCube {

class CondVarClockSource: public ClockSource {
  std::mutex &m;
  std::condition_variable &cv;
  bool &ready;
public:
  CondVarClockSource(std::mutex &newM, std::condition_variable &newCv, bool &newReady,
                     ClockSourceExitCondition &newCond);
  virtual ~CondVarClockSource();
  void loop();
};

} /* namespace FadeCube */

#endif /* CONDVARCLOCKSOURCE_H_ */
