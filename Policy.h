/**
 * Parent abstraction class for policy implementations
**/
#ifndef __HEADER_POLICY__
#define __HEADER_POLICY__
#include <iostream>
#include <list>
#define DEFAULT_FRAME_SIZE 5;

using namespace std;
template<typename T>
class Policy{
    public:
        Policy(){
            Policy(DEFAULT_FRAME_SIZE);
        }
        Policy(int size){
            _frames = new list<T>(size);
            _pages_loaded = new set<T>(size);
        }
        virtual size_t getNextFrameIdx() const;
        virtual bool replaceFrame(size_t idx, T data) const{
            if (idx >= _frames->size()){return false;}
            typename list<T>::iterator _itr = _frames->begin();
            _itr+=idx;
            _pages_loaded->erase(_pages_loaded->find(*_itr));
            typename list<T>::iterator _itr_back = _frames->erase(_itr);
            _frames->insert(_itr_back, data);
            _pages_loaded->insert(data);
            return true;
        }
        ~Policy();
    private:
        size_t _num_frames;
        list<T> * _frames;
        set<T> * _pages_loaded;
    protected:
        bool _isPageFaultExist(T data) const{
            if (_pages_loaded->find(data) != _pages_loaded->end()){
                return true;
            }
            return false;
        }
}

#endif
