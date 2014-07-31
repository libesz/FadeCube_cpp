/*
 * KeyboardInput.h
 *
 *  Created on: Apr 7, 2014
 *      Author: libesz
 */

#ifndef KEYBOARDINPUT_H_
#define KEYBOARDINPUT_H_

#include <Controllable.h>
#include <mutex>

namespace FadeCube {

class KeyboardInput {
  Controllable &s;
  int cancelPipe[2];

  KeyboardCommand getDirectionFromChar(int ch);

public:
  KeyboardInput(Controllable &newS);
  void cancel();
  void loop();
};

} /* namespace FadeCube */

#endif /* KEYBOARDINPUT_H_ */
