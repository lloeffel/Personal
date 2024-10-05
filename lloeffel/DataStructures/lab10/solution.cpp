// Lab 10: kth smallest numbers
// Name:  Liam Loeffel

// Brief description:
//     This code takes a size, k val, and a set of integers. 
//     This uses a heap tree to find the kth smallest value in the set and if the set is a max heap prior to sorting.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


//recursive function to find if the heap is a max heap
bool isMaxHeap(vector<int> array, int i, int size){
    //checks if we have reached then end of a branch
    if (i > (size - 2)/2){return true;}
    //checks if the children are less than the parent, and the children's children recusively
    if((array[i] >= array[(2*i)+1]) && (array[i] >= array[(2*i)+2]) && isMaxHeap(array,(2*i) + 1, size) && isMaxHeap(array,(2*i) + 2, size)){
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    vector<int> heap;           //stores the heap as a vector
    int input;                  //stores the input for the vector
    int size;                   //stores the size of the vector
    int k;                      //stores the kth value we are trying to find
    while(cin >> size >> k){
        //resets the vector
        heap.clear();

        //gets the vector vals
        for(int i = 0; i < size; i++){
            cin >> input;
            heap.push_back(input);
        }

        //is it a max heap?
        if(isMaxHeap(heap, 0, size)){
            cout << "Y  ";
        }else{
            make_heap(heap.begin(), heap.end());
            cout << "N  ";
        }
        
        //finding the kth value
        for(int i = 0; i < size-k; i++){        
            //puts the root on the end of the vector    
            pop_heap(heap.begin(), heap.end());
            //removes that element
            heap.pop_back();
        }
        cout << heap[0] << endl;
    }
}
