/*
 * GameController.cpp
 *
 *  Created on: May 9, 2014
 *      Author: libesz
 */

#include <GameController.h>

namespace FadeCube {

GameController::GameController(GameTable &newTable) :
    table(newTable), gameOver(false) {
}

GameController::~GameController() {
  // TODO Auto-generated destructor stub
}

bool GameController::isGameOver() const {
  return gameOver;
}

void GameController::setDirection(Direction d) {
  bool result = false;
  switch (d) {
  case Direction::BACKWARD:
    result |= table.mergeDown();
    result |= table.shiftDown();
    break;
  case Direction::FORWARD:
    result |= table.mergeUp();
    result |= table.shiftUp();
    break;
  case Direction::LEFT:
    result |= table.mergeLeft();
    result |= table.shiftLeft();
    break;
  case Direction::RIGHT:
    result |= table.mergeRight();
    result |= table.shiftRight();
    break;
  default:
    break;
  }
  if(result)
    table.generateAtRandomEmptyPlace();
  else if(!table.getFreePlaces())
    gameOver = true;
}

} /* namespace FadeCube */
