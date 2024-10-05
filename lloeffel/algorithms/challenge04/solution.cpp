// Challenge 04 : Graph Paths
// Name: Liam Loeffel
// Description: This program constructs graphs from input and finds if there is a path to the test inputs

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//this recursive algorithm was developed with the guidance of ChatGPT
//it returns true when the destination is found
bool DFS(map<char,vector<char>>& graph, char current, char destination, set<char>& visited){
  if(current == destination){
    return true;
  }
  visited.insert(current);// keeps track of where we have already been

  for(char neighbor : graph[current]){ // traversing each possible path
    if (visited.find(neighbor) == visited.end()){ //if the value has not been visited before do go down the path
      if(DFS(graph, neighbor, destination, visited)){
        return true;
      }
    }
  }
  return false;
}

// Main Execution
int main(int argc, char *argv[]) {
  //input vars
  int nEdges = 0;
  int nPaths = 0;
  char src = 0;
  char dest = 0;

  int count = 1;

  while(cin >> nEdges){ //filling the graphs in
    if(count != 1){
      cout << endl;
    }
    map<char, vector<char>> graph = {};
    for(int i = 0; i < nEdges; i++){ //filling graph
      cin >> src >> dest;
      if(graph.find(src) == graph.end()){ //src is not in graph
        graph[src].push_back(dest);
      }else{
        graph[src].push_back(dest);
      }
    }
    //printing graph
    cin >> nPaths;
    for(int i = 0; i < nPaths; i++){   
      cin >> src >> dest;
      cout << "In Graph " << count << " there is ";
      if(graph.find(src) == graph.end()){ //if the src does not exist
        cout << "no path from " << src << " to " << dest << endl;
      }else{
        set<char> visited;
        if (DFS(graph, src, dest, visited)){
          cout << "a path from " << src << " to " << dest << endl;
        }else{
          cout << "no path from " << src << " to " << dest << endl;
        }
      }
    }
    cout.flush(); //supposed to deal with memory leaks having to do with cin/cout from valgrind but i honestly dont even know what it does
    count++;
  }

  return (0);
}
