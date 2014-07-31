/*
 * GameExitCondition.cpp
 *
 *  Created on: Jul 10, 2014
 *      Author: libesz
 */

#include <GameExitCondition.h>

namespace FadeCube {

GameExitCondition::GameExitCondition(const GameTable &newTable,
                                     const GameController &newController): table(newTable),
                                                                           controller(newController) {}
bool GameExitCondition::cond() {
  return ( table.boardDone() != GameResult::UNKNOWN ) || (controller.isExitRequested());
}

} /* namespace FadeCube */
