//Program to implement Single linked list in c++

#include<iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

class l_list
{
public:
  node *head,*tail;

  l_list()        //Constructor
  {
    head=NULL;
    tail=NULL;
  }

void createNode(int value)    // Creating a Node
{
  node *temp = new node;
  temp -> data = value;
  temp -> next = NULL;

  if(head==NULL)
  {
    head=temp;
    tail=temp;
    temp=NULL;
  }
  else
  {
    tail -> next = temp;
    tail = temp;
  }
}

void display()      // Displaying Linked List
{
  node *temp = new node;
  temp = head;
  while(temp!=NULL)
  {
    cout << temp -> data <<endl;
    temp = temp -> next;
  }
}

void insert_start(int value)      // Insert value at the beginning of linked list
{
  node *temp = new node;
  temp -> data =  value;
  temp -> next = head;
  head = temp;
}

void insert_pos(int pos, int value)   // Insert value at the given position of linked list
{
  node *temp = new node;
  node *prev = new node;
  node *curr = new node;

  curr = head;
  for(int i=0;i<pos;i++)
  {
    prev = curr;
    curr = curr -> next;
  }
  temp -> data = value;
  temp -> next = curr;
  prev -> next = temp;
}

void delete_first()       // Delete value at the beginning of linked list
{
  node *temp = new node;
  temp = head;
  head = head -> next;
  delete temp;
}

void delete_last()        // Delete value at the end of linked list
{
  node *curr = new node;
  node *prev = new node;

  curr =  head;

  while((curr->next)!=NULL)
  {
    prev = curr;
    curr = curr -> next;
  }
  tail = prev;
  prev -> next = NULL;
  delete curr;
}

void delete_pos(int pos)      // Delete value at the given position of linked list
{
  node* curr = new node;
  node* prev = new node;
  curr = head;
  for(int i=0;i<pos;i++)
  {
    prev = curr;
    curr = curr -> next;
  }
  prev -> next = curr -> next;
  delete curr;
}

void reverse_iter()              //Reversing a linked list using iteration
{
  node *curr = new node;
  node *prev = new node;
  node *forward = new node;

  curr = head;
  prev = NULL;

  while(curr!=NULL)
  {
    forward = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = forward;
  }
  head = prev;
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
