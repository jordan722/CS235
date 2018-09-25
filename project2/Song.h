#ifndef SONG_H_
#define SONG_H_


class Song
{
private:
  std::string title_;
  std::string author_;
  std::string album_;


public:
  // default constructor
  Song();
  // constructor with arguments
  Song(const std::string& title, const std::string& author = "", const std::string& album = "");
  // allows user to set/alter title of song
  void setTitle(std::string title);
  // allows user to set/alter author of song
  void setAuthor(std::string author);
  // allows user to set/alter album of song
  void setAlbum(std::string album);
  // returns title of song
  std::string getTitle() const;
  // returns author of song
  std::string getAuthor() const;
  // returns album of song
  std::string getAlbum() const;
  // friend function that allows us to compare songs
  friend bool operator==(const Song& lhs, const Song& rhs);

};

#endif /* SONG_H_ */
