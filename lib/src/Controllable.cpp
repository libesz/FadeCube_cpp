/*
 * Controllable.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: libesz
 */

#include <Controllable.h>

namespace FadeCube {

#if ( DEBUG )
std::ostream& operator<<(std::ostream &out, const KeyboardCommand &d) {
  switch (d) {
  case KeyboardCommand::FORWARD:
    out << "FORWARD";
    break;
  case KeyboardCommand::BACKWARD:
    out << "BACKWARD";
    break;
  case KeyboardCommand::LEFT:
    out << "LEFT";
    break;
  case KeyboardCommand::RIGHT:
    out << "RIGHT";
    break;
  case KeyboardCommand::UP:
    out << "UP";
    break;
  case KeyboardCommand::DOWN:
    out << "DOWN";
    break;
  case KeyboardCommand::EXIT:
    out << "EXIT";
    break;
  default:
    out << "UNKNOWN";
    break;
  }
  return out;
}
#endif

} /* namespace FadeCube */
