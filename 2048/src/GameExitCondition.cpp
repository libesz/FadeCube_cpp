/*
 * GameExitCondition.cpp
 *
 *  Created on: Jul 10, 2014
 *      Author: libesz
 */

#include <GameExitCondition.h>

namespace FadeCube {

GameExitCondition::GameExitCondition(GameTable &newTable): table(newTable) {}
bool GameExitCondition::cond() {
  return table.boardDone() != GameResult::UNKNOWN;
}

} /* namespace FadeCube */
