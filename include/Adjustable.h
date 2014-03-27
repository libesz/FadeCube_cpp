/*
 * Adjustable.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef ADJUSTABLE_H_
#define ADJUSTABLE_H_

namespace FadeCube {

class Adjustable {
public:
	virtual void moveAbsolute(int x, int y, int z) = 0;
	virtual void moveRelative(int x, int y, int z) = 0;
	virtual ~Adjustable();
};

} /* namespace FadeCube */

#endif /* ADJUSTABLE_H_ */
