/*
 * snake.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: libesz
 */

#include <Snake.h>
#include <CubeDisplay.h>
#include <Renderer.h>
#include <vector>

using namespace FadeCube;

int main( int argc, char **argv ) {
  Snake s(10,10,10);
  std::vector<Renderable *> ra;
  ra.push_back(&s);

  CubeDisplay d("192.168.1.99", 1125);
  Renderer re(&d);
  s.start(0,0,0, Snake::Direction::FORWARD);
  s.move();
  s.move();
  s.move();
  s.move();
  re.draw(ra);
}

