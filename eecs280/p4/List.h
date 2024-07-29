#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  //EFFECTS:  returns true if the list is empty
  bool empty() const {
    return length == 0;
  };

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const {
    return length;
  };

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front() {
    return first->datum;
  };

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back() {
    return last->datum;
  };

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum) {
    Node* temp = new Node({nullptr, nullptr, datum});
    if (empty()) {
      first = temp;
      last = temp;
    }
    else {
      temp->next = first;
      first->prev = temp;
      first = temp;
    }
    length++;
  };

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum) {
    Node* temp = new Node({nullptr, nullptr, datum});
    if (empty()) {
      first = temp;
      last = temp;
    }
    else {
      temp->prev = last;
      last->next = temp;
      last = temp;
    }
    length++;
  };

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front() {
    Node* victim = first;
    first = first->next;
    length--;
    if (empty()) {
      last = first;
    }
    else {
      first->prev = nullptr;
    }
    delete victim;
  };

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back() {
    Node* victim = last;
    last = last->prev;
    length--;
    if (empty()) {
      first = last;
    }
    else {
      last->next = nullptr;
    }
    delete victim;
  };

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear() {
    while (!empty()) {
      pop_front();
    }
  };

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists
  List() {
    length = 0;
    first = nullptr;
    last = nullptr;
  };
  List(const List<T> &other) {
    length = 0;
    first = nullptr;
    last = nullptr;
    //Node* temp = other.first;
    //for (int i = 0; i < length; ++i) {
    //  push_back(temp->datum);
    //  temp = temp->next;
    //}
    copy_all(other);
  };
  ~List() {
    clear();
  };
  List& operator= (const List<T> &other) {
    copy_all(other);
    return *this;
  };

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };
  int length;
  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other) {
    if (this == &other) {
      return;
    }
    clear();
    Node* temp = other.first;
    for (int i = 0; i < other.length; ++i) {
      push_back(temp->datum);
      temp = temp->next;
    }
  };

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    };
    Iterator& operator++() {
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }
    bool operator==(const Iterator& other) const{
      return node_ptr == other.node_ptr;
    }
    bool operator!=(const Iterator& other) const{
      return node_ptr != other.node_ptr;
    }
    T& operator*() {
      return node_ptr->datum;
    }

    Iterator() {
      node_ptr = nullptr;
    };
    Iterator(const Iterator &other) {
      node_ptr = other.node_ptr;
    };
    Iterator& operator= (const Iterator &other) {
      node_ptr = other.node_ptr;
      return *this;
    };

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
    friend Iterator List::begin() const;
    friend Iterator List::end() const;
    friend void List::erase(Iterator i);
    friend void List::insert(Iterator i, const T &datum);

    // construct an Iterator at a specific position
    Iterator(Node *p) {
      node_ptr = p;
    };

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  };

  // return an Iterator pointing to "past the end"
  Iterator end() const {
    if (empty()) {
      return Iterator(last);
    }
    else {
      return Iterator(last->next);
    }
  };

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i) {
    Node* victim = i.node_ptr;
    Node* left = victim->prev;
    Node* right = victim->next;
    if (left) {
      left->next = right;
    }
    else {
      first = right;
    }
    if (right) {
      right->prev = left;
    }
    else {
      last = left;
    }
    delete victim;
    length--;
  };

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum) {
    if (empty()){
      push_back(datum);
      return;
    }
    Node* right = i.node_ptr;
    Node* left = right->prev;
    Node* temp = new Node({right, left, datum});
    right->prev = temp;
    if (left) {
      left->next = temp;
    }
    else {
      first = temp;
    }
    length++;
  };

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for


#endif // Do not remove this. Write all your code above this line.
