/*
 * GameController.cpp
 *
 *  Created on: May 9, 2014
 *      Author: libesz
 */

#include <GameController.h>

namespace FadeCube {

GameController::GameController(std::mutex &newM, std::condition_variable &newCv, bool &newReady, GameTable &newTable) :
    m(newM), cv(newCv), ready(newReady), table(newTable), exitRequested(false) {
}

GameController::~GameController() {
  // TODO Auto-generated destructor stub
}

bool GameController::isExitRequested() const {
  return exitRequested;
}

void GameController::setDirection(KeyboardCommand d) {
  bool result = false;
  std::unique_lock<std::mutex> lk(m);

  switch (d) {
  case KeyboardCommand::BACKWARD:
    result |= table.mergeDown();
    result |= table.shiftDown();
    break;
  case KeyboardCommand::FORWARD:
    result |= table.mergeUp();
    result |= table.shiftUp();
    break;
  case KeyboardCommand::LEFT:
    result |= table.mergeLeft();
    result |= table.shiftLeft();
    break;
  case KeyboardCommand::RIGHT:
    result |= table.mergeRight();
    result |= table.shiftRight();
    break;
  case KeyboardCommand::EXIT:
    exitRequested = true;
    break;
  default:
    break;
  }
  if(result) {
    table.generateAtRandomEmptyPlace();
  }
  lk.unlock();
  if(result || exitRequested) {
    ready = true;
    cv.notify_one();
  }
}

} /* namespace FadeCube */
