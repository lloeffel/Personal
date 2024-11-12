//Name: Liam Loeffel
// Challenge 09: sequence alignment
// Description: Aligns sequences based on Needleman-Wunsch algorithm

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string first, second;

    while(cin >> first >> second){
        int table[second.size() + 1][first.size() + 1];
        int tableWidth = first.size() + 1;
        int tableHeight = second.size() + 1;
        int gap = -1;
        int mismatch = -1;
        int match = 1;

        //filling in parts of the table we know 
        table[0][0] = 0;
        for(int i = 1; i < tableHeight; i++){
            table[i][0] = i * -1;
        }
        for(int i = 1; i < tableWidth; i++){
            table[0][i] = i * -1;
        }

        int up,left,diag;
        //figuring out values until we reach the bottom right corner of the table
        for(int i = 1; i < tableHeight; i++){
            for(int j = 1; j < tableWidth; j++){
                //calculating possibilities
                up = table[i-1][j] + gap;
                left = table[i][j-1] + gap;
                if(first[j-1] == second[i-1]){
                    diag = table[i-1][j-1] + match;
                }else{
                    diag = table[i-1][j-1] + mismatch;
                }
                //deciding which one is best
                if (up >= diag && up >= left){
                    table[i][j] = up;
                }else if(left >= diag && left >= up){
                    table[i][j] = left;
                }else{
                    table[i][j] = diag;
                }
            }
        } 
        //outputting the score of our alignment
        cout << table[tableHeight-1][tableWidth-1] << endl;
    }
    return 0;
}



