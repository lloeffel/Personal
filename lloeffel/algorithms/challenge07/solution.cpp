//Name: Liam Loeffel
// Challenge 08: Repeated DNA sequences
// Description: This code will iterate thru a sequence of DNA and find repeated strings in that DNA strand that are 9 letters long

#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
    set<string> repeats = {}; //stores repeated values
    set<string> observed = {}; //stores seen values
    string DNA = "";
    while(getline(cin, DNA)){
        //resets for every DNA scan 
        repeats.clear();
        observed.clear();
        //making sure the string is long enough
        if(DNA.length() < 9){
            cout << "-1" << endl;
            continue;
        }

        //iterating thru the string
        for(size_t i = 0; i < DNA.length()-8;i++){
            string lookAt = DNA.substr(i,9);
            //if we have seen this value, and if we have not seen it twice
            if((observed.find(lookAt) != observed.end()) && (repeats.find(lookAt) == repeats.end())){
                repeats.insert(lookAt);
                continue;
            }
            observed.insert(lookAt);
        }
        //printing repeats
        set<string>::iterator it;
        for(it = repeats.begin(); it != repeats.end(); it++){
            cout << *it << endl;
        }
        cout << "-1" << endl;
    }

    return 0;
}


