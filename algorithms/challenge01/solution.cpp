//Name: Liam Loeffel (netID: lloeffel)
//Challenge 01: Rotating Arrays; null solution
//Description: This program will rotate an array based on inputs like direction and offset.
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int input;
    int size;
    int shift;
    char direction;
    vector<int> nums;

    //main loop
    while(cin >> size >> shift >> direction){
        nums.resize(size); //change size so no array out of bounds
        if(direction == 'R'){ //choosing which direction
            for(int i = 0; i < size; i++){ 
                cin >> input;
                nums[((i+(shift%size)+size)%size)] = input; //insertion
            }
        }else{
            for(int i = 0; i < size; i++){
                cin >> input;
                nums[((i-(shift%size)+size)%size)] = input; //insertion
            }
        }
        //print loop
        for (int j = 0; j < size-1; j++){
            cout << nums[j] << " ";
        }
        //last number print with no space
        cout << nums[size-1] << endl;
    }
    return 0;
}

