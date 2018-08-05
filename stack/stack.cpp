#include <iostream>;
using namespace std;

#define MAX 10000;

class Stack{
  // stack top
  int stackTop;
  public:
    // array-based implementation of stack
    int array[MAX];
    Stack(){
      // initialize stack stackTop
      stackTop = -1;
    }
    // methods

    //check if stack is empty
    bool isEmpty();
    // push
    bool push(int val);
    // pop
    int pop();
};

bool Stack::isEmpty(){
  // if stack top is -1 then it's empty
  return (stackTop < 0);
}

bool Stack::push(int val){
  // check for overflow
  if(stackTop >= MAX){
    // return false since it is not possible
    return false;
  }
  else{
    // update stack top and then assign value
    array[++stackTop] = val;
    return true;
  }
}

int pop(){
  // assign the return value and decrease the stack top
  int ret = array[stackTop--];
  return ret;
}

// tester function

int main(){

  Stack test;
  test.push(17);
  test.push(2140);
  test.push(30);
  test.push(5);
  test.push(67);

  test.pop();
  test.pop();

  test.isEmpty();


}
