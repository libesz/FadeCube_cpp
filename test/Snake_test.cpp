/*
 * Snake_test.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: libesz
 */

#include <Snake.h>
#include <gtest/gtest.h>
#include <stdexcept>

namespace FadeCube {

TEST(SnakeTest, TestCreateAndThrowsBeforeStarted) {
	Snake s(10,10,10);
	EXPECT_THROW(s.render(), std::logic_error );
}

TEST(SnakeTest, TestStartable) {
	Snake s(10,10,10);
	s.start(0, 0, 0, Snake::direction::FORWARD);
	/* TODO: render snake and check that it is 1 long */
}

} /* namespace FadeCube */
