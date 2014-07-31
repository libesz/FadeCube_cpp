/*
 * SnakeExitCondition.cpp
 *
 *  Created on: Jul 31, 2014
 *      Author: libesz
 */

#include "SnakeExitCondition.h"

namespace FadeCube {

SnakeExitCondition::SnakeExitCondition(Snake &newS): s(newS) {
}

SnakeExitCondition::~SnakeExitCondition() {
  // TODO Auto-generated destructor stub
}

bool SnakeExitCondition::cond() {
  return (s.getLastMoveResult() != Snake::MoveResult::OK) || s.isExitRequested();
}

} /* namespace FadeCube */
