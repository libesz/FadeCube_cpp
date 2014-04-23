/*
 * SnakeFood.h
 *
 *  Created on: Apr 23, 2014
 *      Author: libesz
 */

#ifndef SNAKEFOOD_H_
#define SNAKEFOOD_H_

#include <Renderable.h>
#include <Schedulable.h>
#include <DotObject.h>
#include <random>

namespace FadeCube {

class SnakeFood: public Renderable, public Schedulable {
  std::mt19937 rng;
  DotObject *foodPosition;
  void createFood();

public:
  SnakeFood();
  virtual ~SnakeFood();
  const std::vector<Point> render() const;
  void tick();
};

} /* namespace FadeCube */

#endif /* SNAKEFOOD_H_ */
