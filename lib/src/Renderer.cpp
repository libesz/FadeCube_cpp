/*
 * Renderer.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <vector>
#include <Renderer.h>
#include <Point.h>

namespace FadeCube {

Renderer::Renderer(Display &newD): d(newD) {
}

void Renderer::draw() const {
  std::vector<Point> result;
  for (auto o : objects) {
    std::vector<Point> temp = o->render();
    result.insert(result.end(), temp.begin(), temp.end());
  }
  d.draw(result);
}

void Renderer::tick() {
  draw();
}

void Renderer::add(Renderable* object) {
  objects.push_back(object);
}

Renderer::~Renderer() {
	// TODO Auto-generated destructor stub
}

} /* namespace FadeCube */
