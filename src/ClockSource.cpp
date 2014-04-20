/*
 * ClockSource.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: libesz
 */

#include <ClockSource.h>
#include <algorithm>

namespace FadeCube {

ClockSource::ClockSource() {
  // TODO Auto-generated constructor stub

}

void ClockSource::add(Schedulable* s) {
  observers.push_back(s);
}

void ClockSource::dereg(Schedulable* s) {
  observers.erase(find(observers.begin(), observers.end(), s));
}

void ClockSource::update() {
  for(auto it: observers) {
    it->tick();
  }
}

ClockSource::~ClockSource() {
  // TODO Auto-generated destructor stub
}

} /* namespace FadeCube */
