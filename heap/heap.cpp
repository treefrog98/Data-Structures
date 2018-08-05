#include <iostream>
#include <vector>;

template <typename T>
class Heap {

public:
  Heap();
  T peek();
  T remove();
  void insert(T data);
  size_t size();
  void print();

private:
  vector<T>_elems;
  size_t left_child_index(size_t index);
  size_t right_child_index(isize_t index);
  size_t parent_index(size_t index);
  bool has_child(size_t val);
  void heapify_up(size_t val);
  void heapify_down(size_t val);

}

template <typename T>
Heap<T>::Heap() {
  // default value for 0th element
  min_heap.push_back(T());
}
template <typename T>
void Heap<T>::Heap() {
  // test if it's empty
  if (size() == 0){
        return;
    } else {
        for (int i = 1; i < _elems.size() - 1; i++) {
            std::cout << _elems[i] << " | ";
        }
        std::cout << _elems[size()] << std::endl;
    }
}

template <typename T>
T Heap<T>::peek() {
  if(size() > 0){
    // return the 1st element of the heap
    return min_heap[1];
  }
}

template <typename T>
void Heap<T>::insert(T data) {
  min_heap.push_back(T);
  heapify_up(min_heap[size()-1]);
}

template <typename T>
T Heap<T>::remove() {
  // save root index
  T temp = min_heap[root_index()];
  min_heap[root_index()] = min_heap[size()];
  min_heap[size()] = temp;
  min_heap.pop();
  heapify_down(1);

}

template <typename T>
int Heap<T>::size() {
  return min_heap.size()-1;
}

template <typename T>
size_t index Heap<T>::left_child_index(size_t index) {
  if(index * 2 <= size())
    return index * 2;
  }
  else {
    return -1;
  }

}
template <typename T>
size_t index Heap<T>::right_child_index(size_t index) {
  if(index * 2 + 1 <= size()) {
    return index * 2 + 1;
  }
  else {
    return -1;
  }
}
template <typename T>
size_t index Heap<T>::parent_index(size_t index) {
  if(index != 1) {
    return index / 2;
  }
}

template <typename T>
size_t Heap<T>::root_index() {
  return 1;
}


template <typename T>
bool Heap<T>::has_child(size_t index) {
  return index * 2 <= size();
}
template <typename T>
void Heap<T>::heapify_up(size_t index) {
  while(parent_index(index) != -1 && min_heap[parent_index(index)] < min_heap[index]){
    // swap
    T temp = min_heap[parent_index(index)];
    min_heap[parent_index(index)] = min_heap[index];
    min_heap[index] = temp;
    index = parent_index(index);
  }

}
template <typename T>
void Heap<T>::heapify_down(size_t index) {


  // heapify down
  while(has_child(index)) {
    if(right_child_index(index) != -1) {
      // compare the index value with both children
      T left_val = min_heap[left_child_index(index)];
      T right_val = min_heap[right_child_index(index)];
      if(left_val < right_val) {
        if(left_val < min_heap[index]) {
          // swap the index with the left child index
          min_heap[index] = left_val;
          min_heap[left_child_index] = min_heap[index];
        }
        else {
          break;
        }
      }
      else {
        if(right_val < min_heap[index]) {
          // swap right child with index
          min_heap[index] = right_val;
          min_heap[right_child_index(index)] = min_heap[index];
          index = right_child_index(index);
        }
        else{
          break;
        }
      }
    } else {
        if(left_val < min_heap[index]) {
          // swap left child with indices
          min_heap[index] = left_val;
          min_heap[left_child_index(index)] = min_heap[index];
        }
        break;

    }

  }




}

int main() {





}
