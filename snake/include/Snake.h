/*
 * Snake.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include <vector>
#include <mutex>
#include <Renderable.h>
#include <Controllable.h>
#include <Schedulable.h>
#include <CubeProp.h>

namespace FadeCube {

class Snake: public Renderable, public Controllable, public Schedulable {
public:
  enum class MoveResult {
    OK, WALL, TAIL
  };
private:
  CubeProp cubeProp;
  std::vector<Point> body;
  KeyboardCommand lastDirection;
  KeyboardCommand nextDirection;
  mutable std::mutex dLock;
  unsigned int size;
  MoveResult lastMoveResult;
  bool exitRequested;
  Snake();
  void checkInitValues();
  MoveResult move();
public:
  Snake(const CubeProp newCubeProp, int newSize = 10);
  virtual ~Snake();
  const std::vector<Point> render() const;
  void start(int x, int y, int z, KeyboardCommand d);
  void tick();
  void setDirection(KeyboardCommand newD);
  MoveResult getLastMoveResult();
  Point getHead() const;
  unsigned int getSize() const;
  void setSize(unsigned int size);
  KeyboardCommand getDirection() const;
  void storeDirection();
  bool isExitRequested() const;
};

} /* namespace FadeCube */

#endif /* SNAKE_H_ */
