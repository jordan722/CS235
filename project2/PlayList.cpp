#include "PlayList.h"
#include "Song.h"
#include <iostream>

PlayList::PlayList(){
}


PlayList::PlayList(const Song& a_song){
  playlist_.add(a_song);
}


int PlayList::getNumberOfSongs() const{
  return playlist_.getCurrentSize();
}


bool PlayList::isEmpty() const{
  return playlist_.isEmpty();
}


bool PlayList::addSong(const Song& new_song){
  return playlist_.add(new_song);
}


bool PlayList::removeSong(const Song& a_song){
  return playlist_.remove(a_song);
}


void PlayList::clearPlayList(){
  playlist_.clear();
}


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
