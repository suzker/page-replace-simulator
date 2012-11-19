/*
 * PolicyFIFO_test.cpp
 *
 *  Created on: Nov 19, 2012
 *      Author: zsu2
 */

#include "PolicyFIFO.h"


int main(){
	Policy<int> * pf = new PolicyFIFO<int>(4);
	cout << "Page faults: " << pf->getNumPageFault() << endl;
	// insert pages
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
	pf->addPage(1);
	cout << "Page faults: " << pf->getNumPageFault() << endl;
}
