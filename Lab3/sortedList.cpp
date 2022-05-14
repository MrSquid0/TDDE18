#include <iostream>
#include <string>

#include "sortedList.h"

// DONE: Use the data member initialization list when initializing
// data members in constructors. Example:

// My_Class::My_Class(int x)
//     : data_member { x }
// {
// }

// Instead of:

// My_Class::My_Class(int x)
// {
//     data_member = x;
// }

// This is the correct way to implement a constructor in C++.

// TODO: At least one of insert, remove, at or printList must be
// *recursive*. Right now all of them are iterative (using for-loops).


sortedList::sortedList()
    : first{nullptr}, size{0}
{} // constructor
sortedList::~sortedList()
{
    while(first != nullptr){
        remove(0);
    }
} //destructor
sortedList::sortedList(sortedList const& other)
{
    deepCopy(other);
} // copy constructor
sortedList::sortedList(sortedList&& other)
{
    move(other);
}; // move constructor
sortedList& sortedList::operator=(sortedList const& other)
{
    while (first != nullptr){
        remove(0);
    }
    deepCopy(other);
    return *this;
}; // copy assignment operator
sortedList& sortedList::operator=(sortedList&& other)
{
    move(other);
    return *this;
}; // move assignment operator
int sortedList::at (int index) const {
    Node* currentNode{};
    int valueStored{};
    if (size == 0){ //Case of not having any node
        std::cerr << "\nThe index " << index << " does not exist. "
                     "List is empty! Returning -1...\n";
        return -1;
    } else if (index >= size || index < 0){ //Recursive call
        std::cerr << "\nThe index " << index <<  " does not exist. "
                     "Returning the first element of the list...\n";
        return at(0);
    } else {
        currentNode = first;
        for (int i=0; i < size; i++){
            if (index == i){
                valueStored = currentNode->value;
            }
            currentNode = currentNode->next;
        }
    }
    return valueStored;
} //returns the value stored at a specified index
void sortedList::remove(int index)
{
    Node* prevNode{nullptr};
    Node* currentNode{nullptr};
    if (index>=size)
    {
        std::cerr << std::endl << "\nThe given index is not correct." << std::endl;
    }
    else if (first == nullptr)
    {
        std::cerr << std::endl << "\nThere is no node to remove" << std::endl;
    }
    else
    {
        if (index == 0) //Case of removing first node
        {
            Node* tmp = first;
            first = first->next;
            delete tmp;
            size--;
        }

	// TODO: This case, and the else-case are exactly the same if
	// you think about it (what does currentNode->next contain if
	// currentNode is the last node?)
	
        else if (index == size-1) //Case of removing last node
        {
            currentNode = first;
            for (int i=0; i<index; i++){
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            delete currentNode;
            prevNode->next = nullptr;
            size--;
        }
        else //Rest of cases
        {
            currentNode = first;
            for (int i=0; i<index; i++){
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            prevNode->next = currentNode->next;
            delete currentNode;
            size--;
        }
    }
}//removes a node by index
void sortedList::insert(int value) {
    Node *tmp{new Node{value}};
    if (this->isEmpty()) { // Case of adding the first node in an empty list
        tmp->next = first;
        first = tmp;
        size++;
    } else { //Cases of an existing list
        Node* currentNode{first};
        Node* prevNode{nullptr};
        for (int i = 0; i < getSize(); i++) {


	    // TODO: Calling at is not a good idea here. Why? Can you
	    // access the value of the current node in some other
	    // manner that doesn't require you to call at?
	    
            if (this->at(i) >= value) {
                if (i == 0) { //Case of adding a new first node
                    first = tmp;
                    tmp->next = currentNode;
                    size++;
                    break;
                } else { //Rest of cases
                    tmp->next = currentNode;
                    prevNode->next = tmp;
                    size++;
                    break;
                }

	    // TODO: This case is the same as the case above, see if
	    // you can merge these cases.
		
            } else if (i == getSize() - 1) { //Case of adding a new last node
                tmp->next = nullptr;
                currentNode->next = tmp;
                size++;
                break;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }

}// inserts a node in sorted order
bool sortedList::isEmpty() const{

    // DONE: The expression 'size == 0' returns a bool value already,
    // so using an if-statement is redundant. Instead do this:
    // return size == 0;

    return size == 0;
} //checks if a list is empty
std::string sortedList::printList() const{
    std::string print{};

    if (this->isEmpty()){
        print = "NULL.";
    } else {
        for (int i=0; i<size; i++)
        {

	    // TODO: This usage of the at function is not OK. Because
	    // for every index the at-function has to start at the
	    // beginning and loop to the correct index. This is too
	    // much work.
	    //
	    // Instead you should just iterate over the nodes, this
	    // way you don't have to start at the beginning every
	    // time.
	    
            if (i==size-1){ //Last iteration
                print += std::to_string(at(i)) + " -> NULL.";
            } else {
                print += std::to_string(at(i)) + " -> ";
            }
        }
    }
    return print;
} //prints the existing nodes
int sortedList::getSize() const{
    return size;
} //gets size of the list
void sortedList::deepCopy(sortedList const& other) {
    for (int i=0; i<other.getSize(); i++)
    {
	// TODO: Calling insert (and at) here is too much work (just
	// as with calling at in the TODO above). insert performs work
	// to make sure that the value is inserted in sorted
	// order. But the values in other is already sorted, so why do
	// we perform all that extra work?  Instead you should just
	// iterate over other and add each node at the end of "this",
	// this way no extra work is performed.
        this->insert(other.at(i));
    }
} //performs a deep copy of the list
void sortedList::move(sortedList& other){
    this->first = other.first;
    this->size = other.size;
    other.size=0;
    other.first = nullptr;
} // moves content from other to this object
