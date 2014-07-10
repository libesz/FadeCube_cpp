/*
 * 2048.cpp
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 */


#include <CubeProp.h>
#include <CubeDisplay.h>
#include <Renderer.h>
#include <KeyboardInput.h>
#include <TimerClockSource.h>
#include <GameController.h>
#include <GameTable.h>
#include <GameRenderable.h>
#include <GameExitCondition.h>

#include <vector>
#include <unistd.h>
#include <thread>
#include <iostream>

using namespace FadeCube;

int main( int argc, char **argv ) {
  CubeProp prop(10);
  const int gridSize = 4;
  GameTable t(prop, gridSize, gridSize);
  t.generateAtRandomEmptyPlace();
  t.generateAtRandomEmptyPlace();
  GameController c(t);
  GameRenderable r(t);

  CubeDisplay d("192.168.1.99", 1125);
  //DisplayDumper d;

  Renderer renderer(d);
  renderer.add(&r);

  KeyboardInput k(c);
  std::thread userInput(&KeyboardInput::loop, &k);

  GameExitCondition a(t);
  TimerClockSource clock(250000, &a);
  clock.add(&renderer);
  clock.loop();
  k.cancel();
  userInput.join();
  renderer.draw();
  std::cout << t.getScore() << std::endl;
}
