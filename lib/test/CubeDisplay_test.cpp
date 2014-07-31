/*
 * CubeDisplay_test.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: libesz
 */

#include <CubeDisplay.h>
#include <gtest/gtest.h>

namespace FadeCube {

TEST(CubeDisplayTest, DISABLED_TestBasic) {
  CubeDisplay d("192.168.1.99", 1125);
  std::vector<Point> p;
  p.push_back(Point(1,1,0,255));
  p.push_back(Point(1,1,1,255));
  p.push_back(Point(1,1,2,255));
  p.push_back(Point(1,1,3,255));
  d.draw(p);
}

} /* namespace FadeCube */
