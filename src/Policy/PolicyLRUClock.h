/*
 * PolicyLRUClock.h
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#ifndef POLICYLRUCLOCK_H_
#define POLICYLRUCLOCK_H_

#include "Policy.h"

template<typename T>
class PolicyLRUClock: public Policy<T> {
public:
	PolicyLRUClock(size_t s) : Policy<T>(s) {

	}
	virtual ~PolicyLRUClock() {
	}
};

#endif /* POLICYLRUCLOCK_H_ */
