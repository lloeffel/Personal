//Name: Liam Loeffel
//Program Name: Prime Checker
//Description: This program takes a value and finds if that value is prime
// and finds all the values within a range of 0 and that value are prime and stores that in a cache.

// Lab 6: Is it prime?

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

vector<int> isPrime(int min, int max){
  int limit = max; //upper limit
  vector<int> primes; //stores the primes
    //finding all the primes in the range: [2,limit-1]
    //since divide by 0 is an error, and everything is divisible by 1 and itself we can skip these calculations
  bool notPrime; //used to see if the next loop should also be continued thru
  for(int i = min; i < limit; i++){ //goes thru the range of numbers between 2 and the upper limit
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
  return primes;
}

int main(int argc, char *argv[]) {
  vector<int> cache = {0,0};
  string input; //stores the input
  int maximum = 2; //initializing the maximum to the smallest prime
  int minimum; //stores the bottom of the range to look through
  while(cin >> input){
    //using https://unstop.com/blog/find-in-vector-cpp to learn the usage of the find() function
    if(find(cache.begin(), cache.end(), stoi(input)) == cache.end()){ //if the value is not in the cache
      minimum = maximum; //set the min
      maximum = stoi(input); //set the new max
      cache = isPrime(minimum,maximum); //set the updated cache
    }else{ //if it is in the cache
      cout << "prime" << endl;
      continue;
    }
    if(find(cache.begin(), cache.end(), stoi(input)) == cache.end()){cout << "not prime" << endl;} //if it is not in the cache after updating
  }


  return 0;

}

