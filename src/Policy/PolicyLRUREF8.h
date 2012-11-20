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
#include <stdint.h> // uint8_t
#include <limits> // numeric_limits<int>::max()

template<typename T>
class PolicyLRUREF8: public Policy<T> {
private:
	map<T, uint8_t> *__ref_byte_map;

public:
	PolicyLRUREF8(size_t s) : Policy<T>(s) {
		this->__ref_byte_map = new map<T, uint8_t>();
	}

	virtual ~PolicyLRUREF8() {
		delete __ref_byte_map;
	}

	virtual bool addPage(T data){
		if (__ref_byte_map->find(data) == __ref_byte_map->end()){ // if key not found
			__ref_byte_map->insert(pair<T, uint8_t>(data, 0));
		}
		bool _result = false;
		bool _fault = _testPageFault(data);
		size_t next_frm_idx = _getNextFrameIdx();
		if (_fault) {
			_result = _replaceFrame(next_frm_idx, data);
		}
		// update all references
		typename map<T, uint8_t>::iterator _map_itr;
		for (_map_itr = __ref_byte_map->begin(); _map_itr != __ref_byte_map->end(); ++_map_itr){
			(*__ref_byte_map)[_map_itr->first] = (*__ref_byte_map)[_map_itr->first]>>1;
			// give the current occurred page a little bit credit
			if (this->__pages_loaded->find(_map_itr->first) == this->__pages_loaded->end()){
				(*__ref_byte_map)[_map_itr->first] = (*__ref_byte_map)[_map_itr->first] | 0x80;
			}
		}
		return _result;
	}

protected:
	virtual size_t _getNextFrameIdx(){
		if (this->__frames->size() < this->__num_frames){
			return (this->__frames->size());
		}
		size_t _lru_idx = 0;
		int _curr_idx = 0;
		int _min_ref = numeric_limits<int>::max();
		typename map<T, uint8_t>::iterator _map_itr;
		for (_map_itr = this->__ref_byte_map->begin(); _map_itr != __ref_byte_map->end(); ++_map_itr){
			if (int(_map_itr->second) < _min_ref){
				_lru_idx = _curr_idx;
			}
			++_curr_idx;
		}
		return _lru_idx;
	}

};

#endif /* POLICYLRUREF8_H_ */
