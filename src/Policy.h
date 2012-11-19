/*
 * Policy.h
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#ifndef POLICY_H_
#define POLICY_H_

#include <iostream>
#include <list>
#include <set>

using namespace std;
template<typename T>
class Policy {
public:
	Policy(size_t s) {
		this->__num_frames = s;
		this->__frames = new list<T>();
		this->__pages_loaded = new set<T>();
		this->__num_page_fault = 0;
	}
	virtual ~Policy() {
		delete(this->__frames);
		delete(this->__pages_loaded);
	}

	virtual bool addPage(T) = 0;
	int getNumPageFault(){
		return this->__num_page_fault;
	}

protected:
	int __num_page_fault;
	list<T> * __frames;
	set<T> * __pages_loaded;
	size_t __num_frames;
	virtual size_t _getNextFrameIdx() = 0;

	bool _replaceFrame(size_t idx, T data){
		if (this->__frames->size() < this->__num_frames){
			this->__frames->push_back(data);
			this->__pages_loaded->insert(data);
			return true;
		}
		if (idx >= this->__num_frames){return false;}
		typename list<T>::iterator _itr_old_value = this->__frames->begin();
		advance(_itr_old_value, idx);
		this->__pages_loaded->erase(this->__pages_loaded->find(*_itr_old_value));
		_itr_old_value = __frames->erase(_itr_old_value);
		this->__frames->insert(_itr_old_value, data);
		this->__pages_loaded->insert(data);
		return true;
	}

	bool _testPageFault(T data){
	    if (this->__pages_loaded->find(data) == this->__pages_loaded->end()){
	        ++(this->__num_page_fault);
	        return true;
	    }
	    return false;
	}
};

#endif /* POLICY_H_ */
