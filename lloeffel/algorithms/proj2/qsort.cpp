// qsort.cpp
#include "volsort.h"

#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

/* From zacks lab lecture, 
bool comp(const void *lhs, const void *rhs) {
    Node* L = (*(Node**)lhs);
    Node* R = (*(Node**)rhs);

    return L->string == R->string;
}
*/

//translates the function to one compatible with the rest of the code
int num_comp(const void *a, const void *b) {
    Node* L = (*(Node**)a);
    Node* R = (*(Node**)b);

    if(node_number_compare(L,R)) { //I could just do the comparison but this felt easier at the time, it's probably not
        return -1;
    } else {
        return 1;
    }
}

//returns an int to compare strings lexiographicaly
int str_comp(const void *a, const void *b) {
    Node* L = (*(Node**)a);
    Node* R = (*(Node**)b);
    
    if(node_string_compare(L,R)) {
        return -1;
    } else {
        return 1;
    }
}

void qsort_sort(List &l, bool numeric) {

    if(l.size < 2) {return;} // a vec of size 1 or 0 is sorted

    vector<Node*> vec; //make a vector to store the node pointers in

    for(Node* it = l.head; it->next != NULL; it = it->next){
        vec.push_back(it); //add them all to the vector
    }
    vec.push_back(vec.back()->next); //add the last one to the vector

    //sort
    if(numeric) {
        //qsort(void *base, size_t nmemb, size_t size, __compar_fn_t compar)
        qsort(vec.data(), vec.size(), sizeof(Node*), num_comp);
    }
    else {
        qsort(vec.data(),vec.size(),sizeof(Node*), str_comp);
    }

    //rebuild from the ashes
    l.head = vec[0];
    for(size_t i=0; i<vec.size()-1; ++i) {
        vec[i]->next = vec[i + 1]; //link all the nodes back
    }
    vec.back()->next = NULL;

}
