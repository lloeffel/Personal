// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <string>
#include <iostream>

struct Node {
    std::string string;
    int         number;
    Node       *next;
};

struct List {
    Node       *head;
    size_t      size;

    List(); 					// define in list.cpp
    ~List();					// define in list.cpp

    void push_front(const std::string &s) {	//define below
	Node *n = new Node; //create a new node
	int num = 0; //default value
	num = std::stoi(s);

	//fill values
	n->number = num;
	n->string = s;

	if(size == 0){
	    n->next = NULL;
	    head = n;
	}
	else {
	    n->next = head;
	    head = n;
	}
	size++;
    }
};


// Functions -------------------------------------------------------------------

bool node_number_compare(const Node *a, const Node *b); 	//implement in list.cpp to avoid compile-time issues, used by quick, merge and stl
bool node_string_compare(const Node *a, const Node *b);		//implement in list.cpp to avoid compile-time issues, merge and stl

//makeing this inline was the only way that I could get it to not throw an error but it might be wrong -DF
inline void dump_node(Node *n) {std::cout << n->number << " " << n->string;};	// implement in this file (volsort.h) to make it easier for TAs to grade

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation


#endif
