/*
 * Game2048_test.cpp
 *
 *  Created on: May 2, 2014
 *      Author: libesz
 */

#include <GameTable.h>
#include <CubeProp.h>
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>

namespace FadeCube {

void dumpTable(const GameTable &table) {
  for (int i = 0; i < table.getGridX(); i++) {
    for (int j = 0; j < table.getGridX(); j++) {
      std::cout << table.getSlotValue(i, j);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

TEST(GameTableTest, GetInitialZeroTable) {
  const int gridSize = 4;
  GameTable g(CubeProp(10), gridSize, gridSize);
  for(int i = 0; i < gridSize * gridSize; i++)
    EXPECT_EQ(0, g.getSlotValue((i/gridSize), (i%gridSize)));
}

TEST(GameTableTest, EngagedCountAfterCreateOnEmptyPlace) {
  const int gridSize = 4;
  GameTable g(CubeProp(10), gridSize, gridSize);
  for(int i = 0; i < gridSize * gridSize; i++) {
    int nonZeroes = 0;
    for(int j = 0; j < gridSize * gridSize; j++)
      if(g.getSlotValue((j/gridSize), (j%gridSize)))
        nonZeroes++;
    EXPECT_EQ(i, nonZeroes);
    g.generateAtRandomEmptyPlace();
  }
}

TEST(GameTableTest, ThrowsWhenTableFilled) {
  const int gridSize = 4;
  GameTable g(CubeProp(10), gridSize, gridSize);
  for(int i = 0; i < gridSize * gridSize; i++) {
    g.generateAtRandomEmptyPlace();
  }
  EXPECT_THROW(g.generateAtRandomEmptyPlace(), std::runtime_error);
}

TEST(GameTableTest, SetValidValue) {
  const int gridSize = 4;
  GameTable g(CubeProp(10), gridSize, gridSize);
  for(int i = 2;  i <= 2048; i *= 2) {
    g.setSlotValue(0,0,i);
    EXPECT_EQ(i, g.getSlotValue(0,0));
  }
}

TEST(GameTableTest, ThrowsWhenSetInvalidValue) {
  const int gridSize = 4;
  GameTable g(CubeProp(10), gridSize, gridSize);
  EXPECT_THROW(g.setSlotValue(0,0,3), std::runtime_error);
  EXPECT_THROW(g.setSlotValue(0,0,13), std::runtime_error);
  EXPECT_THROW(g.setSlotValue(0,0,553), std::runtime_error);
  EXPECT_THROW(g.setSlotValue(0,0,1233), std::runtime_error);
}

TEST(GameTableTest, MergeDown) {
  const int gridSize = 4;
  GameTable g(CubeProp(10), gridSize, gridSize);
  g.setSlotValue(0,0,2);
  g.setSlotValue(1,0,2);
  dumpTable(g);
  EXPECT_TRUE(g.mergeDown());
  dumpTable(g);
}

TEST(GameTableTest, ShiftDown) {
  const int gridSize = 4;
  GameTable g(CubeProp(10), gridSize, gridSize);
  g.setSlotValue(0,0,2);
  g.setSlotValue(1,0,2);
  dumpTable(g);
  EXPECT_TRUE(g.shiftDown());
  dumpTable(g);
}

} /* namespace FadeCube */
