/*
 * PolicyLRUREF8.h
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#ifndef POLICYLRUREF8_H_
#define POLICYLRUREF8_H_

#include "Policy.h"
#include <map>

template<typename T>
class PolicyLRUREF8: public Policy<T> {
private:
	map<T, unsigned int> *__ref_byte_map;

public:
	PolicyLRUREF8(size_t s) : Policy<T>(s) {
		this->__ref_byte_map = new map<T, unsigned int>();
	}

	virtual ~PolicyLRUREF8() {
		delete __ref_byte_map;
	}

	virtual bool addPage(T data){
		if (__ref_byte_map->find(data) == __ref_byte_map->end()){ // if key not found
			__ref_byte_map->insert(pair<T, unsigned int>(data, 0));
		}
		bool _fault = _testPageFault(data);
		size_t next_frm_idx = _getNextFrameIdx();
		if (_fault) {

		}
		// update all references
	}
};

#endif /* POLICYLRUREF8_H_ */
