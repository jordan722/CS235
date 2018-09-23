#ifndef SONG_H_
#define SONG_H_

class Song
{
private:
  std::string title_;
  std::string author_;
  std::string album_;


public:
  Song();
  Song(const std::string& title, const std::string& author = "", const std::string& album = "");
  void setTitle(std::string title);
  void setAuthor(std::string author);
  void setAlbum(std::string album);
  std::string getTitle() const;
  std::string getAuthor() const;
  std::string getAlbum() const;
  friend bool operator==(const Song& lhs, const Song& rhs);

};

#include "Song.cpp"
#endif /* SONG_H_ */















#include "Song.cpp"
#endif /* SONG_H_*/
