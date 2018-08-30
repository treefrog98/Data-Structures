#include <cstdio>
#include <iostream>
#include <algorithms>
#include <cstdlib>
using namespace std;

struct node{
  int data;
  struct node* prev;
  struct node* next;
}*head;

class doublyLL{

  public:
    void create(int val); //
    int count(); //
    void reverse(); //
    void deleteElement(int val); //
    bool searchElement(int val); //
    void printList(); //
    void insertAtBegin(int value); //
    void insertAtMiddle(int value, int position);

    doublyLL{
      head = NULL;
    }

}
// create the list
void doublyLL::create(int val){
  // use a temp node, initialize values
  struct node* temp = new(struct node);
  // set initial values
  temp->data = val;
  temp->next = null;

  struct node* later;

  // base
  if(head == NULL){
    temp->prev = NULL;
    // set
    head = temp;
  }
  else{
    later = head;
    while(later->next != NULL){
      later = later->next;
    }
    later->next = temp;
    temp->prev = later;
  }

  struct node* list;

}
void doublyLL::printList(){
  if(head == NULL){
    return;
  }
  struct node* iterate = head;
  while(iterate != NULL){
    cout<<iterate->data<<endl;
    iterate = iterate->next;
  }
}

int doublyLL::count(){
  if(head == NULL){
    return 0;
  }
  int count = 0;
  struct node* iterate = head;
  while(iterate != NULL){
    count+=1;
    iterate = iterate->next;
  }
  return count;
}

void doublyLL::reverse(){
  struct node* traverse1 = head;
  traverse1->next = NULL;
  struct node* traverse2 = traverse1->next;
  traverse1->prev = traverse2;
  while(traverse2 != NULL){
     traverse2->prev = traverse2->next;
     traverse2->next = traverse1;
     traverse1 = traverse2;
     traverse2 = traverse2->prev;
  }
  head = traverse1;
}

void doublyLL::deleteElement(int val){
  struct node* temp;
  struct node* temp2;
  if(head->data == val){
    temp = start;
    start = start->next;
    start->prev = null;
    free(temp);
    return;
  }

  temp2 = head;
  while(temp2->next->next != NULL){
    if(temp2->next->data == val){
      temp = temp2->next;
      temp2->next->prev = temp;
      free(temp);
      return;
    }
    temp2= temp2->next;
  }
  if(temp2->next->data == val){
    temp = temp2->next;
    free(temp);
    temp2->next = NULL;
    return;
  }
}

void doublyLL::insertAtBegin(int val){
  if(head == null){
    return;
  }
  struct node* temp = new(struct node);
  temp->prev = NULL;
  temp->next = head;
  temp->data = value;
  head -> prev = temp;
  head = temp;
}
bool doublyLL::searchElement(int val){
  struct node* iterate = head;
  if(head->data == val){
    return true;
  }
  if(head == null){
    return false;
  }
  while(iterate != null){
    if(iterate->data == val){
      return true;
    }
    iterate = iterate->next;
  }
  return false;
}

void doublyLL::insertAtMiddle(int val, int position){
  if(head == null){
    return;
  }
  struct node* temp = new (struct node);
  struct node* current = head;
  for(int i = 0; i < position-1; i++){
    current = current->next;
    // null check
    if(current == null){
      return;
    }
  }
  temp-> data = val;
  if(current->next == NULL){
    current->next = temp;
    // set to NULL
    temp->next = NULL;
    temp->prev = current;
  }
  else{
    temp->next = current->next;
    current->next = temp;
    temp->prev = current;
  }

}
