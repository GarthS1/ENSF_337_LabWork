//list.h

#ifndef list_H
#define list_H

struct ListItem
{
  int year;
  double flow;
};

struct Node {
 ListItem item;
 Node *next;
};

class FlowList {
    
  public:
  FlowList(); // PROMISES: Creates empty list.
  FlowList(const FlowList& source);
  FlowList& operator =(const FlowList& rhs);
  ~FlowList();
  
	void insert(const ListItem& itemA);

  void remove(const ListItem& itemA);
	
	void print() const;
  
  Node* headM;
  
  private:
	void destroy();
	
	void copy(const FlowList& source);
  
};
#endif
