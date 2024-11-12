#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//MM:SS
int geTime(string str) {
  int min,sec;
  if(str.size() == 5) { // 10+ minuets
    min = stoi(str.substr(0,2));
    sec = stoi(str.substr(3,5));
  }
  else {
    min = stoi(str.substr(0,1));
    sec = stoi(str.substr(2,4)); 
  }
  return sec + (min * 60);
}

string printTime(int timeSec) {
  string time;
  time += to_string((timeSec / 60));
  time += ":";
  if(timeSec%60 < 10) {
    time += "0";
  }
  time += to_string((timeSec % 60));
  return time;
}

int main(){
  cout << "2:05" << endl;
  cout << geTime("2:05") << endl;
  cout << endl << "22:04" << endl;
  cout << geTime("22:04") << endl;
  //cout << printTime(geTime("2:05"));
}
