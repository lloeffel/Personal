//Name: Liam Loeffel (utkID: lloeffel)
//Program Name: List Code
//Description: This Program defines all the functions in the header file.


// THIS WAS HEAVILY INSPIRED BY THE NOTES FROM CLASS

#include "list.h"
#include <vector>


//Source: CS202 Notes:
//url: https://web.eecs.utk.edu/~semrich/cs202-24/notes/7/LinkedList.h
//constructor
template<typename T>
LinkedList<T>::LinkedList() : first(NULL) {}

//Source: CS202 Notes:
//url: https://web.eecs.utk.edu/~semrich/cs202-24/notes/7/LinkedList.h
//deconstructor
template<typename T>
LinkedList<T>::~LinkedList() {
	if (!empty()) { // follow the links, clobbering as we go
		Node<T> *p= first;

		while (p != NULL) {
			Node<T> *next = p->next;
			delete p;
			p = next;
		};
	}
}

//Source: CS202 Notes:
//url: https://web.eecs.utk.edu/~semrich/cs202-24/notes/7/LinkedList.h
template<typename T>
void LinkedList<T>::appendNode(const T &data) {
	Node<T> *nn  = newNode(data);
	if (empty()) {
		first = nn;
	}
	else {
		Node<T> *p = first;
		while (p->next != NULL) p = p->next;
		p->next = nn;
	}
	nn->next = NULL;
}


//Source: CS202 Notes:
//url: https://web.eecs.utk.edu/~semrich/cs202-24/notes/7/LinkedList.h
template<typename T>
bool LinkedList<T>::empty() { return (first == NULL); }


//Source: CS202 Notes:
//url: https://web.eecs.utk.edu/~semrich/cs202-24/notes/7/LinkedList.h
template<typename T>
Node<T> *LinkedList<T>::newNode(const T &value) {
	return new Node<T>(value);
}


//Source: CS202 Notes:
//url: https://web.eecs.utk.edu/~semrich/cs202-24/notes/7/LinkedList.h
template<typename T>
int LinkedList<T>::nodeCount(void) {
	int n=0;
	for(Node<T> *p = first; p != NULL; p = p->next) n++;
	return n;
}

template<typename T>
//gets the value at an index
int LinkedList<T>::getValue(int n){
	vector<int> TempVals;  //stores the linked list as a vector
	if(empty()){           //error check
		return -1;
	}else{            
		Node<T> *p = first;          //sets the first value of the pointer
		TempVals.push_back(p->data); //adds the reference to the vector
		while (p->next != NULL){     //adds the rest
			p = p->next;
			TempVals.push_back(p->data);
		}
	}
	return TempVals[n];
}
//Source: Chat GPT
template class LinkedList<int>;
