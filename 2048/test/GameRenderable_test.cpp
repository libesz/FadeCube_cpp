/*
 * GameRenderable_test.cpp
 *
 *  Created on: May 9, 2014
 *      Author: libesz
 */

#include <GameRenderable.h>
#include <gtest/gtest.h>

namespace FadeCube {

TEST(GameRenderable, GetInitialZeroTable) {
  const int gridSize = 4;
  GameTable g(CubeProp(10), gridSize, gridSize);
  GameRenderable r(g);
  EXPECT_EQ(0, r.render().size());
}

TEST(GameRenderable, CheckCorrectRendering) {
  const int gridSize = 4;
  GameTable g(CubeProp(10), gridSize, gridSize);
  g.setSlotValue(0, 0, 2);
  GameRenderable r(g);
  std::vector<Point> result = r.render();
  EXPECT_EQ(1, result.size());
}

} /* namespace FadeCube */
