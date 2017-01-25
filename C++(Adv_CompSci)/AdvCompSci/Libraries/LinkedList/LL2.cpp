#include <iostream>
#include <string>
using namespace std;



class LinkedList
{
private:
  struct Node
  {
    string name;
    Node *pNext;
  };

  Node *current;
  Node *first;
public:
  LinkedList();
  LinkedList(string);
  void Last();
  void addList(string);
  void displayList();
};


LinkedList::LinkedList()
{
    current = NULL;
    first = NULL;
}

LinkedList::LinkedList(string nm)
{

    current = first = new Node;
    first -> name = nm;
    first -> pNext = NULL;
}
void LinkedList::Last()
{
   if(current != NULL)
     { 
         while(current -> pNext != NULL)
            current = current -> pNext;

     }
}
void LinkedList::addList(string nm)
{
  if(current == NULL)            // empty list
    {
      current = new Node;
      current -> name = nm;
      current -> pNext = NULL;
      first = current;

    }
  else
    {
      Last();
      current -> pNext = new Node;
      current = current -> pNext;
      current -> name = nm;
      current -> pNext = NULL;

    }
}


void LinkedList::displayList()
{
    Node *temp=first;
    while(temp!=NULL)
    {
       cout<<temp->name;
        if(temp->pNext!=NULL)
          cout<<" ";
        temp=temp->pNext;
    }
	delete(temp);
}



int main()
{
  LinkedList c1;
//  c1.InitList();
   c1.addList("Bob");
   c1.addList("Mary");
   c1.addList("Joe");
   c1.addList("Beth");
  c1.displayList();
  return 0;
}