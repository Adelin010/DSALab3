#include <exception>

#include "IndexedList.h"
#include "ListIterator.h"


DLLANode::DLLANode(){
    this->info = -1;
    this->next = -1;
    this->prev = -1;
}

DLLANode::DLLANode(int info, int next, int prev){
    this->next = next;
    this->prev = prev;
    this->info = info;
}

IndexedList::IndexedList() {
	//TODO - Implementation
    this->capacity = 4;
    this->listSize = 0;
    this->nodes = new DLLANode*[this->capacity];
    this->head = -1;
    this->tail = -1;
    //Init the next array in the nodes
    for(int i = 0; i < this->capacity; ++i){
        this->nodes[i] = new DLLANode(0, i+1, -1);
    }
    //Set the last element of the Array on -1
    this->nodes[this->capacity-1]->next = -1;
    this->firstEmpty = 0;
}

int IndexedList::size() const {
    //TODO - Implementation
	return this->listSize;
}


bool IndexedList::isEmpty() const {
    //TODO - Implementation
	return this->listSize == 0;
}

TElem IndexedList::getElement(int pos) const {
    //TODO - Implementation
	return NULL_TELEM;
}

TElem IndexedList::setElement(int pos, TElem e) {
    //TODO - Implementation
	return NULL_TELEM;
}

void IndexedList::addToEnd(TElem e) {
    //TODO - Implementation
    //No elements inside
    if(this->head == -1){
        int where = this->firstEmpty;
        //Add the element
        this->nodes[where]->info = e;
        //change the position of the first empty Elem
        this->firstEmpty = this->nodes[where]->next;
        //because there is only one node in the list both next & prev are -1
        this->nodes[where]->next = -1;
        this->nodes[where]->prev = -1;
        // HEAD-UL & TAIL-UL become the added node position
        this->head = where;
        this->tail = where;
        //increment the size
        this->listSize++;
        return;
    }

    if(this->firstEmpty != -1){
        //position where to add the new node
        int where = this->firstEmpty;
        //change the firstEmpty to the next empty position
        this->firstEmpty = this->nodes[where]->next;
        //add the element in the array
        this->nodes[where]->info = e;
        //link the tail with the node
        this->nodes[this->tail]->next = where;
        this->nodes[where]->prev = this->tail;
        this->nodes[where]->next = -1;
        //move the tail to the new node
        this->tail = where;
        //increment the size
        this->listSize++;
        return;
    }

    //Resizing implementation for later
    
}

void IndexedList::addToPosition(int pos, TElem e) {
    //TODO - Implementation
}

TElem IndexedList::remove(int pos) {
    //TODO - Implementation
	return NULL_TELEM;
}

int IndexedList::search(TElem e) const{
    //TODO - Implementation
    int currentIndex = this->head;
    while(currentIndex != -1){
        if(e == this->nodes[currentIndex]->info){
            return 1;
        }
        currentIndex = this->nodes[currentIndex]->next;
    }
	return 0;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}

IndexedList::~IndexedList() {
	//TODO - Implementation
}