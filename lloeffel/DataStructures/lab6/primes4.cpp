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
  bool notPrime;
  for(int i = min; i < limit; i++){
        notPrime = false;   
        for(int j = 2; j < i; j++){
            if(i%j == 0){
                notPrime = true;
                break;
            }
        }
        if(notPrime){continue;}
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
    if(binary_search(cache.begin(), cache.end(), stoi(input)) == false){
      minimum = maximum;
      maximum = stoi(input);
      cache = isPrime(minimum,maximum);
    }else{
      cout << "prime" << endl;
      continue;
    }
    if(binary_search(cache.begin(), cache.end(), stoi(input)) == false){cout << "not prime" << endl;}
  }


  return 0;

}

