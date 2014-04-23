/*
 * SnakeController.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: libesz
 */

#include <SnakeController.h>

namespace FadeCube {

SnakeController::SnakeController(Snake *newSnake, SnakeFood *newSnakeFood):
                                 snake(newSnake), snakeFood(newSnakeFood){
}

SnakeController::~SnakeController() {
  // TODO Auto-generated destructor stub
}

void SnakeController::tick() {
  if(snake->getHead() == snakeFood->render()[0]) {
    snake->setSize(snake->getSize()+1);
    snakeFood->tick();
  }
}

} /* namespace FadeCube */
