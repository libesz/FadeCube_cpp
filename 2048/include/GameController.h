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
#include <condition_variable>
#include <mutex>

namespace FadeCube {

class GameController: public Controllable {
  std::mutex &m;
  std::condition_variable &cv;
  bool &ready;
  GameTable &table;
public:
  GameController(std::mutex &newM, std::condition_variable &newCv, bool &newReady, GameTable &newTable);
  virtual ~GameController();
  void setDirection(Direction newD);
};

} /* namespace FadeCube */

#endif /* GAMECONTROLLER_H_ */
