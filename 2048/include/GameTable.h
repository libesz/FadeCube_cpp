/*
 * Game2048.h
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 */

#ifndef GAME2048_H_
#define GAME2048_H_

#include <CubeProp.h>
#include <vector>
#include <array>
#include <random>
#include <mutex>

namespace FadeCube {

class GameTable {
  CubeProp cubeProp;
  int gridX;
  int gridY;
  std::vector<std::vector<int> > slots;
  std::mt19937 rng;
  mutable std::mutex sLock;
  const std::array<int, 11> validValues{{2,4,8,16,32,64,128,256,512,1024,2048}};
  int freePlaces;
  int score;
  void checkValue(int value);

public:
  GameTable(CubeProp newCubeProp, int newGridX, int newGridY);
  int getSlotValue(int row, int col) const;
  void setSlotValue(int row, int col, int value);
  virtual ~GameTable();
  void generateAtRandomEmptyPlace();
  bool mergeDown();
  bool mergeUp();
  bool mergeLeft();
  bool mergeRight();
  bool shiftDown();
  bool shiftUp();
  bool shiftLeft();
  bool shiftRight();
  int getGridX() const;
  int getGridY() const;
  int getFreePlaces() const;
  int getScore() const;
};

} /* namespace FadeCube */

#endif /* GAME2048_H_ */
