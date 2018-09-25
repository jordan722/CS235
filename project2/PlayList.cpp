#include "PlayList.h"
#include "Song.h"
#include <iostream>

// default constructor
PlayList::PlayList(){
}

// constructor that instantiates playlist with a given song in it
PlayList::PlayList(const Song& a_song){
  playlist_.add(a_song);
}

// returns number of songs in playlist
int PlayList::getNumberOfSongs() const{
  return playlist_.getCurrentSize();
}

// returns true if playlist is empty, false if not
bool PlayList::isEmpty() const{
  return playlist_.isEmpty();
}

// adds song if possible
// returns true if song successfully added, false if not
bool PlayList::addSong(const Song& new_song){
  return playlist_.add(new_song);
}

// removes song if possible
// returns true if song is successfully removed, false if not
bool PlayList::removeSong(const Song& a_song){
  return playlist_.remove(a_song);
}

// removes all songs from playlist
void PlayList::clearPlayList(){
  playlist_.clear();
}


// displays the contents of playlist
void PlayList::displayPlayList() const{
  std::vector<Song>  song_vector = playlist_.toVector();
  for(int i = 0; i < playlist_.getCurrentSize(); i++){
    std::cout << "* Title: " << song_vector[i].getTitle()
		          << " * Author: " << song_vector[i].getAuthor()
		          << " * Album: " << song_vector[i].getAlbum() << " * " << '\n';
    //std::cout << song_vector[i] << std::endl;
  }
  std:: cout << "End of playlist" << '\n';
}
