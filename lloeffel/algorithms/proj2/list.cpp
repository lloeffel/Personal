//used some of my old code from lab4 of 202 to remember stuff
#include "volsort.h"
#include <string>
#include <string.h>

List::List() {
    head = NULL; //this has to be null to avoid memory leaks
    size = 0;
}

List::~List() {
    //delete everything
    Node *ptr = head;

    while(ptr != NULL) {
        Node *next = ptr->next;
        delete ptr;
        ptr = next;
    }
}

bool node_number_compare(const Node *a, const Node *b) {
    return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b) {
   return (a->string.compare(b->string) < 0);
}
