/*
 * GameRenderable.cpp
 *
 *  Created on: May 9, 2014
 *      Author: libesz
 */

#include <GameRenderable.h>

namespace FadeCube {

GameRenderable::~GameRenderable() {
  // TODO Auto-generated destructor stub
}

GameRenderable::GameRenderable(const GameTable& newTable): table(newTable) {
}

int GameRenderable::getHeightFromValue(int value) const {
  int result = 0;
  while(value>1) {
    value /= 2;
    result++;
  }
  return result;
}

const std::vector<Point> GameRenderable::render() const {
  std::vector<Point> result;
  const int firstRow = 6;
  const int firstCol = 6;
  for (int i = 0; i < table.getGridX(); i++) {
    for (int j = 0; j < table.getGridY(); j++) {
      if(table.getSlotValue(i, j))
        for(int k = 0; k < getHeightFromValue(table.getSlotValue(i, j)); k++)
          result.push_back(Point(firstRow - j, firstCol - i, k, 255));
    }
  }

  return result;
}

} /* namespace FadeCube */
