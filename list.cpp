//list.cpp

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList()
: headM(0) 
{
	tracker = 0;
}

FlowList::~FlowList()
{
  Node* before = headM;
	while(before != 0){
		Node* temp = before -> next;
		delete before;
		before = temp;
	}
  headM = 0;
}
