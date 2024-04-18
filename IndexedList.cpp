#include <exception>
#include <iostream>

#include "IndexedList.h"
#include "ListIterator.h"

using std::cout;



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

void DLLANode::operator=(DLLANode const& second){
    this->info = second.info;
    this->next = second.next;
    this->prev = second.prev;
}

void IndexedList::set(int pos, TElem info, int next, int prev){
    this->nodes[pos].info = info;
    this->nodes[pos].next = next;
    this->nodes[pos].prev = prev;
}

IndexedList::IndexedList() {
	//TODO - Implementation
    this->capacity = 4;
    this->listSize = 0;
    this->nodes = new DLLANode[this->capacity];
    this->head = -1;
    this->tail = -1;
    //Init the next array in the nodes
    for(int i = 0; i < this->capacity; ++i){
        this->set(i, 0, i+1, i-1);
    }
    //Set the last element of the Array on -1
    this->nodes[this->capacity-1].next = -1;
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
        this->firstEmpty = this->nodes[firstEmpty].next;

        //add the value;
        this->nodes[where].info = e;
        this->nodes[where].next = -1;
        this->nodes[where].prev = -1;
        //set the head and the tail
        this->head = this->tail = where;
        this->listSize = 1;
        return;
    }
    //resize
    if(this->listSize >= this->capacity-1){
        int newCap = this->capacity * 2;
        DLLANode* newArr = new DLLANode[newCap];
        //copy the old nodes
        for(int i = 0; i < this->capacity;++i){
            newArr[i].info = this->nodes[i].info;
            newArr[i].next = this->nodes[i].next;
            newArr[i].prev = this->nodes[i].prev;
        }
        //init the new part added
        for(int i = this->capacity; i < newCap; ++i){
            newArr[i].next = i+1;
            newArr[i].prev = i-1;
            newArr[i].info = 0;
        }
        //the last next must be -1
        this->firstEmpty = this->capacity;
        this->capacity = newCap;
        delete[] this->nodes;
        this->nodes = newArr;
    }
    
    //Normally add the node to the end
    int where = this->firstEmpty;
    this->firstEmpty = this->nodes[this->firstEmpty].next;
    this->nodes[where].info = e;
    this->nodes[where].prev = this->tail;
    this->nodes[this->tail].next = where;
    this->nodes[where].next = -1;
    this->tail = where;
    this->listSize++;
    return;
    
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
        cout << this->nodes[currentIndex].info<< " ";
        if(e == this->nodes[currentIndex].info){
            return 1;
        }
        currentIndex = this->nodes[currentIndex].next;
    }
   
	return 0;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}

IndexedList::~IndexedList() {
	//TODO - Implementation
    delete[] this->nodes;
}