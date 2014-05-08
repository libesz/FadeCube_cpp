/*
 * Game2048.h
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 */

#ifndef GAME2048_H_
#define GAME2048_H_

#include <CubeProp.h>
#include <Renderable.h>
#include <vector>

namespace FadeCube {

class Game2048: public Renderable {
  CubeProp cubeProp;
  int gridX;
  int gridY;
  std::vector<std::vector<int> > slots;
public:
  Game2048(CubeProp newCubeProp, int newGridX, int newGridY);
  const std::vector<Point> render() const;
  int getSlotValue(int row, int col);
  virtual ~Game2048();
};

} /* namespace FadeCube */

#endif /* GAME2048_H_ */
