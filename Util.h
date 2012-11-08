/**
 * Utiltiies class w/ static methods
 * Author: suzker
 */ 
#ifndef __HEADER_UTILITY__
#define __HEADER_UTILITY__
#include <iostream>
#include <string>
#include <string.h> //clib for string

using namespace std;

class Util {
    public:
        static int arg_print_usage;
        static int arg_available_frame;
        static int arg_replace_policy;
        static string arg_input_filepath;
        Util();
        ~Util();
        const int parse(int argc, char * argv[]);
    private:
        static const int RPLCY_FIFO = 1;
        static const int RPLCY_LFU = 2;
        static const int RPLCY_LRU_STACK = 3;
        static const int RPLCY_LRU_CLOCK = 4;
        static const int RPLCY_LRU_REF8 = 5;
        static const int RPLCY_BELADY = 6;
        void __init_arg();
};
#endif
