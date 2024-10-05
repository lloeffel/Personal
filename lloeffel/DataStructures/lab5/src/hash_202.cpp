//NAME: Liam Loeffel (utkID: lloeffel)
//Program: Hash table Class Definitions
//DATE: 3/8/2024
//Description: This function allows for the creation of a hash table, addition of values to it, printing it, finding values in it, and finding of the total probes


#include "hash_202.hpp"
using namespace std;
//used for the pow function in the hexToInt function
//url: https://www.programiz.com/cpp-programming/library-function/cmath/pow
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>

//Helper Functions (Inspired by Ashley's videos)
//url: https://www.youtube.com/watch?v=0XFmDar1bX0
int hexToInt(const string& hexNum){
  int returnVal = 0; //integer version of the hex string
  int j = 0;         //incrementer to count what place of the hexadecimal we are in
  int hexValue; //stores the hex string to an int
  //go thru the hex string backwards
  for(int i = hexNum.length() - 1; i >= 0; i--){ 
    if (hexNum[i] > 96){ //if the char is a letter
      hexValue = hexNum[i] - 87;
    }else{ //if the char is a number
      hexValue = hexNum[i] - 48;
    }
    returnVal = returnVal + (hexValue * pow(16,j)); //convert that number to decimal
    j++;
  }
  return returnVal;
}

//checks if the string is valid hexadecimal
bool isHex(const string& key){
  bool returnVal = true;
  for (size_t i = 0; i < key.length(); i++){
    if(!(((key[i] >= 'a') && (key[i] <= 'f')) || ((key[i] >= '0') && (key[i] <= '9')))){
      returnVal = false;
    }
  }
  return returnVal;
}

//does the hash function of Last7
int Last7(string key){
  
  if (key.length() < 7){return hexToInt(key);}
  return hexToInt(key.substr(key.length()-7,7));
}

//does the hash function of XOR
int XOR(string key){  
  if(key.length() < 7){return hexToInt(key);}
  string copyKey = key; //copies the key from the args
  vector<string> terms;
  int lengthLeft = key.length(); //stores how much of the string we have left to read
  int finalVal;
  //seperating the string into groups of 7
  while(lengthLeft > 7){
    terms.push_back(copyKey.substr(0,7));   //Taking the first 7 characters of the string and adding it to the array
    lengthLeft = lengthLeft - 7;            //updating the length left variable
    copyKey = copyKey.substr(7,lengthLeft); //updating the copykey
  }
  terms.push_back(copyKey); //in case the last bit of the string is less than 7
  
  //notting all the terms
  finalVal = hexToInt(terms[0]);
  for(size_t i = 1; i < terms.size();i++){
    finalVal = finalVal ^ hexToInt(terms[i]);
  }
  return (finalVal);
}


int getHashIndex(string key){
  (void) key;
  return 0;
}
//end helper functions

//Sets up the Hash Table
string Hash_202::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision)
{
  //error checking
  if (Keys.size() != 0){return "Hash table already set up";}
  if (table_size < 1)  {return "Bad table size";}
  if (fxn.compare("XOR") != 0 && fxn.compare("Last7") != 0){return "Bad hash function";}
  if (collision.compare("Linear") != 0 && collision.compare("Double") != 0){return "Bad collision resolution strategy";}
  //resizing our vectors to the table_size
  Keys.resize(table_size);
  Vals.resize(table_size);
  for(size_t i = 0; i < Keys.size(); i++){
    Keys[i] = "-1";
  }
  //setting the function that will be used  
  if (fxn[0] == 'X'){Fxn = 0;} //if it is Xor
  if (fxn[0] == 'L'){Fxn = 1;} //if it is Last7
  //setting the collision resolution type
  Coll = collision[0];
  //setup for all other variables:
  Nkeys = 0;
  Nprobes = 0;
  return "";
}

//Adds a value to the Hash Table
string Hash_202::Add(const string &key, const string &val)
{
  //error testing
  if (Keys.size() == 0){return "Hash table not set up";}//hash table not set up
  if (key.size() == 0){return "Empty key";} //empty key
  if (!isHex(key)){return "Bad key (not all hex digits)";}//bad key check
  if (val.size() == 0){return "Empty val";}//empty val check
  if (Nkeys == Keys.size()){return "Hash table full";}//hash table full
  //key already in the table
  for(size_t i = 0; i < Keys.size();i++){
    if(Keys[i].compare(key) == 0){return "Key already in the table";}
  }

  int prober = 1; //how much the probing increments
  int x = XOR(key)%Keys.size(); //stores the value of the xor
  int l = Last7(key)%Keys.size(); //stores the value of the last7
  int hash; //stores the designated hash function
  if (Coll == 'D'){ //if double hashing
    if(Fxn == 0){
      if(l == 0){l++;}
      prober = l;
    } //if the double hash was 0
    if(Fxn == 1){
      if(x == 0){x++;}
      prober = x;
    } //if the double hash was 0
  }
  
  if(Fxn == 0){hash = x;}
  if(Fxn == 1){hash = l;}
  
  if(Keys[hash].compare("-1") == 0){ //if the spot is empty
    Keys[hash] = key;
    Vals[hash] = val;
  }else{ //collision! (oh no)
    Nprobes++;
    int i = 1; //incrementer
    int tempProbes = 0; //temporary probes counter that will not be added to Nprobes if the insertion fails
    while(Keys[(hash+(prober * i))%Keys.size()].compare("-1") != 0){ //while there are not empty spots
      if (i > (int)Keys.size()){ //if the value cant be inserted
        Nprobes--;
        return "Cannot insert key";
      }
      i++;
      tempProbes++;
    }
    //set Nprobes
    Nprobes = Nprobes + tempProbes;
    Keys[(hash+(prober * i))%Keys.size()] = key;
    Vals[(hash+(prober * i))%Keys.size()] = val;
  }
  Nkeys = Nkeys + 1;
  return "";
}

//finds the value for a given key
string Hash_202::Find(const string &key)
{
  //error checking
  if (Keys.size() == 0){return "";}//hash table has been set up?
  if (!isHex(key)){return "";}//is the key composed of all hex digits

  //traverse the hash table looking for the key
  for(size_t i = 0; i < Keys.size(); i++){
    if(Keys[i].compare(key) == 0){
      return Vals[i];
    }
  }
  return "";
}

//prints a formatted hash table
void Hash_202::Print() const
{
  if(Keys.size() != 0){ //if there is a hash table
    for(size_t i = 0; i < Keys.size(); i++){ //go thru the whole array
      if(!(Keys[i].compare("-1") == 0)){ //is the row not empty
        cout << setfill(' ') << right << setw(5) << i << " " << Keys[i] << " " << Vals[i] << endl;
      }
    }
  }
}

//returns the number of probes
//if the table is not set up then it returns 0
size_t Hash_202::Total_Probes()
{
  //if the hash is not set up return 0
  if (Keys.size() == 0){return 0;}
  return Nprobes;
}
