#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Set.h"
#include "Song.h"

class PlayList
{
private:
  Set<Song> playlist_;

public:
  // default constructor
  PlayList();
  // constructor with a song to start playlist
  PlayList(const Song& a_song);
  // returns number of songs in playlist
  int getNumberOfSongs() const;
  // returns if playlist is empty
  bool isEmpty() const;
  // adds new song to playlist if possible
  // returns true if song is successfully added and false if not
  bool addSong(const Song& new_song);
  // removes song if possible
  // returns true is song is successfully removed and false if not
  bool removeSong(const Song& a_song);
  // removes all songs from playlist if possible
  void clearPlayList();
  // displays playlist
  void displayPlayList() const;

};
#endif /* end PLAYLIST_H_ */
