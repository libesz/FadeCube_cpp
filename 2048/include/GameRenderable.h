/*
 * GameRenderable.h
 *
 *  Created on: May 9, 2014
 *      Author: libesz
 */

#ifndef GAMERENDERABLE_H_
#define GAMERENDERABLE_H_

#include <Renderable.h>
#include <GameTable.h>

namespace FadeCube {

class GameRenderable: public Renderable {
  const GameTable &table;
  int getHeightFromValue(int value) const;
public:
  GameRenderable(const GameTable &newTable);
  virtual ~GameRenderable();
  const std::vector<Point> render() const;
};

} /* namespace FadeCube */

#endif /* GAMERENDERABLE_H_ */
