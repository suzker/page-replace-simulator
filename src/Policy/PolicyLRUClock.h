/*
 * PolicyLRUClock.h
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#ifndef POLICYLRUCLOCK_H_
#define POLICYLRUCLOCK_H_

#include "Policy.h"
#include <map>

template<typename T>
class PolicyLRUClock: public Policy<T> {
private:
	map<T, bool> *__bit_map;

public:
	PolicyLRUClock(size_t s) : Policy<T>(s) {
		__bit_map = new map<T, bool>();
	}

	virtual ~PolicyLRUClock() {
		delete __bit_map;
	}

	virtual bool addPage(T data){
		bool _fault = _testPageFault(data);
		if (_fault){
			// sweep the map and update the ref bit
			typename map<T, bool>::iterator _itr_map;
			for (_itr_map = this->__bit_map->begin(); _itr_map != this->__bit_map->end(); ++_itr_map){
				if (_itr_map->second){
					_itr_map->second = false;
				}
			}
			size_t next_frm_idx = _getNextFrameIdx();
			return this->_replaceFrame(next_frm_idx, data);
		}
		return false;
	}

protected:
	virtual size_t _getNextFrameIdx(){
		if (this->__frames->size() < this->__num_frames){
			return (this->__frames->size());
		}
		size_t _lru_idx = 0;
		int _curr_idx = 0;
		typename map<T, bool>::iterator _map_itr;
		for (_map_itr = this->__bit_map->begin(); _map_itr != __bit_map->end(); ++_map_itr){
			if (!(_map_itr->second)){
				_lru_idx = _curr_idx;
				break;
			}
			++_curr_idx;
		}
		return _lru_idx;
	}
};

#endif /* POLICYLRUCLOCK_H_ */
