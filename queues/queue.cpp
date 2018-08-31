#include <iostream>
#include <cstdlib>
using namespace std;

#define queue_size 1000;

class queue{
  int array*; 
  int front; 
  int rear; 
  int maxCapacity; 
  int currentSize; 

public:
  queue(){
    int size = queue_size;
  }
  void enqueue(int x);
  void dequeue();
  int length();
  int peek();
  bool isFull();
  bool isEmpty();
};

queue::queue(int size){
  array = new int[size];
  maxCapacity = size;
  currentSize = 0;
  rear = -1;
  front = 0;
}

int queue::length(){
  return currentSize;
}

bool queue::isFull(){
  return(length() == maxCapacity);
}

bool queue::isEmpty(){
  return (length() == 0);
}

int queue::peek(){
  if(isEmpty()){
    cout<< "underflow detected"<< endl;
  }
  return array[front];
}

void queue::enqueue(int x){

  if(isFull()){
    cout<<"overflow detected"<<endl;
  }

  rear = (rear+1)%capacity;
  arr[rear] = x;
  currentSize+=1;
}
void queue::dequeue(int x){
  if(isEmpty()){
    cout<<"underflow detected"<<endl;
  }
  front = (front+1)%capacity;
  currentSize-=1;
}

int main(){



}
