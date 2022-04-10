#ifndef LAB3_SORTEDLIST_H
#define LAB3_SORTEDLIST_H

#include <string>
#include <iostream>

class sortedList
{
public:
    sortedList(); // constructor
    ~sortedList(); // destructor
    sortedList(sortedList const& other); // copy constructor
    sortedList(sortedList&& other); // move constructor
    sortedList& operator=(sortedList const& other); // copy assignment operator
    sortedList& operator=(sortedList&& other); // move assignment operator

    int at(int index) const; // returns the value stored at a specified index
    void remove(int index); // removes a node by index
    void insert (int value); // inserts a node in sorted order
    std::string printList (); // prints the existing nodes
    bool isEmpty(); // checks if a list is empty
    int getSize(); //gets size of the list
    void deepCopy(sortedList const& other); //performs a deep copy of the list
    void move(sortedList& other);

private:
    struct Node
    {
        int value;
        Node* next;
    };

    Node* first{};
    int size{};
};

#endif