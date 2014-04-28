/*
 * SnakeController.h
 *
 *  Created on: Apr 23, 2014
 *      Author: libesz
 */

#ifndef SNAKECONTROLLER_H_
#define SNAKECONTROLLER_H_

#include <Snake.h>
#include <SnakeFood.h>
#include <Schedulable.h>

namespace FadeCube {

class SnakeController: public Schedulable {
  Snake &snake;
  SnakeFood &snakeFood;
public:
  SnakeController(Snake &newSnake, SnakeFood &newSnakeFood);
  virtual ~SnakeController();
  void tick();
};

} /* namespace FadeCube */

#endif /* SNAKECONTROLLER_H_ */
