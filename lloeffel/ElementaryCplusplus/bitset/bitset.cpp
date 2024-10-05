/* Program Name: Bitset
 * Student Name: Liam Loeffel
 * Net ID: lloeffel
 * Student ID: STUDENT ID HERE (000-12-3456)
 * Program Description: This program takes in a users input to change a binary number, view the number, view the set, and see how many sets there are. The inputs are s-set,c-clear,q-quit,g-get,n-number of sets,t-test.*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BITSET {
	vector<int> mSets;

	public:
		BITSET();
		bool Test(int index) const;
		void Set(int index);
		void Clear(int index);
		int GetNumSets() const;
		int GetSet(int index) const;
};
string ToBinary(int bit_set, int spacing = 4);
int main() {
	BITSET sets;
	string command;
	int which;
	do {
		cout << "> ";
		if (!(cin >> command) || "q" == command) {
			// If cin fails for any reason, it usually means
			// an EOF state, break and quit.
			break;
		}
		// Handle the commands here
		if ("t" == command) {
			if (!(cin >> which)) {
				cout << "Invalid index\n";
			} else {
				cout << sets.Test(which) << '\n';
			}
		} else if ("s" == command) {
			if (!(cin >> which)) {
				cout << "Invalid index\n";
			} else {
				sets.Set(which);
			}
		} else if ("g" == command) {
			int spacing;
			string line;
			getline(cin, line);
			istringstream sin{line};
			if (!(sin >> which)) {
				cout << "Invalid index\n";
			} else {
				if (!(sin >> spacing)) {
					spacing = 4;
				}
				cout << ToBinary(sets.GetSet(which), spacing) << '\n';
			}
		} else if ("c" == command) {
			if(!(cin>>which)){
				cout << "Invalid index\n";
			}else{
				sets.Clear(which);
			}
		} else if ("n" == command) {
			cout << sets.GetNumSets() << '\n';
		} else {
			cout << "Unknown command '" << command << "'\n";
		}
	} while (true);
	return 0;
}
// Write the function body for ToBinary:
string ToBinary(int bit_set, int spacing) {
	string ret;
	for (int i = 31; i >= 0; i--) {
		if ((bit_set%2) == 1) {
			ret += '1';
		} else {
			ret += '0';
		}
		if (i % spacing == 0 && i != 0) {
			ret += ' ';
		}
		bit_set = bit_set/2;
	}

	//reverses the order of characters in the bitset
	string newRet;
	for (int i = ret.size()-1; i >= 0; i--){
		newRet += ret[i];
	}
	return newRet;
}

// BITSET Class Members
BITSET::BITSET() : mSets(1, 0) {}

bool BITSET::Test(int index) const {
	// Recall that each set has 32 bits
	int which_set = index/32; // TODO: FINISH THE ARITHMETIC HERE
	int which_bit = index%32; // TODO: FINISH THE ARITHMETIC HERE
	if (which_set >= GetNumSets()) {
		// The BITSET is an "infinite" set, so if the requested set
		// is bigger than what we are storing, that means it's a 0.
		return false;
	}
	// TODO: Write the code to test the bit at which_set/which_bit
	// and return true if it's a 1 or false if it's a 0.
	return (mSets[which_set] & (1 << which_bit)) != 0;
}

void BITSET::Set(int index) {
	int which_set = index/32; // TODO: FINISH THE ARITHMETIC HERE
	int which_bit = index%32; // TODO: FINISH THE ARITHMETIC HERE
	// TODO: You might need to expand the Set to accommodate the index
	// which_set. If you do not do this properly, you will get a runtime
	// error named 'out_of_range'
	// TODO: Finish the bitwise operator to set bit which_bit.
	while (which_set >= GetNumSets()) {
        mSets.push_back(0);
    }

    mSets[which_set] |= (1 << which_bit);
}

void BITSET::Clear(int index) {
	int which_set = index/32; // TODO: FINISH THE ARITHMETIC HERE
	int which_bit = index%32; // TODO: FINISH THE ARITHMETIC HERE
	if (which_set < GetNumSets()) {
		mSets.at(which_set) &= ~(1 << which_bit); // TODO: Finish the bitwise
		// operation(s) to clear bit which_bit.
		// TODO: Write the code here to truncate empty sets--sets that are 0.
		while (GetNumSets() > 1 && mSets.back() == 0) {
            mSets.pop_back();
        }
	}
}

int BITSET::GetNumSets() const { return static_cast<int>(mSets.size()); }

int BITSET::GetSet(int which_set) const {
	if (which_set >= 0 && which_set < GetNumSets()) {
        return mSets[which_set];
    }
    // Return 0 for non-existent sets
    return 0;
}
