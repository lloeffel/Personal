//Name: Liam Loeffel
//Program Name: primes finder
//Description: This program finds all the primes within a given range
// and prints out the numbers it found in rows of 20 values.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]){
    //error checking
    if(argc != 2){ //usage
        cerr << "error: usage" << endl;
        return 1;
    }
    if(argv[1] <= 0){ //out of range 
        cerr << "error: input a positive integer above 0" << endl;
        return 1;
    }
    int limit = stoi(argv[1]); //upper limit
    vector<int> primes; //stores the primes
    //finding all the primes in the range: [2,limit-1]
    //since divide by 0 is an error, and everything is divisible by 1 and itself we can skip these calculations
    bool notPrime; //used to see if the next loop should also be continued thru
    for(int i = 2; i < limit; i++){ //goes thru the range of numbers between 2 and the upper limit
        notPrime = false;
        for(int j = 2; j < i; j++){ //finds if i is prime
            if(i%j == 0){
                notPrime = true;
                break;
            }
        }
        if(notPrime){continue;} //skips adding the value to the primes list
        primes.push_back(i);
    }

    //printing the primes
    for(size_t i = 0; i < primes.size(); i++){
        cout<<primes[i];
        if((i+1)%20 == 0){ //newline every 20 numbers
            cout << endl;
            continue;
        }
        if(i != primes.size()-1){cout << ", ";} //adds a comma after every value except the first one
    }
    cout << endl;
    //finding the primes
    return 0;
}