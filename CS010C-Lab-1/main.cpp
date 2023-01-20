#include <string>
#include <iostream>

using namespace std;

#include "Playlist.h"

PlaylistNode songList;
void printMenu(string listTitle);
// void outputFullList(string listTitle, PlaylistNode *head);
// void addSong(PlaylistNode* &head, PlaylistNode* &tail);

int main() {

  string userOption;
  string newID, newSong, newArtist;
  string userArtist;
  int newLength;
  string listTitle;

  cout << "Enter playlist's title:" << endl << endl;
  getline(cin, listTitle);

  while (true) {
    printMenu(listTitle);
    cout << endl;
    cout << "Choose an option:" << endl;
    cin >> userOption;
    cin.ignore();

    if(userOption == "s") {
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:" << endl;
      getline(cin, userArtist);
      cout << endl;
      songList.artistSongs(userArtist);
    }
    else if (userOption == "o") {
      cout << listTitle << " - OUTPUT FULL PLAYLIST" << endl;
      songList.outputFullList();
    }
    else if(userOption == "a") {
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> newID;
      cin.ignore();
      cout << "Enter song's name:" << endl;
      getline(cin, newSong);
      cout << "Enter artist's name:" << endl;
      getline(cin, newArtist);
      cout << "Enter song's length (in seconds):" << endl;
      cin >> newLength;
      cout << endl;
      songList.addSong(newID, newSong, newArtist, newLength);
    }
    else if(userOption == "d") {
      string delSong;
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> delSong;
      songList.removeSong(delSong);
    }
    else if(userOption == "c") {
      cout << "CHANGE POSITION OF SONG" << endl;
      int songPos, newPos;
      cout << "Enter song's current position:" <<endl;
      cin >> songPos;
      cout << "Enter new position for song:" << endl;
      cin >> newPos;
      songList.changePosition(songPos, newPos);
    }
    else if(userOption == "t") {
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      cout << "Total time: " << songList.songTime() << " seconds" << endl;
      cout << endl;
    }
    else if(userOption == "q") {
      break;
    }
  }
}

void printMenu(string listTitle) {
  cout << listTitle << " PLAYLIST MENU" << endl;
  cout << "a - Add song" << endl;
  cout << "d - Remove song" << endl;
  cout << "c - Change position of song" << endl;
  cout << "s - Output songs by specific artist" << endl;
  cout << "t - Output total time of playlist (in seconds)" << endl;
  cout << "o - Output full playlist" << endl;
  cout << "q - Quit" << endl;
}

// Below is code that was migrated over to my Playlist.cpp
//------------------------------------------------------------------------------
// void outputFullList (string listTitle, PlaylistNode *head) {
//   int i = 1;
//   PlaylistNode *listPtr = head;
//   cout << listTitle << " - OUTPUT FULL PLAYLIST" << endl;
//   if (head == nullptr) {
//     cout << "Playlist is empty" << endl;
//     cout << endl;
//     printMenu(listTitle);
//   }
//   else {
//     while (listPtr != nullptr) {
//       cout << i << "." << endl;
//       listPtr -> PrintPlaylistNode();
//       cout << endl;
//       listPtr = listPtr -> GetNext();
//       i++;
//     }
//   }
// }

// void addSong(string newID, string newSong, string newArtist, int newLength) {
//   PlaylistNode *newSong = new PlaylistNode(newID, newSong, newArtist, newLength);

//   cout << "ADD SONG" << endl;
//   cout << "Enter song's unique ID:" << endl;
//   cin >> newID;
//   cin.ignore();
//   cout << "Enter song's name:" << endl;
//   getline(cin, newSong);
//   cout << "Enter artist's name:" << endl;
//   getline(cin, newArtist);
//   cout << "Enter song's length (in seconds):" << endl;
//   cin >> newLength;
  
//   if (head == nullptr) {
//     head = tail = new PlaylistNode(newID, newSong, newArtist, newLength);
//   }
//   else {
//     tail -> InsertAfter(newID, newSong, newArtist, newLength);
//   }
//}

// void removeSong(PlaylistNode* &head, PlaylistNode* &tail) {
//   string removeID;
//   PlaylistNode *removeSong = head, *temp ;
//   cout << "REMOVE SONG" << endl;
//   cout << "Enter song's unique ID:" << endl;
//   cin >> removeID;

//   while (removeSong !)
// }