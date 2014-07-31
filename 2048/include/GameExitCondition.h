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
#include <GameController.h>

namespace FadeCube {

class GameExitCondition: public ClockSourceExitCondition {
  const GameTable &table;
  const GameController &controller;
public:
  GameExitCondition(const GameTable &newTable, const GameController &newController);
  bool cond();
};

} /* namespace FadeCube */

#endif /* GAMEEXITCONDITION_H_ */
