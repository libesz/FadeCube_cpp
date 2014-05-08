/*
 * Game2048.cpp
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 *
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---O---+---O---+---O---+---O---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---O---+---O---+---O---+---O---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---O---+---O---+---O---+---O---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---O---+---O---+---O---+---O---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 * 0,0
 *
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---O---O---O---O---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---O---O---O---O---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---O---O---O---O---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---O---O---O---O---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 * 0,0
 *
 *  O---+---+---O---+---+---O---+---+---O
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  O---+---+---O---+---+---O---+---+---O
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  O---+---+---O---+---+---O---+---+---O
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  +---+---+---+---+---+---+---+---+---+
 *  |   |   |   |   |   |   |   |   |   |
 *  O---+---+---O---+---+---O---+---+---O
 * 0,0
 *
 */

#include <Game2048.h>
#include <stdexcept>

namespace FadeCube {

Game2048::Game2048(CubeProp newCubeProp, int newGridX, int newGridY):
    cubeProp(newCubeProp), gridX(newGridX), gridY(newGridY) {
  slots.resize(gridX);
  for(int i = 0; i < gridX; i++) {
    slots[i].resize(gridY);
    for(int j = 0; j < gridY; j++) {
      slots[i][j] = 0;
    }
  }
}

int Game2048::getSlotValue(int row, int col) {
  return slots[row][col];
}

const std::vector<Point> Game2048::render() const {
  return std::vector<Point>();
}

Game2048::~Game2048() {
  // TODO Auto-generated destructor stub
}

} /* namespace FadeCube */