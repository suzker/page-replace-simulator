/**
 * Implementation of FIFO policy using STL Queue container
 * Author: suzker
**/
#ifndef __HEADER_POLICY_FIFO__
#define __HEADER_POLICY_FIFO__
#include <iostream>
#include <queue>
#include "Policy.h"

template<typename T>
class PolicyFIFO : public Policy<T>{
    private:
        queue<T> * _page_loaded_q;
        
}

#endif
