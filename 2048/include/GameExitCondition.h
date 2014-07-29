/*
 * GameExitCondition.h
 *
 *  Created on: Jul 10, 2014
 *      Author: libesz
 */

#ifndef GAMEEXITCONDITION_H_
#define GAMEEXITCONDITION_H_

#include <TimerClockSource.h>
#include <GameTable.h>

namespace FadeCube {

class GameExitCondition: public ClockSourceExitCondition {
  GameTable &table;
public:
  GameExitCondition(GameTable &newTable);
  bool cond();
};

} /* namespace FadeCube */

#endif /* GAMEEXITCONDITION_H_ */
