/*
 * Game2048_test.cpp
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 */

#include <Game2048.h>
#include <CubeProp.h>
#include <gtest/gtest.h>

namespace FadeCube {
TEST(Game2048Test, GetInitialZeroTable) {
  const int gridSize = 4;
  Game2048 g(CubeProp(10), gridSize, gridSize);
  for(int i = 0; i < gridSize * gridSize; i++)
    EXPECT_EQ(0, g.getSlotValue((i/gridSize), (i%gridSize)));
}

TEST(Game2048Test, GetEmptyRenderAfterCreate) {
  const int gridSize = 4;
  Game2048 g(CubeProp(10), gridSize, gridSize);
  EXPECT_EQ(0, g.render().size());
}

} /* namespace FadeCube */
