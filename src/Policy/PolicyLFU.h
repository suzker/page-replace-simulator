/*
 * PolicyLFU.h
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#ifndef POLICYLFU_H_
#define POLICYLFU_H_

#include "Policy.h"
#include <map>
#include <limits>

template<typename T>
class PolicyLFU: public Policy<T> {
private:
	map<T, int> *__count_map;

public:
	PolicyLFU(size_t s) : Policy<T>(s) {
		__count_map = new map<T, int>();
	}

	virtual ~PolicyLFU() {
		delete __count_map;
	}

	virtual bool addPage(T data){
		bool _fault = _testPageFault(data);
		size_t next_frm_idx = _getNextFrameIdx();
		// update the related counts
		if (__count_map->find(data) == __count_map->end()){ // if key not found, that's not in record
			__count_map->insert(pair<T, int>(data, 1));
		} else {
			++(*__count_map)[data];
		}
		// replace faulty pages
		if (_fault){
			return _replaceFrame(next_frm_idx, data);
		}
		return false;
	}

protected:
	virtual size_t _getNextFrameIdx(){
		if (this->__frames->size() < this->__num_frames){
						return (this->__frames->size());
		}
		size_t _least_used_idx = 0;
		int _curr_idx = 0;
		int _min_count = numeric_limits<int>::max();
		typename list<T>::iterator _itr_frm;

		for (_itr_frm = this->__frames->begin(); _itr_frm != this->__frames->end(); ++_itr_frm){
			if ((*(this->__count_map))[*(_itr_frm)] < _min_count){
				_least_used_idx = _curr_idx;
			}
			++_curr_idx;
		}
		return _least_used_idx;
	}
};

#endif /* POLICYLFU_H_ */
