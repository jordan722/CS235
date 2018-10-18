// Name: Jordan Yaqoob
// Assignment: CS235 Project 3
// Date: October 15, 2018
// Description: Node PlayList Functions


#include "PlayList.h"
#include <iostream>

// initialize
PlayList::PlayList() : tail_ptr_(nullptr) {}

// paramater constructor
PlayList::PlayList(const Song& a_song) {
	add(a_song);
}

// copy constructor
PlayList::PlayList(const PlayList& a_play_list) : LinkedSet<Song>(a_play_list) {
	tail_ptr_ = getPointerToLastNode();
}

// destructor
PlayList::~PlayList() {
	unloop();
	clear();
}

// get the last node in the chain
Node<Song>* PlayList::getPointerToLastNode() const {
	// Create node
	Node<Song>* last = head_ptr_;
	// traverse chain
	while (last->getNext() != nullptr)
		last = last->getNext();

	return last;
}

// get the specified pointer and preserve order
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
  bool found = false;
	Node<Song>* curr_ptr = head_ptr_;
	int loc = 0;
	while (!found && (curr_ptr != nullptr) )
	{
    // set previous
		if (loc <= 1) {
			previous_ptr = head_ptr_;
		}
		else {
			previous_ptr = previous_ptr->getNext();
		}

    // check if target is found
		if (target == curr_ptr->getItem()) {
			found = true;
		}
		else {
			curr_ptr = curr_ptr->getNext();
		}

		//increment location by 1
		loc += 1;
	}

	return curr_ptr;
}


// Adds a song to the playlist from the end
bool PlayList::add(const Song& new_song) {
	// Create node
	auto new_node = new Node<Song>(new_song);
	bool result = true;

	if (!contains(new_song)) {
    // checking if node empty or not
		if (tail_ptr_ == nullptr) {
			head_ptr_ = new_node;
			tail_ptr_ = head_ptr_;
		}
		else {
			tail_ptr_->setNext(new_node);
			tail_ptr_ = tail_ptr_->getNext();
		}

		item_count_++;
    return true;
	}
  return false;
}


bool PlayList::remove(const Song& target_song) {
	auto prev_node = new Node<Song>();

	Node<Song>* target_node = getPointerTo(target_song, prev_node);

	if (!isEmpty() && target_node != nullptr) {
    // removes node from head
		if (target_node == head_ptr_) {
			head_ptr_ = head_ptr_->getNext();
		}
		else {
			prev_node->setNext(target_node->getNext());
			prev_node = prev_node->getNext();
		}

		item_count_--;
    return true;
	}
	return false;
}


// connects tail to head for looping
void PlayList::loop() {
	tail_ptr_->setNext(head_ptr_);
}

// sets next of tail pointer back to null
void PlayList::unloop() {
	tail_ptr_->setNext(nullptr);
}

// print out name of title, author and album
void PlayList::displayPlayList() {
	std::vector<Song> song_vector = toVector();

	for (int i = 0; i < getCurrentSize(); i++) {
		std::cout << "* Title: " << song_vector[i].getTitle()
		          << " * Author: " << song_vector[i].getAuthor()
		          << " * Album: " << song_vector[i].getAlbum() << " * " << '\n';
	}

	std::cout << "End of playlist" << '\n';

}
