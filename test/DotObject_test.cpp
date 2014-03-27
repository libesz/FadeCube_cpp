/*
 * DotObject_test.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <DotObject.h>
#include <gtest/gtest.h>
#include <vector>

namespace FadeCube {

TEST(DotObjectTest, TestCreateAndRender) {
	DotObject o(0,0,0,0);
	std::vector<Point> p = o.render();
	EXPECT_EQ(1, p.size());
	EXPECT_EQ(0, p.begin()->getX());
	EXPECT_EQ(0, p.begin()->getY());
	EXPECT_EQ(0, p.begin()->getZ());
	EXPECT_EQ(0, p.begin()->getBr());
}

TEST(DotObjectTest, TestMoveAbsolute) {
	DotObject o(0,0,0,0);
	o.moveAbsolute(1, 2, 3);
	std::vector<Point> p = o.render();
	EXPECT_EQ(1, p.begin()->getX());
	EXPECT_EQ(2, p.begin()->getY());
	EXPECT_EQ(3, p.begin()->getZ());
	EXPECT_EQ(0, p.begin()->getBr());
}

TEST(DotObjectTest, TestMoveRelative) {
	DotObject o(1,2,3,0);
	o.moveRelative(-1, -2, -3);
	std::vector<Point> p = o.render();
	EXPECT_EQ(0, p.begin()->getX());
	EXPECT_EQ(0, p.begin()->getY());
	EXPECT_EQ(0, p.begin()->getZ());
	EXPECT_EQ(0, p.begin()->getBr());
}

} /* namespace FadeCube */
