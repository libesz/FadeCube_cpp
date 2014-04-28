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
  std::uniform_int_distribution<int> uint_dist10(0, 9);
  foodPosition.setX(uint_dist10(rng));
  foodPosition.setY(uint_dist10(rng));
  foodPosition.setZ(uint_dist10(rng));
}

SnakeFood::SnakeFood(): foodPosition(0,0,0,255), invisible(false) {
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
