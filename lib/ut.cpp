/*
 * ut.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: libesz
 */

#include <iostream>
#include <gtest/gtest.h>

int main( int argc, char **argv ) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
