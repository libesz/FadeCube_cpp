/*
 * SnakeController.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: libesz
 */

#include <SnakeController.h>

namespace FadeCube {

SnakeController::SnakeController(Snake &newSnake, SnakeFood &newSnakeFood):
                                 snake(newSnake), snakeFood(newSnakeFood),
                                 score(0) {
}

SnakeController::~SnakeController() {
  // TODO Auto-generated destructor stub
}

unsigned SnakeController::getScore() const {
	return score;
}

void SnakeController::tick() {
  if(snake.getHead() == snakeFood.get()) {
    snake.setSize(snake.getSize()+5);
    snakeFood.tick();
    score += 10;
#if(DEBUG)
    std::cout << "Got point at: " << snakeFood.get() << std::endl;
#endif
  }
  snakeFood.toogleInvisible();
}

} /* namespace FadeCube */
