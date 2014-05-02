/*
 * SnakeFood.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: libesz
 */

#include <SnakeFood.h>
#include <ctime>
#include <iostream>

namespace FadeCube {

void SnakeFood::createFood() {
  std::uniform_int_distribution<int> genX(0, cubeProp.getSpaceX());
  std::uniform_int_distribution<int> genY(0, cubeProp.getSpaceY());
  std::uniform_int_distribution<int> genZ(0, cubeProp.getSpaceZ());
  foodPosition.setX(genX(rng));
  foodPosition.setY(genY(rng));
  foodPosition.setZ(genZ(rng));
}

SnakeFood::SnakeFood(CubeProp newCubeProp): cubeProp(newCubeProp), foodPosition(0,0,0,255), invisible(false) {
  rng.seed(time(0));
  createFood();
}

SnakeFood::~SnakeFood() {
}

const std::vector<Point> SnakeFood::render() const {
  std::vector<Point> result;
  Point pos = foodPosition;
  if(invisible)
    pos.setBr(0);
  result.push_back(pos);
  return result;
}

void SnakeFood::toogleInvisible() {
  invisible = !invisible;
}

void SnakeFood::tick() {
  createFood();
}

} /* namespace FadeCube */
