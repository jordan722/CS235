#ifndef SET_H_
#define SET_H_

#include <string>

#include "SetInterface.h"

template<class ItemType>
class Set: public SetInterface<ItemType>
{
private:
  static const int DEFAULT_SET_SIZE = 4; // for testing purposes we will keep the set small
  ItemType items_[DEFAULT_SET_SIZE]; // array of set items
  int item_count_;                  // current count of set items
  int max_items_;                   // max capacity of the set

  // post: Either returns the index of target in the array items_
  // or -1 if the array does not contain the target
  int getIndexOf(const ItemType& target) const;

public:
  // default constructor
  Set();
  // returns number of items in set
  int getCurrentSize() const override;
  // returns whether the set is empty
  bool isEmpty() const override;
  // adds item to set if possible
  // returns true if item is added and false if not added
  bool add(const ItemType& newEntry) override;
  // removes item from set if possible
  // returns true if item is successfully removed and false if not
  bool remove(const ItemType& anEntry) override;
  // removes all items from set
  void clear() override;
  // returns whether the set contains a certain element
  bool contains(const ItemType& anEntry) const override;
  std::vector<ItemType> toVector() const override;
};

#include "Set.cpp"
#endif /* SET_H_ */
