#include<iostream>

template<typename X> struct Node{
  X data;
  Node<X>* next;
  Node(X data, Node<X>* next) : data(data), next(next){}
};

template<typename X>
class LinkedList{

  public:
    Node<X>* head;
    int size;
    void insert(X);
    void insertAtEnd(x);
    bool insert(X, int index);
    bool remove(X);
    size_t find(X);
    void print();
    int length();

    LinkedList() : head(), size(0){}
    LinkedList(X data){
      size = 0;
      insert(data);
    }
    LinkedList(Node<X> new_head){
      head = new_head;
      size = 1;
    }


};

template<typename X>
void LinkedList<X>::insert(X data){
  if(head == nullptr){
    head = new Node<X>(data,nullptr);
  }
  else{
    // O(1), adding to the front of a linked list
    head = new Node<X>(data,head);
    }
  size++;
}
template<typename X>
void LinkedList<X>::insertAtEnd(X data){
  if(head == nullptr){
    head = new Node<X>(data,nullptr);
  }
  else{
    Node<X> current = head;
    while(current!= nullptr){
      current = current->next;
    }
    current->next = new Node<X>(data,nullptr);
  }
}


template<typename X>
bool LinkedList<X>::insert(X data, int index){
  if(index > size+1 || index < 0){
    return false;
  }
  Node<X>* current = head;
  for(int i = 0; i < index - 1; i++)
  {
    current = current->next;
  }
  current->next = new Node<X>(data,current->next);
  return true;
}

template<typename X>
bool LinkedList<X>::remove(X data){
  if(head == nullptr){
    return false;
  }
  // check if the head node has the data
  if(head->next == nullptr){
    if(head->data == data){
      head = nullptr;
      size--;
      return true;
    }
    else{
      return false;
    }
  }
  Node<X> current = head; // head
  Node<X> prev = nullptr; // starts at nullptr
  while(current->next != nullptr && current->data != data){
    prev = current; // stops at one before
    current = current->next;
  }
  // jump to the next (but checks)
  if(prev->next->next == nullptr){
    free(current);
    current = nullptr;
  }
  else{
      prev->next->next = prev->next;
      free(current);
      current = nullptr;
  }
  return true;
}


template<typename X>
size_t LinkedList<X>::find(X data){
  int i = 0;
  Node<X> current = head;
  while(current->next != nullptr && current->data!= data){
    current = current->next;
    i++;
  }
  if(current!= nullptr){
    return i;
  }
  return -1;
}

template<typename X>
void LinkedList<X>::print(){
  Node<X> current = head;
  while(current != nullptr){
    cout<<current->data<<std::endl;
    current = current->next;
  }
}

template<typename X>
int LinkedList<X>::length(){
  return size;
}

int main(){





}
