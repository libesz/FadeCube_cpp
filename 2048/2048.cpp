/*
 * 2048.cpp
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 */


#include <CubeProp.h>
#include <CubeDisplay.h>
//#include <DisplayDumper.h>
#include <Renderer.h>
#include <KeyboardInput.h>
#include <CondVarClockSource.h>
#include <GameController.h>
#include <GameTable.h>
#include <GameRenderable.h>
#include <GameExitCondition.h>

#include <vector>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace FadeCube;

int main( int argc, char **argv ) {
  CubeProp prop(10);
  const int gridSize = 4;
  GameTable t(prop, gridSize, gridSize);
  t.generateAtRandomEmptyPlace();
  t.generateAtRandomEmptyPlace();

  std::mutex m;
  std::condition_variable cv;
  bool ready;
  GameController c(m, cv, ready, t);
  GameRenderable r(t);

  CubeDisplay d("192.168.1.99", 1125);
  //DisplayDumper d;

  Renderer renderer(d);
  renderer.add(&r);

  KeyboardInput k(c);
  std::thread userInput(&KeyboardInput::loop, &k);

  GameExitCondition co(t);
  CondVarClockSource clock(m, cv, ready, co);
  clock.add(&renderer);

  //Wake up the renderer once to send initial state of the table
  ready = 1;
  cv.notify_one();

  clock.loop();
  k.cancel();
  userInput.join();
  renderer.draw();
  std::cout << t.getScore() << std::endl;
}
