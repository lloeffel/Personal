// Lab 6: Is it prime?

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> cache = {0};
  string input; //stores the input
  int value;
  int tempStor;
  bool notPrime;
  while(cin >> input){
    value = stoi(input);
    if(cache.size() < value){
      tempStor = cache.size();
      cache.resize(value);
      for(int i = tempStor; i < value; i++){
        notPrime = false;
        for(int j = 2; j < i; j++){
          if(i%j == 0){
            notPrime = true;
            cache[i-1] = 0;
            break;
          }
        }
        if(notPrime){continue;}
        cache[i-1] = 1;
      }
    }else{
      if(cache[value-1] == 1){
        cout << "prime" << endl;
        continue;
      }
      cout << "not prime" << endl;
      continue;
    }
    if(cache[value-1] == 1){
        cout << "prime" << endl;
        continue;
    }
    cout << "not prime" << endl;
  }
  return 0;
}