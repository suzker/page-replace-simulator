#include "Policy.h"

template<class T>
int Policy<T>::getNumPageFault() const{
    return this->__num_page_fault;
}

template<class T>
void Policy<T>::printFrames(){
    typename list<T>::iterator _itr = __frames->begin();
    while (_itr != __frames->end()){
        cout<< _itr << endl;
    }
}

template<class T>
bool Policy<T>::_replaceFrame(size_t idx, T data) const{
    if (idx >= __frames->size()){return false;}
    typename list<T>::iterator _itr = __frames->begin();
    advance(_itr, idx);
    __pages_loaded->erase(__pages_loaded->find(*_itr));
    typename list<T>::iterator _itr_back = __frames->erase(_itr);
    __frames->insert(_itr_back, data);
    __pages_loaded->insert(data);
    return true;
}

template<class T>
bool Policy<T>::_testPageFault(T data) const{
    if (this->__pages_loaded->find(data) != __pages_loaded->end()){
        ++(this->__num_page_fault);
        return true;
    }
    return false;
}
