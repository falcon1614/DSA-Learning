#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
  int *arr;
  int size;
  int capacity;

  public:
    /*----------------------------Constructor------------------------------*/
    MaxHeap(int n){
      arr = new int[n];
      size = 0;
      capacity = n;
    }

    /*----------------------------Insertion-------------------------------*/
    void Insert(int val){

      // Over Flow Condition
      if(size==capacity){
        cout<<"Heap OverFlow \n";
        return;
      }

      //
      arr[size] = val;
      int index = size;
      size++;

      int parent = index-1/2;
      while(index>0 && arr[index]>arr[parent]){
        // Swap with parent
        swap(arr[index],arr[parent]);
        index = (index-1)/2;
      }
    }

    /*-----------------------------Deletion--------------------------------------*/
    void Delete(){

      // UnderFlow Condition
      if(size==0){
        cout<<"Heap UnderFlow \n";
        return;
      }

      // Start Element Replace With End element
      cout<<arr[0]<<": Delete From The Array \n";
      arr[0] = arr[size-1];
      size--; // Last Element Remove

      if(size==0){
        return;
      }

      Heapify(0); // after Delete Heap Condition Full Fill
    }

    /*-------------------------------Heapify--------------------------------------*/
    void Heapify(int index){

      int largest = index;
      int left = (2*index)+1;
      int right = (2*index)+2;

      if(left<size && arr[left] < arr[right]){
        largest = left;
      }

      if(right<size && arr[right] < arr[left]){
        largest = right;
      }

      if(largest!=index){
        swap(arr[index],arr[largest]);
        Heapify(largest);
      }
    }

    /*-----------------------------------Print-------------------------------------*/
    void PrintHeap() {
      cout << "Current Heap: ";
      for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
      }
      cout << "\n";
    }
};

// Main function
int main() {
  MaxHeap heap(10);

  heap.Insert(30);
  heap.Insert(40);
  heap.Insert(10);
  heap.Insert(50);
  heap.Insert(20);

  heap.PrintHeap(); // Expected: 50 40 10 30 20

  heap.Delete();    // Delete root (50)
  heap.PrintHeap(); // Expected: 40 30 10 20

  heap.Delete();    // Delete root (40)
  heap.PrintHeap(); // Expected: 30 20 10

  return 0;
}

