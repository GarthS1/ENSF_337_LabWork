//list.cpp

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList()
: headM(0) 
{
}

FlowList::~FlowList()
{
	destroy();
}

int FlowList::insert(const ListItem& itemA)
{
	// checks to see if duplicate year 
	Node* tracker = headM;
	while(tracker != 0)
	{
		if(tracker -> item.year == itemA.year)
		{
			return 0;
		}
		tracker =  tracker -> next;
	}
	
	//Otherwise, inserts in order of flow 
	Node *new_node = new Node;
	new_node -> item.year = itemA.year;
	new_node -> item.flow = itemA.flow;
	
	if( headM == 0 || itemA.flow < headM -> item.flow )
	{
		new_node -> next = headM;
		headM = new_node;
	}
	else
	{
		Node* before = headM;
		Node* after = headM -> next;
		while( after != 0 && itemA.flow > after -> item.flow)
		{
			before = after;
			after = after -> next;
		}
		new_node -> next = after;
		before->next = new_node;
	}
	
	return 1;
}

int FlowList::remove(int year )
{
	if (headM == 0)
		return 0;
 
  Node *doomed_node = 0;
    
  if (year == headM->item.year) 
	{
    doomed_node = headM;
    headM = headM->next;
  }
  else 
	{
    Node *before = headM;
    Node *maybe_doomed = headM->next;
		
    while(maybe_doomed != 0 && year != maybe_doomed -> item.year) 
		{
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->next;
    }
		
		if(maybe_doomed != 0)
		{
			if(maybe_doomed -> item.year == year)
			{
				before -> next = maybe_doomed -> next;
				doomed_node = maybe_doomed;
			}
		}		
  }
	
	// checks to see if matching node than deletes if matched
	if(doomed_node != 0){	
		delete doomed_node;
		return 1;
	}
	
	return 0;
}
	
void FlowList::destroy()
{
	Node* before = headM;
	while(before != 0){
		Node* temp = before -> next;
		delete before;
		before = temp;
	}
  headM = 0;
}
	


