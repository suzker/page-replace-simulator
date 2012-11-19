/*
 * PolicyFIFO_test.cpp
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#include "PolicyOptimal.h"


int main(){
	int in[] = {1,2,3,4,5,3,3,3,3,6,6,1};
	int input_size = sizeof in/sizeof(int);
	PolicyOptimal<int> * pf = new PolicyOptimal<int>(in, 4, input_size);
	cout << pf->getOptimalResult() << endl;
	/*// insert pages
	pf->addPage(1);
	pf->addPage(2);
	pf->addPage(3);
	pf->addPage(4);
	pf->addPage(5);
	pf->addPage(3);
	pf->addPage(3);
	pf->addPage(3);
	pf->addPage(3);
	pf->addPage(6);
	pf->addPage(6);
	pf->addPage(1);*/
	return 0;
}
