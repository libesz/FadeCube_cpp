/*
 * GameController.cpp
 *
 *  Created on: May 9, 2014
 *      Author: libesz
 */

#include <GameController.h>

namespace FadeCube {

GameController::GameController(std::mutex &newM, std::condition_variable &newCv, bool &newReady, GameTable &newTable) :
    m(newM), cv(newCv), ready(newReady), table(newTable) {
}

GameController::~GameController() {
  // TODO Auto-generated destructor stub
}

void GameController::setDirection(Direction d) {
  bool result = false;
  std::unique_lock<std::mutex> lk(m);

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
  if(result) {
    table.generateAtRandomEmptyPlace();
  }
  lk.unlock();
  if(result) {
    ready = 1;
    cv.notify_one();
  }
}

} /* namespace FadeCube */
