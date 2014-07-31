/*
 * SnakeExitCondition.h
 *
 *  Created on: Jul 31, 2014
 *      Author: libesz
 */

#ifndef SNAKEEXITCONDITION_H_
#define SNAKEEXITCONDITION_H_

#include <ClockSource.h>
#include <Snake.h>

namespace FadeCube {

class SnakeExitCondition: public ClockSourceExitCondition {
  Snake &s;
public:
  SnakeExitCondition(Snake &newS);
  virtual ~SnakeExitCondition();
  bool cond();
};

} /* namespace FadeCube */

#endif /* SNAKEEXITCONDITION_H_ */
