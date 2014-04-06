/*
 * KeyboardInput.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: libesz
 */

#include <KeyboardInput.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <mutex>

namespace FadeCube {

KeyboardInput::KeyboardInput(Controllable *newS): s(newS), cancelled(false) {
  // TODO Auto-generated constructor stub

}

void KeyboardInput::cancel() {
  protectCancel.lock();
  cancelled = true;
  protectCancel.unlock();
}

void KeyboardInput::loop() {
  while (1) {
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

    Direction d = Direction::FORWARD;
    switch (ch) {
    case 'w':
      d = Direction::FORWARD;
      break;
    case 's':
      d = Direction::BACKWARD;
      break;
    case 'a':
      d = Direction::LEFT;
      break;
    case 'd':
      d = Direction::RIGHT;
      break;
    case '\'':
      d = Direction::UP;
      break;
    case '/':
      d = Direction::DOWN;
      break;
    }
    s->setDirection(d);
    protectCancel.lock();
    if(cancelled)
      return;
    protectCancel.unlock();
  }
}

} /* namespace FadeCube */
