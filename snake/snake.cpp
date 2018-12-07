/*
 * snake.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: libesz
 */

#include <Snake.h>
#include <SnakeFood.h>
#include <SnakeController.h>
#include <SnakeExitCondition.h>
#include <CubeProp.h>
#include <ClockDivider.h>
#include <CubeDisplay.h>
#include <DisplayDumper.h>
#include <Renderer.h>
#include <KeyboardInput.h>
#include <TimerClockSource.h>

#include <vector>
#include <unistd.h>
#include <thread>
#include <iostream>

#ifdef __MINGW32__
#include <winsock2.h>
#endif // __MINGW32__

using namespace FadeCube;

int main( int argc, char **argv ) {
#ifdef __MINGW32__
  WSADATA WSAData;
  WSAStartup(MAKEWORD(2,0), &WSAData);
#endif // __MINGW32__
  CubeProp prop(10);
  Snake s(prop);
  ClockDivider snakeDivider(1, s);
  SnakeFood f(prop);
  ClockDivider foodDivider(40, f);
  SnakeController c(s, f);
  CubeDisplay d("192.168.1.99", 1125);
  //DisplayDumper d;

  Renderer renderer(d);
  renderer.add(&s);
  renderer.add(&f);

  s.start(0,0,0, KeyboardCommand::FORWARD);
  KeyboardInput k(s);
  std::thread userInput(&KeyboardInput::loop, &k);

  SnakeExitCondition exit(s);
  TimerClockSource clock(250000, exit);
  clock.add(&snakeDivider);
  clock.add(&foodDivider);
  clock.add(&c);
  clock.add(&renderer);
  clock.loop();
  std::cout << c.getScore() << std::endl;
  k.cancel();
  userInput.join();

#ifdef __MINGW32__
  WSACleanup();
#endif // __MINGW32__
}
