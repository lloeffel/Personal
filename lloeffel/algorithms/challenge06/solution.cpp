// Name: Liam Loeffel (lloeffel)
// Challenge 6: Minimum Spanning Tree
// Description: This program implements Primms Algorithm on a MST in an undirected weighted graph.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

//struct to store the values in an Edge
struct Edge{
  char beginning;
  char end;
  int weight;
};


int main(int argc, char *argv[]) {
  int SIZE = 0;
  //0 if not visited. 1 if visited.
  vector<int> visited = {};
  vector<Edge> mst = {};
  vector<Edge> edges = {};
  char row = 'A';
  vector<string> paths = {};
  int mstWeight = 0;
  
  //main loop
  while(cin >> SIZE){
    cin.ignore();
    if (visited.size() > 0){
      cout << endl << endl;
    }
    //resetting vars for future iterations
    mst.clear();
    visited.clear();
    visited.resize(SIZE);
    edges.clear();
    paths.clear();
    row = 'A';
    mstWeight = 0;

    //scan the input
    paths.resize(SIZE);
    for(int i = 0; i < SIZE; i++){
      getline(cin, paths[i]);
    }


    int column = 0;
    visited[row - 65] = 1; //mark the first node as visited
    //interate thru the graph
    int numVisited = 1; //counts number of visited nodes
    while(numVisited != SIZE){
      stringstream s(paths[row-65]);
      string weight = "";
      column = 65;
      
      //look at edges connected to the node we are looking at
      while(s >> weight){
        //if there is no edge then skip this iteration
        if(stoi(weight) == -1){
          column++;
          continue;
        }
        Edge temp;
        temp.beginning = row;
        temp.end = column;
        temp.weight = stoi(weight);
        edges.push_back(temp);
        column++;
      }
      //looking for smallest edge that doesnt connect to something that is already visited
      int smallestWeight = INT8_MAX;
      int smallIndex;
      
      for(size_t i = 0; i < edges.size(); i++){
        //does this node connect to something that we have visited already
        if (visited[edges[i].end - 65] == 1){
          continue;
        }

        //finding the smallest weight in the edges 
        if(edges[i].weight < smallestWeight){
          smallestWeight = edges[i].weight;
          smallIndex = i;
        }
      }
      //adding the edge to the MST
      mst.push_back(edges[smallIndex]);
      mstWeight += smallestWeight;
      row = edges[smallIndex].end;
      visited[row - 65] = 1;
      numVisited++;
    }

    //Formatting the edge data
    vector<string> mstFormatted = {};
    char temp = 0;
    for(size_t i = 0; i < mst.size(); i++){
      if (mst[i].beginning > mst[i].end){
        temp = mst[i].beginning;
        mst[i].beginning = mst[i].end;
        mst[i].end = temp;
      }
      string edge = "  ";
      edge[0] = mst[i].beginning;
      edge[1] = mst[i].end;
      mstFormatted.push_back(edge);
    }
    sort(mstFormatted.begin(),mstFormatted.end());

    //print the mst
    cout << mstWeight << endl;
    for(size_t i = 0; i < mst.size() - 1; i++){
      cout << mstFormatted[i] << endl;
    }
    cout << mstFormatted[mst.size() - 1];
  }
  cout << endl;
  return (0);
}

