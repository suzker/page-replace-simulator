/*
 * PolicyOptimal.h
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#ifndef POLICYOPTIMAL_H_
#define POLICYOPTIMAL_H_

#include "Policy.h"
#include <limits>

template<typename T>
class PolicyOptimal: Policy<T> {
private:
	T * __entire_input;
	int __curr_pos;
	int __input_size;

public:
	PolicyOptimal(T *in_array, size_t s, int in_size) : Policy<T>(s){
		__entire_input = in_array;
		__curr_pos = 0;
		__input_size = in_size;
		cout << "size: " << __input_size <<endl;
	}

	virtual ~PolicyOptimal() {
		delete(__entire_input);
	}

	/**
	 * Convenient function to get the result directly
	 */
	int getOptimalResult(){
		for (int j = this->__curr_pos; j< this->__input_size; ++j){
			this->addPage(__entire_input[j]);
		}
		return this->getNumPageFault();
	}

	virtual bool addPage(T data){
        bool _fault = _testPageFault(data);
        size_t next_frm_idx =  _getNextFrameIdx();
        ++this->__curr_pos;
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
		int _curr_count;
		typename list<T>::iterator _itr_frm;

		for (_itr_frm = this->__frames->begin(); _itr_frm != this->__frames->end(); ++_itr_frm){
			_curr_count = 0;
			for (int j = this->__curr_pos; j< this->__input_size; ++j){
				if (this->__entire_input[_curr_idx] == *(_itr_frm)){
					++_curr_count;
				}
			}
			if (_curr_count < _min_count){
				_least_used_idx = _curr_idx;
			}
			++_curr_idx;
		}
		return _least_used_idx;
	}
};

#endif /* POLICYOPTIMAL_H_ */
