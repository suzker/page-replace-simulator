/**
 * Utiltiies class w/ static methods
 * Author: suzker
 */ 
#ifndef __HEADER_UTILITY__
#define __HEADER_UTILITY__
#include <iostream>
#include <string>

using namespace std;

class Util {
    public:
        enum replace_policy_t {FIFO, LFU, LRU_STACK, LRU_CLOCK, LRU_REF8, BELADY};
        static int arg_print_usage;
        static int arg_available_frame;
        static replace_policy_t arg_replace_policy;
        static string arg_input_filepath;
        const int parse(int, char **);
        Util(){};
        ~Util();
};
#endif
