/*
 * Renderer.h
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include <vector>
#include <Display.h>
#include <Renderable.h>

namespace FadeCube {

class Renderer {
  Display *d;
public:
  Renderer(Display* newD);
  void draw(const std::vector<Renderable *> objects) const;
	virtual ~Renderer();
};

} /* namespace FadeCube */

#endif /* RENDERER_H_ */
