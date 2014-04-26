/*
 * snake.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: libesz
 */

#include <Snake.h>
#include <SnakeFood.h>
#include <SnakeController.h>
#include <ClockDivider.h>
#include <CubeDisplay.h>
#include <DisplayDumper.h>
#include <Renderer.h>
#include <KeyboardInput.h>
#include <TimerClockSource.h>

#include <vector>
#include <unistd.h>
#include <thread>

using namespace FadeCube;

class SnakeExitCondition: public TimerClockSourceExitCondition {
  Snake &s;
public:
  SnakeExitCondition(Snake &newS): s(newS) {
  }
  bool cond() {
    return s.getLastMoveResult() != Snake::MoveResult::OK;
  }
};

int main( int argc, char **argv ) {
  Snake s(10,10,10);
  ClockDivider snakeDivider(2, s);
  SnakeFood f;
  ClockDivider foodDivider(40, f);
  SnakeController c(s, f);
  CubeDisplay d("192.168.1.99", 1125);
  //DisplayDumper d;

  Renderer renderer(&d);
  renderer.add(&s);
  renderer.add(&f);

  s.start(0,0,0, Direction::FORWARD);
  KeyboardInput k(s);
  std::thread userInput(&KeyboardInput::loop, &k);

  SnakeExitCondition exit(s);
  TimerClockSource clock(250000, &exit);
  clock.add(&snakeDivider);
  clock.add(&foodDivider);
  clock.add(&c);
  clock.add(&renderer);
  clock.loop();
  k.cancel();
  userInput.join();
}
