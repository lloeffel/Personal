// Title: merge.cpp
// Names: Liam Loeffel, David Floyd, Jackson Stern, Chase Wolverton
// Description: These are all the functions needed to implement the merge sort algorithm on a linked list of strings or integers.
#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

//this is the main function that will be called to sort the list
void merge_sort(List &l, bool numeric) {
    l.head = msort(l.head, numeric);
}

//this is a recursive function that splits the lists until they are just one Node
Node *msort(Node *head, bool numeric) {
    //if the split is down to 2 or less values then return the head
    if((head == nullptr) || (head->next == nullptr)){return head;}
    //defining the left and right splits
    Node* left = nullptr;
    Node* right = nullptr;

    split(head, left, right);
    
    left = msort(left, numeric);
    right = msort(right, numeric);

    //putting it all back together
    return merge(left, right, numeric);
}

//this is the split function. It uses fast and slow Nodes to split the list
void split(Node *head, Node *&left, Node *&right) {
    //if the head points to null or is only pointing to a 1 element list, 
    //then split whatever the head points to into the left Node
    if (head == nullptr || head->next == nullptr) {
        left = head;
        right = nullptr;
        return;
    }   
    //This is the fast slow implementation of splitting a linked list
    //the fast Node iterates every other value so when it reaches the end
    //the slow Node is only at the middle, effectively splitting the list
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr; //temp Node
    
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    prev->next = nullptr;
    left = head;  //starting the left list at the head
    right = slow; //starting the right list ptr at the end of the slow list
}

//this function puts the split nodes back together in order
Node *merge(Node *left, Node *right, bool numeric) {
    //dummy node is used to keep track of the head as the tail is updated
    Node dummy;
    Node* tail = &dummy;

    while (left != nullptr && right != nullptr) {
        bool left_is_smaller;
        
        //changes the implementation based on if the list is using strings or numbers
        if (numeric) {
            left_is_smaller = node_number_compare(left, right);
        } else {
            left_is_smaller = node_string_compare(left, right);
        }
        
        //decides whether to take a value from the right or left list based on which is smaller
        if (left_is_smaller) {
            tail->next = left;
            left = left->next; //goes to the next value
        } else {
            tail->next = right; 
            right = right->next; //goes to the next value
        }
        tail = tail->next; //updating the tail
    }
    //appending the last value of either of the lists since the while loop doesnt catch it.
    if (left != nullptr) {
        tail->next = left;
    }
    if (right != nullptr) {
        tail->next = right;
    }
    
    //returning the head of the new list which dummy stands for
    return dummy.next;
}
