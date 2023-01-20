#include <iostream>
#include <string>

using namespace std;

#include "Playlist.h"

PlaylistNode::PlaylistNode() {
  uniqueID = "none";
  songName = "none";
  artistName = "none";
  songLength = 0;
  nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string myID, string myName, string myArtist, int myLength) {
  uniqueID = myID;
  songName = myName;
  artistName = myArtist;
  songLength = myLength;
  nextNodePtr = 0;
}

void PlaylistNode::PrintPlaylistNode() {
  cout << "Unique ID: " << uniqueID << endl;
  cout << "Song Name: " << songName << endl;
  cout << "Artist Name: " << artistName << endl;
  cout << "Song Length (in seconds): " << songLength  << endl;
}
void PlaylistNode::SetNext(PlaylistNode *next) {
  nextNodePtr = next;
}

string PlaylistNode::GetID() {
  return uniqueID;
}

string PlaylistNode::GetSongName() {
  return songName;
}

string PlaylistNode::GetArtistName() {
  return artistName;
}

int PlaylistNode::GetSongLength() {
  return songLength;
}


PlaylistNode *PlaylistNode::GetNext() {
  return nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode *node) {
  PlaylistNode *temp = this -> nextNodePtr;
  this -> nextNodePtr = node;
  node -> nextNodePtr = temp;
}
// PlaylistNode* PlaylistNode::InsertAfter(PlaylistNode) {
//   nextNodePtr = new PlaylistNode (newID, newSong, newArtist, newLength);
//   return nextNodePtr;
// }

void PlaylistNode::addSong(string newID, string newSong, string newArtist, int newLength) { //I realized that my main.cpp should not have all the member functions. This is migrated from my previous version.
  PlaylistNode *incSong = new PlaylistNode(newID, newSong, newArtist, newLength);

  if (head == nullptr) {
    head = tail = incSong;
  }
  else {
    tail -> InsertAfter(incSong);
    tail = incSong;
  }
}

void PlaylistNode::outputFullList () { //This is also migrated from my previous version.
  int i = 1;
  PlaylistNode *listPtr = head;
  if (head == nullptr) {
    cout << "Playlist is empty" << endl;
    cout << endl;
  }
  else {
    while (listPtr != nullptr) {
      cout << i << "." << endl;
      listPtr -> PrintPlaylistNode();
      cout << endl;
      listPtr = listPtr -> GetNext();
      i++;
    }
  }
}

void PlaylistNode::removeSong(string delSong) {
  PlaylistNode* temp = head;
  PlaylistNode* next = nullptr;

  if (head == nullptr) { //If there are no songs in the playlist
    cout << "Playlist is empty" << endl;
    cout << endl;
  }
  while (temp != nullptr) { //Checking songs with delSong's ID
    if (temp -> GetID() == delSong) {
      break;
    }
    next = temp;
    temp = temp -> GetNext();
  }
  if (next != nullptr) {
    next -> SetNext(temp -> GetNext());
  }
  else {
    head = temp -> GetNext();
  }
  if (tail == temp) {
    tail = next;
  }

  cout <<"\"" << temp -> GetSongName() << "\"" << " removed." << endl;
  cout << endl;

  delete temp;
}

void PlaylistNode::changePosition(int songPos, int newPos) {
    
    PlaylistNode *temp = head, *next = 0, *poi;
    
    for(int i=1;temp != 0 && i < songPos; i++) {
      next = temp;
      temp = temp->GetNext();
      cout << temp->GetSongName() << endl;
    }
    string oldSong = temp -> GetSongName();
    if(temp == 0) {
      return;
    }
    if(head == temp) {
      head = temp -> GetNext();
    }
    else {
      next->SetNext(temp->GetNext());
      if(tail == temp) {
      tail = next;
      }
    }
    temp->SetNext(0);
    poi = temp;
    temp = head;
    next = 0;
    for(int i=1; temp != 0 && i< newPos; i++) {
      next = temp;
      temp = temp->GetNext();
    }
    if(next == 0) {
      poi->SetNext(head);
      head = poi;
    }
    else {
      poi -> SetNext(next -> GetNext());
      next->SetNext(poi);
      if(tail == next) {
        tail = poi;
      }
    }
    cout << "\"" << oldSong << "\" moved to position " << newPos << endl << endl;
}

void PlaylistNode::artistSongs(string userArtist) {
  PlaylistNode *temp = head;
  int i = 1;
  if (head == nullptr) {
    cout << "Playlist is empty" << endl;
    cout << endl;
  }
  else {
    while (temp != nullptr) {
      if (temp -> GetArtistName() == userArtist) {
        cout << i << "." << endl;
        temp -> PrintPlaylistNode();
        cout << endl;
      }
      temp = temp -> GetNext();
      i++;
    }
  }
}

int PlaylistNode::songTime() {
  int total = 0;
  PlaylistNode *temp = head;
  while (temp != nullptr) {
    total = total + temp->GetSongLength();
    temp = temp -> nextNodePtr;
  }

  return total;
}