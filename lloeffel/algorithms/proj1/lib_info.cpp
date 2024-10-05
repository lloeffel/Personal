//David Floyd
//Liam loeffel 
//had to get some help from stack overflow for remmbering how to read in a file
// https://stackoverflow.com/questions/7880/how-do-you-open-a-file-in-c

#include <complex>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Song {
  string title;
  int time = 0;
  int track = 0;
};

struct Album {
  map <int, Song > songs;
  string name;
  int time = 0;
  int nsongs = 0;
};

struct Artist {
  map <string, Album > albums;
  string name;
  int time = 0;
  int nsongs = 0;
};

//takes a formated string MM:SS and returns number of seconds
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

//takes time in seconds and returns a formated string MM:SS
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

int main (int argc, char *argv[]) {

  if(argc != 2){ //check that the user passes the right number of args
    cerr << "ussage: ./main file\n";
    return 1;
  }
  ifstream in(argv[1]); //open the passed file

  if(!in) { //make sure it opened right
    cerr << "could not open file\n";
    return 1;
  }

  vector<string> text;
  string line,word;
  string title,timems,artist,album,genre,track;
  int inttime, inttrack;
  map <string, Artist> artists;

  // extract all the text from the input file
  while (getline(in, line)) {
    text.push_back(line);
    stringstream str(line);

    str >> title >> timems >> artist >> album >> genre >> track;

    //replace dashes with spaces
    replace(title.begin(),title.end(),'_',' ');
    replace(artist.begin(),artist.end(),'_',' ');
    replace(album.begin(),album.end(),'_',' ');
    replace(genre.begin(),genre.end(),'_',' ');
    inttrack = stoi(track);
    inttime = geTime(timems);

    if(artists.find(artist) == artists.end()){  //artist is not in map
      //get info for song
      Song s;
      s.time = inttime;
      s.title = title;
      s.track = inttrack;

      //add new album to artist
      Album a;
      a.time += s.time;
      a.name = album;
      a.songs.insert({inttrack,s}); //map int, song
      a.nsongs++;

      //add a new artist
      Artist art;
      art.time += s.time;
      art.nsongs++;
      art.name = artist;
      art.albums.insert({album,a}); //string album
      artists.insert({artist, art});
    }else{
      if(artists.at(artist).albums.find(album) == artists.at(artist).albums.end()){   //album is not in map
        Song s;
        s.time = inttime;
        s.title = title;
        s.track = inttrack;

        //setting up new album
        Album a;
        a.time += s.time;
        a.name = album;
        a.songs.insert({inttrack,s}); //map int, song
        a.nsongs++;

        //updating artist
        artists.at(artist).albums.insert({album, a});
        artists.at(artist).time += s.time;
        artists.at(artist).nsongs++;

      }else{
        Song s;
        s.time = inttime;
        s.title = title;
        s.track = inttrack;

        //updating album
        artists.at(artist).albums.at(album).songs.insert({inttrack,s});
        artists.at(artist).albums.at(album).time += s.time;
        artists.at(artist).albums.at(album).nsongs++;

        //updating artist
        artists.at(artist).albums.insert({album, artists.at(artist).albums.at(album)});
        artists.at(artist).time += s.time;
        artists.at(artist).nsongs++;
      }
    }
  }

  string blankspace1 = "        ";
  string blankspace2 = "                ";

  for (map<string,Artist>::iterator it= artists.begin(); it != artists.end(); ++it) {
    cout << it->first << ": " << it->second.nsongs << ", " << printTime(it->second.time) << endl;
    for(map<string,Album>::iterator it2 = it->second.albums.begin(); it2 != it->second.albums.end(); ++it2) {
      cout << blankspace1 << it2->first << ": " << it2->second.nsongs << ", " << printTime(it2->second.time) << endl;
      /* currently this breaks it for some reason */ 
      for(map<int,Song>::iterator it3 = it2->second.songs.begin(); it3 != it2->second.songs.end(); ++it3) {
        cout << blankspace2 << it3->first << ". " << it3->second.title << ": " << printTime(it3->second.time) << endl;
      }
    }
  }
  

  in.close();
  return 0;
}
