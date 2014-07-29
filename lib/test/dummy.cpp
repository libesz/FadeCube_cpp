/*
 * dummy.cpp
 *
 *  Created on: Apr 20, 2014
 *      Author: libesz
 */

#include <ClockSource.h>
#include <Schedulable.h>

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

  class DummyClockSourceExitCondition: public ClockSourceExitCondition {
  public:
    bool cond() {
      return true;
    }
  };

  class DummyClockSource: public ClockSource {
  public:
    DummyClockSource(DummyClockSourceExitCondition &newCond): ClockSource(newCond) {}
    void tickAll() {
      update();
    }
    void loop() {}
  };
}
