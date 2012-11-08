#include "Util.h"

Util::Util(){
   Util::__init_arg();
}

void Util::__init_arg(){
    Util::arg_print_usage = 0;
    Util::arg_available_frame = 5;
    Util::arg_replace_policy = RPLCY_FIFO;
    Util::arg_input_filepath = "N/A";
}

const int Util::parse(int argc, char * argv[]){
    int i, err = 0;
    for (i=1; i<argc; ++i){
        if (err == 1) {
            err = 1;
            break;
        }
        if (argv[i][0] != '-'){
            err = 1;
            break;
        } else {
            switch (argv[i][1]){
                case 'h':
                    Util::arg_print_usage = 1;
                    break;
                case 'f':
                    Util::arg_available_frame = ++i < argc ? atoi(argv[i]) : 5;
                    err = i <argc ? 0: 1;
                    break;
                case 'i':
                    if (++i < argc){
                        Util::arg_input_filepath = argv[i];
                    } else {
                        err = 1;
                    }
                    break;
                case 's':
                    if (++i < argc) {
                        string _tmp_ = argv[i];
                        if(_tmp_ == "FIFO") {
                            Util::arg_replace_policy = RPLCY_FIFO;
                            break;
                        }
                        if(_tmp_ == "LFU") {
                            Util::arg_replace_policy = RPLCY_LFU;
                            break;
                        }
                        if(_tmp_ == "LRU_STACK") {
                            Util::arg_replace_policy = RPLCY_LRU_STACK;
                            break;
                        }
                        if(_tmp_ == "LRU_CLOCK") {
                            Util::arg_replace_policy = RPLCY_LRU_CLOCK;
                            break;
                        }
                        if(_tmp_ == "LRU_REF8") {
                            Util::arg_replace_policy = RPLCY_LRU_REF8;
                            break;
                        }
                        if(_tmp_ == "OPTIMAL") {
                            Util::arg_replace_policy = RPLCY_BELADY;
                            break;
                        }
                    } else {
                        err = 1;
                    }
                    break;
                default:
                    err = 1;
                    break;
            }
        }
        if (err == 1) {
            cerr << "[ERR] incorrect arguments." << endl;
            return 0;
        }
        return 1;
    }
}
