/*
 * ClockSource_test.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: libesz
 */

#include <ClockSource.h>
#include <Schedulable.h>
#include <gtest/gtest.h>

namespace FadeCube {
  class DummySchedulable: public Schedulable {
    int tickCount;
  public:
    DummySchedulable(): tickCount(0) {
    }
    void tick() {
      tickCount++;
    }
    int getTickCount() {
      return tickCount;
    }
  };

  class DummyClockSource: public ClockSource {
  public:
    void tickAll() {
      update();
    }
  };

  TEST(ClockSourceTest, CreateAndReg) {
    DummySchedulable sch1, sch2;
    DummyClockSource cs;
    cs.reg(&sch1);
    cs.reg(&sch2);
    cs.tickAll();
    EXPECT_EQ(1,sch1.getTickCount());
    EXPECT_EQ(1,sch2.getTickCount());
  }
} /* namespace FadeCube */
