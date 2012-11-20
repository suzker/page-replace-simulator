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
	PolicyLRUClock() {
		// TODO Auto-generated constructor stub

	}
	virtual ~PolicyLRUClock() {
		// TODO Auto-generated destructor stub
	}
};

#endif /* POLICYLRUCLOCK_H_ */
