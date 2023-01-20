#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iostream>

using namespace std;

class PlaylistNode {

public:
    PlaylistNode(); //Default constructor
    PlaylistNode(string myID, string myName, string myArtist, int myLength); //Parameterized constructor
    void PrintPlaylistNode();
    void InsertAfter(PlaylistNode *node);
    void SetNext(PlaylistNode *next); //Mutator
    string GetID(); 
    string GetSongName(); 
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    
    void addSong (string newID, string newSong, string newArtist, int newLength);
    void outputFullList();
    void removeSong(string delSong);
    void changePosition(int songPos, int newPos);
    void artistSongs (string userArtist);
    int songTime();

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* head;
    PlaylistNode* tail;
    PlaylistNode* temp;
    PlaylistNode* nextNodePtr; //Gives you the ptr to next node in the list.
};

#endif