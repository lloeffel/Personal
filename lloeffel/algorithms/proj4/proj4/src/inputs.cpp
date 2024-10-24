#include <cstdlib>
#include <iostream>
#include <map>
#include <random>

using namespace std;

int main (int argc, char *argv[]) {
    int size;
    cin >> size;


    map<char, int> tileWeights;
    
    tileWeights['f'] = 3;
    tileWeights['g'] = 1;
    tileWeights['G'] = 2;
    tileWeights['h'] = 4;
    tileWeights['m'] = 7;
    tileWeights['r'] = 5;

    char weights[6] = {'f','g','G','h','m','r'};

    cout << "6\nf 3\ng 1\nG 2\nh 4\nm 7\nr 5\n";
    cout << size << " " << size << endl;
   
    //chatGPT recomened this for a more truly random distribuiton
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 5);
    uniform_int_distribution<> dat(0, size);

    for(int row = 0; row < size; ++row) {
        for(int col = 0; col < size; ++col) {
            int randindex = dis(gen);
            //cout << "index: " << randindex;
            cout << weights[randindex] << " "; 
        }
        cout << endl;
    }
    cout << 0 << " " << 0 << endl;
    cout << size-1 << " " << size-1 << endl;
    return 0;
}
