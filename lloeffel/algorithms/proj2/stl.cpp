// stl.cpp
// call stl sort.
// add node pointers to an array and then call sort on the array.
// go through the array and fix up the links so the original array is right
// reset the head pointer

#include "volsort.h"

#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void stl_sort(List &l, bool numeric) {

    if(l.size < 2) {return;} // a vec of size 1 or 0 is sorted

    vector<Node*> vec; //make a vector to store the node pointers in

    for(Node* it = l.head; it->next != NULL; it = it->next){
        vec.push_back(it); //add them all to the vector
    }
    vec.push_back(vec.back()->next); //add them all to the vector

    //sort 
    if(numeric) {
        sort(vec.begin(),vec.end(),node_number_compare);
    }
    else {
        sort(vec.begin(),vec.end(),node_string_compare);
    }
    
    //rebuild from the ashes

    l.head = vec[0];
    for(size_t i=0; i<vec.size()-1; ++i) {
        vec[i]->next = vec[i + 1]; //link all the nodes back
    }
    vec.back()->next = NULL;
}

