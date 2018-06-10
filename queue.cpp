#include <iostream>
#include <cstdlib>
using namespace std;

// queue size of 1000 elements (by default)
#define queue_size 1000;

class queue{
  int array*; // pointer to (array-based implementation of queue)
  int front; // front of queue
  int rear; // back of queue
  int maxCapacity; // max amount
  int currentSize; // current queue_size

public:
  queue(){
    int size = queue_size;
  }
  // add element
  void enqueue(int x);
  // remove element
  void dequeue();
  // length
  int length();
  // top element (front)
  int peek();
  // check if the queue is full
  bool isFull();
  // check if the queue is empty
  bool isEmpty();

};

// constructor
queue::queue(int size){
  // finish array
  array = new int[size];
  // max capacity of the queue
  maxCapacity = size;
  // current Size is still 0
  currentSize = 0;
  rear = -1;
  front = 0;
}

int queue::length(){
  return currentSize;
}
// check queue if it is full
bool queue::isFull(){
  return(length() == maxCapacity);
}
// check queue if it's empty or not
bool queue::isEmpty(){
  return (length() == 0);
}
// check element at front of queue
int queue::peek(){

  // check for underflow
  if(isEmpty()){
    cout<< "underflow detected"<< endl;
  }
  return array[front];
}
// insert element to queue
void queue::enqueue(int x){
  // check for overflow
  if(isFull()){
    cout<<"overflow detected"<<endl;
  }
  // adjust the back of the queue
  rear = (rear+1)%capacity;
  arr[rear] = x;
  // increase size
  currentSize+=1;
}
void queue::dequeue(int x){
  if(isEmpty()){
    cout<<"underflow detected"<<endl;
  }
  // adjust the front
  front = (front+1)%capacity;
  // decrease Size
  currentSize-=1;
}

int main(){



}
