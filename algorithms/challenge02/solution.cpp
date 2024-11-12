// Challenge 02: Closest Numbers
// Name: Liam Loeffel

// Brief description:

// This code finds the smallest difference between numbers in standard input, and outputs them.

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {
    int size, input, difference;
    vector<int> list, solutions;
    while(cin >> size){
        //resets the vectors
        list.clear(); 
        solutions.clear();
        //taking the values from input
        for(int i = 0; i < size; i++){
            cin >> input;
            list.push_back(input);
        }
        sort(list.begin(),list.end());
        //sets the first difference to be the greatest one
        difference = abs(list[0] - list[size - 1]);
        solutions.push_back(0);
        //solves the problem by clearing solutions when the solution found has a 
        //greater difference than the new comparison
        //Then it adds differences equal to the last to the solutions
        for(int i = 0; i < size - 1; i++){
            if(difference > abs((list[i] - list[i + 1]))){
                solutions.clear();
                solutions.push_back(i);
                difference = abs((list[i] - list[i + 1]));
            }else if(difference == abs((list[i] - list[i + 1]))){
                solutions.push_back(i);
            }
        }
        //printing the vals
        for(size_t i = 0; i < solutions.size() - 1; i++){
            cout << list[solutions[i]] << " " << list[solutions[i]+1] << " ";
        }
        //this cout is outside of loop so the CPU doesnt have to use a branch instruction every single loop iteration til the end
        cout << list[solutions[solutions.size()-1]] << " " << list[solutions[solutions.size()-1]+1] << endl;
    }
    return EXIT_SUCCESS;
}
