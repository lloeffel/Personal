// Challenge 06: Palindrome Permutation
// Name: Liam Loeffel
// Description: This code iterates thru an input file in cin and finds if a line is an interation of a palindrome.
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

//checks if a string is an interation of a palindrome not including non letter characters
bool is_palindrome(string s){
  map <int, int> letters; //stores the letters and number that letter occurs
  int whatLetter = 0;     //stores the int value of the uppercase letter in every case
  int charCount = 0;      //stores the number of actual characters in the palindrome
  bool oddState = false;  //specifies if there are an odd number of characters
  
  for(size_t i = 0; i < s.size(); i++){ //fill the map with values
    if(((s[i] >= 65) && (s[i] <= 90))){ //if it is lowercase
      whatLetter = s[i];
      charCount++;
    }else if(((s[i] >= 97) && (s[i] <= 122))){ //if it is uppercase
      whatLetter = s[i] - 32;
      charCount++;
    }else{ //if it's not a letter
      continue;
    }
    if(letters.find(whatLetter) == letters.end()){ //if the letter is not in the map
      letters.insert({whatLetter,1});
    }else{
      letters[whatLetter]++;
    }
  }

  //checking if it is a palindrome:
  if((charCount%2) != 0){oddState = true;}//if the number of characters is odd 
  for (map<int,int>::iterator it= letters.begin(); it != letters.end(); ++it) {
    if((it->second)%2 != 0){ //number of chars is odd
      if(oddState == true){
        oddState = false;
      }else{
        return false;
      }
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  string input;
  while(getline(cin,input)){ //iterates thru the input file
    //printer
    if(is_palindrome(input)){
      cout << "\"" << input << "\"" << " is a palindrome permutation" << endl;
    }else{
      cout << "\"" << input << "\"" << " is not a palindrome permutation" << endl;
    }
  }
  return (0);
}

