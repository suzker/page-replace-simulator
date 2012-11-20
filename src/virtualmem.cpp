/*
 * virtual mem: main driver
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#include "sstream"
#include "fstream"
#include "Policy/PolicyLFU.h"
#include "Policy/PolicyOptimal.h"
#include "Policy/PolicyFIFO.h"
#include "Policy/PolicyLRUREF8.h"
#include "Policy/PolicyLRUClock.h"
#include "Policy/PolicyLRUStack.h"
#include "Util.h"

#include<sys/types.h>
#include<sys/time.h>

int main(int argc, char ** argv){
	Util ut;
	if(!ut.parse(argc, argv)){
		return 0;
	}
	if (ut.arg_print_usage){
		ut.printUsage();
		return 0;
	}

	string _input;
	if (ut.arg_input_filepath == "N/A"){
		cout << "Please enter your page references, end with [ENTER]." << endl;
		getline(cin, _input);
	} else {
		cout << "Reading page references from file {"<< ut.arg_input_filepath << "}."<< endl;
		ifstream myfile (ut.arg_input_filepath.c_str());
		if (myfile.is_open()){
			while(myfile.good()){
				getline(myfile, _input);
				break;
			}
			myfile.close();
		}
	}

	int page_refs[_input.length()];
	int _count = 0;
    istringstream iss(_input);
    do
    {
        string sub;
        iss >> sub;
        page_refs[_count] = atoi(sub.c_str());;
        ++_count;
    } while (iss);
    --_count; // discard the last one;

    // start using Policies
    Policy<int> * thePolicy;
    switch(ut.arg_replace_policy){
    	case Util::FIFO:
    		thePolicy = new PolicyFIFO<int>(ut.arg_available_frame);
    		break;
    	case Util::LFU:
    		thePolicy = new PolicyLFU<int>(ut.arg_available_frame);
    		break;
    	case Util::LRU_CLOCK:
    		thePolicy = new PolicyLRUClock<int>(ut.arg_available_frame);
    		break;
    	case Util::LRU_REF8:
    		thePolicy = new PolicyLRUREF8<int>(ut.arg_available_frame);
    		break;
    	case Util::LRU_STACK:
    		thePolicy = new PolicyLRUStack<int>(ut.arg_available_frame);
    		break;
    	default:
    		thePolicy = new PolicyFIFO<int>(ut.arg_available_frame);
    		break;
    }

    // optimal algorithm
    PolicyOptimal<int> * cmpPolicy = new PolicyOptimal<int>(page_refs, ut.arg_available_frame, _count);
    struct timeval tv1;
    struct timeval tv2;
    gettimeofday(&tv1, NULL);
    uint start_t = (uint)tv1.tv_usec;
    int optimal_pf = cmpPolicy->getOptimalResult();
    gettimeofday(&tv2, NULL);
    uint end_t = (uint)tv2.tv_usec;
    uint opt_time_usage = end_t - start_t;

    // usr's choice
    gettimeofday(&tv1, NULL);
    start_t = (uint)tv1.tv_usec;
    for (int j = 0; j<_count; ++j){
    	thePolicy->addPage(page_refs[j]);
    }
    gettimeofday(&tv2, NULL);
    end_t = (uint)tv2.tv_usec;
    int normal_pf = thePolicy->getNumPageFault();
    uint norm_time_usage = end_t - start_t;

    cout << "# of page replacements with User's Choice: " << normal_pf << endl;
    cout << "# of page replacements with Optimal: " << optimal_pf << endl;
    cout << "% page replacement penalty using: " << (((double)optimal_pf-(double)normal_pf)/(double)normal_pf) << "%"<< endl;
    cout << endl;
    cout << "Total time to run User's Choice: " << norm_time_usage << "msec" << endl;
    cout << "Total time to run Optimal algorithm: " << opt_time_usage << "msec" << endl;
    cout << "The chosen algorithm is " << (((double)opt_time_usage-(double)norm_time_usage)/(double)norm_time_usage) << " % faster than the Optimal algorithm." << endl;
}
