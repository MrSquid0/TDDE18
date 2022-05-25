#include <iostream>
#include <string>

#include "sortedList.h"

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
        for (int i{0}; i < size; i++){
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
            Node* tmp{first};
            first = first->next;
            delete tmp;
            size--;
        }
        else //Rest of cases
        {
            currentNode = first;
            for (int i{0}; i<index; i++){
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
        for (int i{0}; i < getSize(); i++) {
            if (currentNode->value >= value) { //Case of adding a new first node
                if (i == 0) {
                    first = tmp;
                }
                else {
                    prevNode->next = tmp;
                }
                tmp->next = currentNode;
                size++;
                break;
            } else {
                if (i == getSize() - 1){
                    tmp->next = nullptr;
                    currentNode->next = tmp;
                    size++;
                    break;
                }
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }

}// inserts a node in sorted order
bool sortedList::isEmpty() const{
    return size == 0;
} //checks if a list is empty

std::string sortedList::printList() const{
    Node* currentNode = first;
    std::string currentPrint = "[";
    int position = 0;

    if (size == 0){
        return "[NULL]";
    }

    return doPrintList(currentNode, currentPrint, position);
} //prints the existing nodes
std::string sortedList::doPrintList(Node* currentNode = nullptr, std::string currentPrint = "[", int position = 0) const{
    if (position == getSize() - 1){
        return currentPrint + std::to_string(currentNode->value) + " --> NULL]";
    } else {
        currentPrint += std::to_string(currentNode->value) + " --> ";
        return doPrintList(currentNode->next, currentPrint, position + 1);
    }
}

int sortedList::getSize() const{
    return size;
} //gets size of the list
void sortedList::deepCopy(sortedList const& other) {
    this->size = other.size;
    Node* currentNode{other.first};
    for (int i{0}; i<other.size; i++)
    {
        Node *tmp{new Node{currentNode->value}};
        if (i==0){
            first = tmp;
        } else {
            first->next = tmp;
        }
        currentNode = currentNode->next;
    }
} //performs a deep copy of the list
void sortedList::move(sortedList& other){
    this->first = other.first;
    this->size = other.size;
    other.size=0;
    other.first = nullptr;
} // moves content from other to this object