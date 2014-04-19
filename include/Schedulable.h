/*
 * Schedulable.h
 *
 *  Created on: Apr 19, 2014
 *      Author: libesz
 */

#ifndef SCHEDULABLE_H_
#define SCHEDULABLE_H_

namespace FadeCube {

class Schedulable {
public:
  Schedulable();
  virtual void tick() = 0;
  virtual ~Schedulable();
};

} /* namespace FadeCube */

#endif /* SCHEDULABLE_H_ */
