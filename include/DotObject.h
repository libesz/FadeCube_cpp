/*
 * DotObject.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef DOTOBJECT_H_
#define DOTOBJECT_H_

#include <Renderable.h>
#include <Adjustable.h>

namespace FadeCube {

class DotObject: public Renderable, public Adjustable {
  Point data;
public:
  DotObject(int newX, int newY, int newZ, int newBr);
	void moveAbsolute(int x, int y, int z);
	void moveRelative(int x, int y, int z);

	virtual ~DotObject();
  const std::vector<Point> render() const;
};

} /* namespace FadeCube */

#endif /* DOTOBJECT_H_ */
