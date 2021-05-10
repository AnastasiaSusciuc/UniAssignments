#include <exception>

#include "IndexedList.h"
#include "ListIterator.h"

IndexedList::IndexedList() {
    this->buffer = new node*[10];
    this->capacity=10;
    this->free_slots=NULL;
    this->no_of_elements=0;
    this->head_pos=-1;
    this->tail_pos=-1;
    this->buffer_last=0;
}

int IndexedList::allocator(){
    int position;
    if(this->free_slots){
        position = free_slots->position;
        freeslots_node* old = free_slots;
        free_slots = free_slots->next;
        delete old;
    }
    else{
        if(this->buffer_last>=this->capacity)
            this->resize();
        position = this->buffer_last;
        this->buffer_last++;
    }
    return position;
}

void IndexedList::resize() {
    node ** new_buffer = new node*[2*this->capacity];
    for(int i =0; i<this->capacity; i++)
        new_buffer[i] = this->buffer[i];
    this->capacity*=2;
    node** old_buffer = this->buffer;
    this->buffer = new_buffer;
    delete[] old_buffer;
}

int IndexedList::size() const {
    return no_of_elements;
}


bool IndexedList::isEmpty() const {
    return (this->no_of_elements==0);
}

TElem IndexedList::getElement(int pos) const {
    if(pos<0 or pos>=this->no_of_elements)
        throw std::exception();
    else{
        int curr=this->head_pos;
        for(int i=0; i<pos; ++i){
            curr=this->buffer[curr]->next;
        }
        return this->buffer[curr]->data;
    }
}

TElem IndexedList::setElement(int pos, TElem e) {
    if(pos<0 or pos>=this->no_of_elements)
        throw std::exception();
    else{
        int curr=this->head_pos;
        for(int i=0; i<pos; ++i){
            curr=this->buffer[curr]->next;
        }
        TElem old = this->buffer[curr]->data;
        this->buffer[curr]->data = e;
        return old;
    }
}

void IndexedList::addToEnd(TElem e) {
    if(this->no_of_elements){
        auto* x = new node();
        x->data=e;
        int position = this->allocator();
        this->buffer[position]=x;
        x->next = -1;
        x->previous = this->tail_pos;
        this->buffer[this->tail_pos]->next = position;
        this->tail_pos = position;
        this->no_of_elements++;
    }
    else{
        auto* x = new node();
        x->data=e;
        this->buffer[this->buffer_last++]=x;
        x->next = -1;
        x->previous = -1;
        this->head_pos=0;
        this->tail_pos=0;
        this->no_of_elements=1;
    }
}

void IndexedList::addToPosition(int pos, TElem e) {
    if(pos<0 or pos>=this->no_of_elements)
        throw std::exception();
    else{
        int curr=this->head_pos;
        int prev = -1;
        for(int i=0; i<pos; ++i){
            prev = curr;
            curr=this->buffer[curr]->next;
        }
        auto* x = new node();
        x->data = e;
        int position = this->allocator();
        this->buffer[position]=x;
        if(prev == -1){ //x is the new head
            x->previous = -1;
            x->next = this->head_pos;
            this->buffer[this->head_pos]->previous = position;
            this->head_pos = position;
        }
        else if(curr == -1){///x is the new tail
            x->next = -1;
            x->previous = this->tail_pos;
            this->buffer[this->tail_pos]->next = position;
            this->tail_pos = position;
        }
        else{
            x->next = curr;
            x->previous = prev;
            this->buffer[prev]->next = position;
            this->buffer[curr]->previous = position;
        }
        this->no_of_elements++;
    }
}


TElem IndexedList::remove(int pos) {
    if(pos<0 or pos>=this->no_of_elements)
        throw std::exception();
    else{
        int curr=this->head_pos;
        for(int i=0; i<pos; ++i){
            curr=this->buffer[curr]->next;
        }
        this->buffer[curr]->data;
        this->no_of_elements--;
        auto *removed = this->buffer[curr];
        if(removed->previous != -1)///if the removed node wasn't the head, we have te reset the previous's next
            this->buffer[removed->previous]->next = removed->next;
        if(removed->next != -1)///if the removed node wasn't the tail, we have to reset the next's previous
            this->buffer[removed->next]->previous = removed->previous;
        if (curr == this->head_pos) this->head_pos = removed->next;///if the removed node was the head, we update the position of the new head
        if (curr == this->tail_pos) this->tail_pos = removed->previous;///if the removed node was the tail, we update the position of the new tail
        auto *new_freeslot = new freeslots_node; ///we save the position os the removed node as an unocupied position (for later use)
        new_freeslot->position = curr;
        new_freeslot->next = this->free_slots;
        this->free_slots = new_freeslot;
        this->buffer[curr] = NULL; ///lastly we mark the position in the vector with null
        TElem e = removed->data;
        delete removed;///and free the memory
        return e;
    }
}

int IndexedList::search(TElem e) const{
    int x = this->head_pos;
    int pos=0;
    while(x!=-1 and this->buffer[x]->data != e){
        x=this->buffer[x]->next;
        ++pos;
    }
    if(x!=-1)
        return pos;
    else return -1;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}

IndexedList::~IndexedList() {
	//TODO - Implementation
}