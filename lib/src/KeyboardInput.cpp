/*
 * KeyboardInput.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: libesz
 */

#include <KeyboardInput.h>
//#include <termios.h>
#include <conio.h>
#include <winsock2.h>
#include <stdio.h>
#include <unistd.h>
#include <mutex>
#include <fcntl.h>
#include <iostream>
#include <Controllable.h>

namespace FadeCube {
#define pipe(fds) _pipe(fds,4096, _O_BINARY)

KeyboardInput::KeyboardInput(Controllable &newS): s(newS) {
  //pipe(cancelPipe);
  cancelPipe[0] = 0;
}

void KeyboardInput::cancel() {
  //write(cancelPipe[1], " ", 1);
  cancelPipe[0] = 1;
}

KeyboardCommand KeyboardInput::getDirectionFromChar(int ch) {
  KeyboardCommand d = KeyboardCommand::UNKNOWN;
  switch (ch) {
  case 'w':
    d = KeyboardCommand::FORWARD;
    break;
  case 's':
    d = KeyboardCommand::BACKWARD;
    break;
  case 'a':
    d = KeyboardCommand::LEFT;
    break;
  case 'd':
    d = KeyboardCommand::RIGHT;
    break;
  case 'k':
    d = KeyboardCommand::UP;
    break;
  case 'm':
    d = KeyboardCommand::DOWN;
    break;
  case 27:
    d = KeyboardCommand::EXIT;
  }
  return d;
}

void KeyboardInput::loop() {
  //struct termios oldt, newt;

  //fd_set fds;

  /*tcgetattr( STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO);
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);*/

  while (1) {
    /*FD_ZERO(&fds);
    FD_SET(cancelPipe[0], &fds);
    FD_SET(STDIN_FILENO, &fds);
    select(cancelPipe[0]+1, &fds, NULL, NULL, NULL);

    if (FD_ISSET(cancelPipe[0], &fds)){
      break;
    }*/
    if(cancelPipe[0]) {
        break;
    }
    if(kbhit()) {
        s.setDirection(getDirectionFromChar(getch()));
    } else {
        usleep(100000);
    }
  }
  //tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}

} /* namespace FadeCube */
