/**
 * Parent abstraction class for policy implementations
**/
#ifndef __HEADER_POLICY__
#define __HEADER_POLICY__
#include <iostream>
#include <list>
#include <set>
#define DEFAULT_FRAME_SIZE 5;

using namespace std;
template<class T>
class Policy{
    public:
        Policy(size_t num_frames){
            _num_frames = num_frames;
            __frames = new list<T>();
            __pages_loaded = new set<T>();
            __num_page_fault = 0;
        }
        ~Policy();
        virtual bool addPage(T) const;
        int getNumPageFault() const;
        void printFrames();

    private:
        list<T> * __frames;
        set<T> * __pages_loaded;
        int __num_page_fault;

    protected:
        size_t _num_frames;
        virtual size_t _getNextFrameIdx() const;
        virtual bool _replaceFrame(size_t, T) const;
        bool _testPageFault(T) const;
};

#endif
