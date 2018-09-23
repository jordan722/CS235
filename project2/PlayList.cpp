PlayList::PlayList(){
}


PlayList::PlayList(const Song& a_song){
  playlist_.addSong(a_song);
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
  playlist_.clear()
}


void PlayList::displayPlayList() const{
  for(int i = 0; i < playlist_.getCurrentSize(); i++){
    std::cout << playlist_[i] << std::endl;
  }
}
