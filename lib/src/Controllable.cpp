/*
 * Controllable.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: libesz
 */

#include <Controllable.h>

namespace FadeCube {

#if ( DEBUG )
std::ostream& operator<<(std::ostream &out, const Direction &d) {
  switch (d) {
  case Direction::FORWARD:
    out << "FORWARD";
    break;
  case Direction::BACKWARD:
    out << "BACKWARD";
    break;
  case Direction::LEFT:
    out << "LEFT";
    break;
  case Direction::RIGHT:
    out << "RIGHT";
    break;
  case Direction::UP:
    out << "UP";
    break;
  case Direction::DOWN:
    out << "DOWN";
    break;
  default:
    out << "UNKNOWN";
    break;
  }
  return out;
}
#endif

} /* namespace FadeCube */
