// A C++ program to implement Double Linked list
#include<iostream>

using namespace std;

struct node
{
  node *prev;
  int data;
  node *next;
}

class dl_list
{
public:
  node *head;
  node *tail;

  dl_list()         //Default Constructor
  {
   head = NULL;
   tail = NULL;
  }

  void createNode(int value)          //Function creates a node
  {
    node *temp =  new node;
    temp -> data = value;
    temp -> prev = NULL;
    temp -> next = NULL;

    if(head == NULL)
    {
      head = temp;
      tail = temp;
      temp = NULL;
    }
    else
    {
      tail-> next = temp;
      temp -> prev = tail;
      tail = temp;
    }
  }

  void display()              // Display linkedlist
  {
    node *temp =  new node;
    temp = head;

    while((temp->next)!=NULL)
    {
      cout << temp->data<<endl;
      temp = temp -> next;
    }
  }

  void insert_start(int value)      // Insert value at the beginning of linked list
  {
    node *temp =  new node;
    temp -> data = value;
    temp -> next = head;
    temp -> prev = NULL;
    head = temp;
  }

  void insert_pos(int pos, int val)       // Insert value at the given position of linked list
  {
    node *temp = new node;
    node *back = new node;
    node *curr = new node;

    curr = head;

    for(int i=0;i<pos;i++)
    {
      back = curr;
      curr = curr->next;
    }

    temp -> data = value;
    temp -> next = curr;
    temp -> prev = back;
    curr -> prev = temp;
    back -> next = temp;
  }

  void delete_last()          // Delete value at the beginning of linked list
  {
    node *temp = new node;

    temp = head;
    head = head -> next;
    delete temp;
  }

  void  delete_last()         // Delete value at the end of linked list
  {
    node *curr = new node;
    node *back = new node;

    curr = head;

    while((curr->next)!=NULL)
    {
      back = curr;
      curr = curr -> next;
    }

    tail = back;
    back -> next = NULL;
    delete curr;
  }

  void delete_pos(int pos,int value)      // Delete value at the given position of linked list
  {
    node *temp = new node;
    node *back = new node;
    node *curr = new node;
    node *following =  new node;

    curr = head;

    for(int i=0;i<pos;i++)
    {
      back = curr;
      curr = curr -> next;
      following = curr -> next;
    }

    back -> next = following;
    following -> prev = back;
    delete curr;
  }
};

int main()
{
  l_list obj1;

  obj1.createNode(1);
  obj1.createNode(2);
  obj1.createNode(3);
  obj1.insert_start(4);

  obj1.display();

  obj1.delete_first();
  cout<<endl;
  obj1.display();
  cout<<endl;
  obj1.delete_last();
  cout<<endl;
  obj1.display();
  obj1.reverse_iter();

  return 0;
}
