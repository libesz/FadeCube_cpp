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
  std::uniform_int_distribution<unsigned int> uint_dist10(0, 9);
  foodPosition = new DotObject(uint_dist10(rng), uint_dist10(rng),
                               uint_dist10(rng), 255);
}

SnakeFood::SnakeFood() {
  rng.seed(time(0));
  createFood();
}

SnakeFood::~SnakeFood() {
  delete foodPosition;
}

const std::vector<Point> SnakeFood::render() const {
  return foodPosition->render();
}

void SnakeFood::tick() {
  delete foodPosition;
  createFood();
}

} /* namespace FadeCube */
