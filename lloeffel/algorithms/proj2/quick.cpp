// quick.cpp
// Written by Jackson Stern
// Last Modified: 9/18/2024
// This set of functions implements a custom quick sort on a singly linked list

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

//Wrapper function
void quick_sort(List &l, bool numeric) {
	l.head = qsort(l.head, numeric);
}

//Recursive quicksort
Node *qsort(Node *head, bool numeric) 
{
	//Base case, empty or single element list
	if(head == nullptr || head->next == nullptr)
		return head;

	Node* pivot = head;
	Node* left = nullptr;
	Node* right = nullptr;

	partition(head->next, pivot, left, right, numeric);

	//removing pivot links to stop circular logic
	pivot->next = nullptr;
	
	//left and right side recursions
	left = qsort(left, numeric);
	right = qsort(right, numeric);

	//Connecting left side of list to pivot, and then pivot to
	//right side of list, returning head of newly concatenated list
	Node* newHead = concatenate(left, pivot);
	return  concatenate(newHead, right);
}

//Splits list into a left and right side around pivot
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) 
{
	Node* leftSide = nullptr;
	Node* rightSide = nullptr;
	
	//While runs until end of list
	while(head != nullptr)
	{
		//Storing nextNode and then detaching current head node
		//from list to avoid any circular logic
		Node* nextNode = head->next;
		head->next = nullptr;
	
		if(numeric)
		{
			//if true add to left side
			if(node_number_compare(head,pivot))
			{
				//Setting left as the head of the left list and adding the node
				//to the left side
				if(left == nullptr)
				{
					left = head;
					leftSide = head;
					leftSide->next = nullptr;
				}
				//Adding nodes to left side of list, making sure
				//that the list end points to nullptr
				else
				{
					leftSide->next = head;
					leftSide = head;
					leftSide->next = nullptr;
				}
			}
			//else add to right side, same logic as left
			else
			{
				if(right == nullptr)
				{
					right = head;
					rightSide = head;
					rightSide->next = nullptr;
				}
				else
				{
					rightSide->next = head;
					rightSide = head;
					rightSide->next = nullptr;
				}
			}
		}
		//Same logic as numeric just using string compare
		else
		{
			if(node_string_compare(head, pivot))
			{
				if(left == nullptr)
				{
					left = head;
					leftSide = head;
					leftSide->next = nullptr;
				}
				else
				{
					leftSide->next = head;
					leftSide = head;
					leftSide->next = nullptr;
				}
			}	
			else
			{
				if(right == nullptr)
				{
					right = head;
					rightSide = head;
					rightSide->next = nullptr;
				}
				else
				{
					rightSide->next = head;
					rightSide = head;
					rightSide->next = nullptr;
				}
			}
		}
		//Moving to next node
		head = nextNode;
	}
}

//Combines left and right lists
Node *concatenate(Node *left, Node *right) 
{
	//Failsafe if left or right is null
	if(left == nullptr)
		return right;
	if(right == nullptr)
		return left;

	Node* head = left;
	Node* current = left;
	
	//Traverses through left side until it reaches the end
	while(current->next != nullptr)
	{
		current = current->next;
	}	
	
	//Connecting left side to right side
	current->next = right;
	
	//Returns head of newly concatenated list
	return head;
}

