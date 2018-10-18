// Name: Jordan Yaqoob
// Assignment: CS235 Project 3
// Date: October 15, 2018
// Description: header file for Node PlayList

#pragma once
#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song> {
  private:
    // pointer to last node
  	Node<Song>* tail_ptr_;
  	Node<Song>* getPointerToLastNode() const;
  	Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;

  public:
    // default constructor
  	PlayList();
    // constructor with first song added
  	PlayList(const Song& a_song);
    // copy constructor
  	PlayList(const PlayList& a_play_list);
    // destructor
  	~PlayList();

  	bool add(const Song& new_song) override;
  	bool remove(const Song& old_song) override;
  	void loop();
  	void unloop();
  	void displayPlayList();
};
