/*
 * PolicyLRUStack.h
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#ifndef POLICYLRUSTACK_H_
#define POLICYLRUSTACK_H_

#include "Policy.h"
#include <list>
#include <algorithm>

template<typename T>
class PolicyLRUStack: public Policy<T> {
private:
	list<T> * __stack_list;

public:
	PolicyLRUStack(size_t s) : Policy<T>(s) {
		__stack_list = new list<T>();
	}
	virtual ~PolicyLRUStack() {
		delete __stack_list;
	}

	virtual bool addPage(T data){
		bool _result = false;
		bool _fault = _testPageFault(data);
		size_t next_frm_idx = _getNextFrameIdx();
		if (_fault){
			typename list<T>::iterator _itr = this->__frames->begin();
			advance(_itr, next_frm_idx);
			T _old_data = *(_itr);
			__stack_list->erase(find(__stack_list->begin(), __stack_list->end(), _old_data));
			_result = _replaceFrame(next_frm_idx, data);
			__stack_list->push_front(data);
		}
		return _result;
	}

protected:
	virtual size_t _getNextFrameIdx(){
		if (this->__frames->size() < this->__num_frames){
			return (this->__frames->size());
		}
		T _lru_data = this->__stack_list->back();
		size_t _lru_idx=0;
		typename list<T>::iterator _itr_frm;
		for (_itr_frm = this->__frames->begin(); _itr_frm != this->__frames->end(); ++_itr_frm){
			if (*_itr_frm == _lru_data) {
				break;
			}else{
				++_lru_idx;
			}
		}
		return _lru_idx;
	}
};

#endif /* POLICYLRUSTACK_H_ */
