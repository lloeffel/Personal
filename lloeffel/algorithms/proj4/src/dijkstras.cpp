#include <cstdint>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

// Helper function to convert 2D coordinates to a single index
int toIndex(int row, int col, int colCount) {
    return row * colCount + col;
}

// Function to convert a single index back to row and column coordinates
string toCoords(int index, int rows, int cols) {
    int row = index / cols;  // Calculate row
    int col = index % cols;  // Calculate column
    return to_string(row) + " " + to_string(col);  // Return as "row col"
}

// Function to print all elements in the priority queue
void printPriorityQueue(priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq) {
    while (!pq.empty()) {
        cout << "(" << pq.top().first << ", " << pq.top().second << ") ";
        pq.pop();
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    // Read in from standard in -------------------------------------------------
    int nTiles;
    cin >> nTiles;

    map<char, int> tileWeights;

    char tempc;
    int tempi;
    for (int i = 0; i < nTiles; ++i) {
        cin >> tempc;
        cin >> tempi;
        tileWeights[tempc] = tempi;
    }

    int row, col;
    cin >> row >> col;

    char tempVal;
    vector<int> grid(row * col); // Flattened map stored as a 1D vector
    for (int x = 0; x < row; ++x) {
        for (int y = 0; y < col; ++y) {
            cin >> tempVal;
            grid[toIndex(x, y, col)] = tileWeights[tempVal];
        }
    }

    int startX, startY, endX, endY;
    // Adjusted to read coordinates correctly as (row, col)
    cin >> startX >> startY >> endY >> endX;

    // End read in -------------------------------------------------------------

    // Print out result (debugging) --------------
    /*
    cout << nTiles << endl;
    map<char, int>::iterator it;
    for (it = tileWeights.begin(); it != tileWeights.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    cout << row << " " << col << endl;
    for (int x = 0; x < row; ++x) {
        for (int y = 0; y < col; ++y) {
            cout << grid[toIndex(x, y, col)] << " ";
        }
        cout << endl;
    }

    cout << startX << " " << startY << endl << endX << " " << endY << endl;
    */
    // end Print out results --------------------------------------------------

    // Initialize distances to infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> frontier; // Use single index instead of (row, col) pairs
    unordered_set<int> marked; // Track marked nodes using a single index
    vector<int> distances(row * col, INT_MAX); // Flattened distances array
    vector<int> previous(row * col, -1); // Track previous nodes for path reconstruction

    // Distance to starting node is 0
    int startIndex = toIndex(startX, startY, col);
    frontier.push({0, startIndex});
    distances[startIndex] = 0;

    //cout << "Starting at: (" << startX << ", " << startY << ") Weight: " << grid[startIndex] << endl << endl;

    while (!frontier.empty()) {
        int currIndex = frontier.top().second;
        int currRow = currIndex / col;
        int currCol = currIndex % col;
        int currDist = frontier.top().first;
        frontier.pop();

        // Mark the node only if we are at the minimum distance for this node
        if (currDist > distances[currIndex]) {
            continue;  // Skip this node if we already found a better path
        }

        // Check for the end condition
        if (currRow == endY && currCol == endX) {
            cout << currDist << endl; // Output the total distance
            
            // Output the path as before
            int step = toIndex(endY, endX, col);
            vector<int> path;
            while (step != -1) {
                path.push_back(step);
                step = previous[step];
            }

            reverse(path.begin(), path.end()); // Reverse to get the right order

            for (size_t i = 0; i < path.size(); ++i) {
                cout << toCoords(path[i], row, col) << endl;
            }
            return 0; // Exit after finding the path
        }

        // Add children nodes to the frontier
        // For each direction, only add if it's within bounds and has not been marked
        if (currRow + 1 < row) { // Down
            int downIndex = toIndex(currRow + 1, currCol, col);
            if (marked.find(downIndex) == marked.end()) { // if the index is not in marked
                if (currDist + grid[currIndex] < distances[downIndex]) { // if there's a better path
                    previous[downIndex] = currIndex;
                    distances[downIndex] = currDist + grid[currIndex]; // Original weight calculation
                    frontier.push({distances[downIndex], downIndex});
                }
            }
        }
        if (currRow - 1 >= 0) { // Up
            int upIndex = toIndex(currRow - 1, currCol, col);
            if (marked.find(upIndex) == marked.end()) { // if the index is not in marked
                if (currDist + grid[currIndex] < distances[upIndex]) { // if there's a better path
                    previous[upIndex] = currIndex;
                    distances[upIndex] = currDist + grid[currIndex]; // Original weight calculation
                    frontier.push({distances[upIndex], upIndex});
                }
            }
        }
        if (currCol + 1 < col) { // Right
            int rightIndex = toIndex(currRow, currCol + 1, col);
            if (marked.find(rightIndex) == marked.end()) { // if the index is not in marked
                if (currDist + grid[currIndex] < distances[rightIndex]) { // if there's a better path
                    previous[rightIndex] = currIndex;
                    distances[rightIndex] = currDist + grid[currIndex]; // Original weight calculation
                    frontier.push({distances[rightIndex], rightIndex});
                }
            }
        }
        if (currCol - 1 >= 0) { // Left
            int leftIndex = toIndex(currRow, currCol - 1, col);
            if (marked.find(leftIndex) == marked.end()) { // if the index is not in marked
                if (currDist + grid[currIndex] < distances[leftIndex]) { // if there's a better path
                    previous[leftIndex] = currIndex;
                    distances[leftIndex] = currDist + grid[currIndex]; // Original weight calculation
                    frontier.push({distances[leftIndex], leftIndex});
                }
            }
        }
    }
    //cout << "No path found!" << endl; // If no path exists
    return 0;
}

