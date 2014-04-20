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
#include <Schedulable.h>

namespace FadeCube {

class Renderer: public Schedulable {
  Display *d;
  std::vector<Renderable *> objects;
public:
  Renderer(Display* newD);
  void add(Renderable *object);
  void draw() const;
  void tick();
  virtual ~Renderer();
};

} /* namespace FadeCube */

#endif /* RENDERER_H_ */
