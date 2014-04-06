/*
 * snake.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: libesz
 */

#include <Snake.h>
#include <CubeDisplay.h>
#include <Renderer.h>
#include <KeyboardInput.h>

#include <vector>
#include <unistd.h>
#include <thread>

using namespace FadeCube;

int main( int argc, char **argv ) {
  Snake s(10,10,10);
  std::vector<Renderable *> ra;
  ra.push_back(&s);

  CubeDisplay d("192.168.1.99", 1125);
  Renderer re(&d);
  s.start(0,0,0, Direction::FORWARD);
  KeyboardInput k(&s);
  std::thread userInput(&KeyboardInput::loop, &k);
  re.draw(ra);
  while(Snake::MoveResult::OK == s.move()) {
    re.draw(ra);
    usleep(500000);
  }
  k.cancel();
  userInput.join();
}
