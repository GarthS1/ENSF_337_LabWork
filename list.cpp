//list.cpp

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList()
: headM(0) 
{
}

FlowList::FlowList(const FlowList& source)
{
	copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
	if (this != &rhs)
	{
		destroy();
		copy(rhs);
	}
	return *this;
}

FlowList::~FlowList()
{
	destroy();
}
  
void FlowList::print() const
{
	//later
}

void FlowList::insert(const ListItem& itemA)
{
	Node *new_node = new Node;
	new_node -> item.year = itemA.year;
	new_node -> item.flow = itemA.flow;
	
	if( headM == 0 || itemA.flow <= headM -> item.flow)
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
}

void FlowList::remove(const ListItem& itemA)
{
	//later
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
	
void FlowList::copy(const FlowList& source)
{
	
}
  


