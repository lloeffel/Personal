/*
Name: Liam Loeffel
Description: This is the rest of the implementation for a Binary Search Tree Data Structure.
             The functions implemented in this code are:
          x   Depth() - Distance from a node to the root.  Returns -1 if the key is not in the tree.
          x   Height() - Returns the depth of the node with maximum depth, plus one.
          x   Ordered_Keys() - Return a vector of sorted keys
          x   Copy Constructer - Creates a Copy of an existing tree
          x   Assignment Operator - Makes a tree equal to another
          x   recursive_find_height() - recursively finds the greatest height.
          x   make_key_vector() - A helper for Ordered_Keys() that returns an odered list of keys
          x   make_balanced_tree() - A helper for the copy constructor and assignment overload.
*/

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include "bstree.hpp"
using namespace std;
using CS140::BSTree;
using CS140::BSTNode;

/* ---------------------------------------------- */
/* You'll write all of these as part of your lab. */

//this function finds distance from a node to the root.  Returns -1 if the key is not in the tree.
int BSTree::Depth(const string &key) const
{
  //this is the node we will traverse the tree with
  BSTNode *n = sentinel->right;
  int depth = 0; //return value
  // this is where we match the node with the key given and increment the depth the deeper we get
  while (n != sentinel) {      //exits the loop if the key is not found
    if (n->key == key) {       //return case
      return depth;
    } else if (n->key > key) { //is it left
      n = n->left;
      depth++;
    } else {                   //is it right
      n = n->right;
      depth++;
    }
  
  }
  return -1; //not found case
}

//this function returns the depth of the node with maximum depth, plus one.
int BSTree::Height() const
{
  return recursive_find_height(sentinel->right); //using helper
}

//this function returns a vector of sorted keys
vector <string> BSTree::Ordered_Keys() const
{
  vector <string> rv;
  make_key_vector(sentinel->right, rv); //uses helper
  return rv;
}

//Creates a Copy of an existing tree
BSTree::BSTree(const BSTree &t)        
{
  //defining the sentinel
  sentinel = new BSTNode;
  sentinel->left = NULL;
  sentinel->right = sentinel;
  sentinel->parent = NULL;
  sentinel->key = "---SENTINEL---";
  sentinel->val = NULL;
  size = 0;
  //copy
  *this = t;

}

//Makes a tree equal to another
BSTree& BSTree::operator= (const BSTree &t) 
{
    //is it the same?
    if(this == &t){return *this;}
    
    //assigning the functions to variables so they only have to be run once
    vector<std::string> keys = t.Ordered_Keys();
    vector<void *> vals = t.Ordered_Vals();
    size = t.Size();

    //copying a balanced version of t to this
    sentinel->right = this->make_balanced_tree(keys, vals, 0, size);

    return *this;
}

//this function recursively finds the greatest height.
int BSTree::recursive_find_height(const BSTNode *n) const
{
  int maxLeft, maxRight; //stores the heights of each tree
  if(n == sentinel){return 0;} //is it at the end of the branch
  maxLeft = recursive_find_height(n->left);
  maxRight = recursive_find_height(n->right);
  return max(maxLeft,maxRight) + 1; //returns the greater heights as the recursion goes on
}

//this function is a helper for Ordered_Keys() that returns an odered list of keys
void BSTree::make_key_vector(const BSTNode *n, vector<string> &v) const
{
  //tree must be balanced for this to work
  //this adds the variables to the vector in the order that they are in the tree
  if (n == sentinel) return;
  make_key_vector(n->left, v);
  v.push_back(n->key);
  make_key_vector(n->right, v);
}

//A helper for the copy constructor and assignment overload.
BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys, 
                                    const vector<void *> &vals,
                                    size_t first_index,
                                    size_t num_indices) const
{
  //if we have come to the end of the iterations of the vector
  if(num_indices == 0){return sentinel;}

  //calculating the middle
  size_t middle = first_index + num_indices / 2; 
  
  //making the new node
  BSTNode *tempNode = new BSTNode;
  tempNode->parent = sentinel;
  tempNode->key = sorted_keys[middle];
  tempNode->val = vals[middle];
  tempNode->left = make_balanced_tree(sorted_keys, vals, first_index, num_indices/2);
  tempNode->right = make_balanced_tree(sorted_keys, vals, middle + 1, first_index + num_indices - (middle + 1));
  
  //assigning correct parents to each node
  if (tempNode->left != sentinel){tempNode->left->parent = tempNode;}
  if (tempNode->right != sentinel){tempNode->right->parent = tempNode;}

  return tempNode;
}
