/*
 * GameController.h
 *
 *  Created on: May 9, 2014
 *      Author: libesz
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include <Controllable.h>
#include <GameTable.h>

namespace FadeCube {

class GameController: public Controllable {
  GameTable &table;
  bool gameOver;
public:
  GameController(GameTable &newTable);
  virtual ~GameController();
  void setDirection(Direction newD);
  bool isGameOver() const;
};

} /* namespace FadeCube */

#endif /* GAMECONTROLLER_H_ */
