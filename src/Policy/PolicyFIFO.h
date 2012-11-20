/*
 * PolicyFIFO.h
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#ifndef POLICYFIFO_H_
#define POLICYFIFO_H_

#include "Policy.h"
#include <queue>

template <typename T>
class PolicyFIFO: public Policy<T> {
private:
	queue<size_t> * __frame_used_q;

public:
	PolicyFIFO(size_t s) : Policy<T>(s) {
		this->__frame_used_q = new queue<size_t>();
	}

	virtual ~PolicyFIFO() {

	}

    virtual bool addPage(T data){
        bool _fault = _testPageFault(data);
        size_t next_frm_idx =  _getNextFrameIdx();
        if (_fault){
        	this->__frame_used_q->push(next_frm_idx);
        	if (this->__frame_used_q->size() > this->__num_frames){
        		this->__frame_used_q->pop();
        	}
        	return _replaceFrame(next_frm_idx, data);
        }
        return false;
    }

protected:
    virtual size_t _getNextFrameIdx(){
    	if (this->__frame_used_q->size() < this->__num_frames){
    		return this->__frame_used_q->size();
    	}
    	return this->__frame_used_q->front();
	}
};

#endif /* POLICYFIFO_H_ */
