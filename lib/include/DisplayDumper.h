/*
 * DisplayDumper.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef DISPLAYDUMPER_H_
#define DISPLAYDUMPER_H_

#include <Display.h>

namespace FadeCube {

class DisplayDumper: public Display {
public:
	virtual ~DisplayDumper();
  void draw(const std::vector<Point> data) const;
};

} /* namespace FadeCube */

#endif /* DISPLAYDUMPER_H_ */
