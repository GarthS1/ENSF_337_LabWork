//list.h

#ifndef list_H
#define list_H

struct ListItem
{
  int year;
  double flow;
};

struct Node 
{
 ListItem item;
 Node *next;
};

class FlowList
{
  public:
  FlowList(); // PROMISES: Creates empty list.
  ~FlowList();
  
	int insert(const ListItem& itemA);

  int remove(int year);
	  
  Node* headM;
  
  private:
	void destroy();
	
	void copy(const FlowList& source); 
};
#endif
