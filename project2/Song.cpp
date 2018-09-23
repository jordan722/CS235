
Song::Song(){
}

// default constructor
Song::Song(const std::string& title, const std::string& author, const std::string& album){
  title_ = title;
  author_ = author;
  album_ = album;
}

// allows user to set/change title
void Song::setTitle(std::string title){
  title_ = title;
}

// allows user to set/change author
void Song::setAuthor(std::string author){
  author_ = author;
}

// allows user to set/change album
void Song::setAlbum(std::string album){
  album_ = album;
}

// allows user to retrieve title
std::string Song::getTitle() const{
  return title_;
}

// allows user to retrieve author name
std::string Song::getAuthor() const{
  return author_;
}

// allows user to retrieve album name
std::string Song::getAlbum() const{
  return album_;
}

// friend function
// sets definition for determining if two songs are the same
bool operator==(const Song& lhs, const Song& rhs){
  return (lhs.title_ == rhs.title_) && (lhs.author_ == rhs.author_) &&(lhs.album_ == rhs.album_);
}
