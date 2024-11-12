//Name: Liam Loeffel (utkID: lloeffel)
//Program Name: Linked List Header
//Description: is the header file for the LinkedList class


//Source: CS202 Notes:
//url: https://web.eecs.utk.edu/~semrich/cs202-24/notes/7/LinkedList.h

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>   // for using cout

using namespace std;

//Source: stack overflow
//url: https://stackoverflow.com/questions/924664/why-is-null-undeclared
#include <stddef.h>

template<typename T> class LinkedList; // forward declaration of List

template<typename T>   // templated node type
struct Node {

  friend class LinkedList<T>;    // make the main class a friend

  public:
    Node(const T &);     // constructor
    T getData() const;   // get function

  private:
    T data;           // data for linked list node
    Node<T> *next;    // pointer to next object
};
// constructor, using member initialization list syntax
template<typename T>
Node<T>::Node(const T &info) :data(info),next(NULL) {}
// simple get function for our class (if friendship is not used)
template<typename T>
T Node<T>::getData(void) const { return data; }


template<typename T>    // templated class
class LinkedList {
	public:
		LinkedList();    // constructor
		~LinkedList();   // deconstructor
		void appendNode(const T &);   // add a node to end of list
		bool empty();                 // if the list is empty
		int nodeCount();              // how many nodes are in the list
		int getValue(int);               // get a value at a particular index
	private:
		Node<T> *first;                // first element in the list
		Node<T> * newNode(const T &);   // helper function; creates a new node
};

#endif
