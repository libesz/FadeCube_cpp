/*
 * DotObject.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef DOTOBJECT_H_
#define DOTOBJECT_H_

#include <Renderable.h>

namespace FadeCube {

class DotObject: public Renderable {
  Point data;
public:
  DotObject(int newX, int newY, int newZ, int newBr);
  virtual ~DotObject();
  const std::vector<Point> render() const;
};

} /* namespace FadeCube */

#endif /* DOTOBJECT_H_ */
