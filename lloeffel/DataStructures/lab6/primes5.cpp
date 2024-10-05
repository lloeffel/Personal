#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    map<int, bool> cache;
    string input;
    int lastValue = 0;
    
    while (cin >> input) {
        int value = stoi(input);
        
        for (int i = lastValue + 1; i <= value; ++i) {
            if (cache.find(i) == cache.end()) {
                cache[i] = isPrime(i);
            }
        }
        
        if (cache[value]) {
            cout << "prime" << endl;
        } else {
            cout << "not prime" << endl;
        }
        
        lastValue = value;
    }

    return 0;
}