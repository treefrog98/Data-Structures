#include <iostream>;
using namespace std;

#define MAX 10000;

class Stack{
  int stackTop;
  public:
    int array[MAX];
    Stack(){
      stackTop = -1;
    }
    bool isEmpty();
    bool push(int val);
    int pop();
};

bool Stack::isEmpty(){
  return (stackTop < 0);
}

bool Stack::push(int val){
  if(stackTop >= MAX){
    return false;
  }
  else{
    array[++stackTop] = val;
    return true;
  }
}

int pop(){
  int ret = array[stackTop--];
  return ret;
}
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
