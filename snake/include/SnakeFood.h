/*
 * SnakeFood.h
 *
 *  Created on: Apr 23, 2014
 *      Author: libesz
 */

#ifndef SNAKEFOOD_H_
#define SNAKEFOOD_H_

#include <Renderable.h>
#include <CubeProp.h>
#include <Schedulable.h>
#include <Point.h>
#include <random>

namespace FadeCube {

class SnakeFood: public Renderable, public Schedulable {
  CubeProp cubeProp;
  std::mt19937 rng;
  Point foodPosition;
  void createFood();
  bool invisible;

public:
  SnakeFood(CubeProp newCubeProp);
  virtual ~SnakeFood();
  const std::vector<Point> render() const;
  void toogleInvisible();
  void tick();
};

} /* namespace FadeCube */

#endif /* SNAKEFOOD_H_ */
