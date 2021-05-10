
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList() {
    this->buffer = new node*[10];
    this->capacity=10;
    this->free_slots=NULL;
    this->no_of_elements=0;
    this->head_pos=-1;
    this->tail_pos=-1;
    this->buffer_last=0;
}

int IteratedList::size() const {
    return no_of_elements;
}

bool IteratedList::isEmpty() const {
    return (this->no_of_elements==0);
}

ListIterator IteratedList::first() const {
    ListIterator iterator(*this);
	return iterator;
}

TElem IteratedList::getElement(ListIterator pos) const {
    if(!pos.valid())
        throw std::exception();
    else
    {
        int index = pos.get_position();
        return this->buffer[index]->data;
    }
}

TElem IteratedList::remove(ListIterator& pos) {
    if(!pos.valid())
        throw std::exception();
    else
    {
        int current = pos.get_position();
        this->no_of_elements--;
        auto *removed = this->buffer[current];
        if(removed->previous != -1)  //if the removed node wasn't the head, we have te reset the previous's next
            this->buffer[removed->previous]->next = removed->next;
        if(removed->next != -1) //if the removed node wasn't the tail, we have to reset the next's previous
            this->buffer[removed->next]->previous = removed->previous;
        if (current == this->head_pos) this->head_pos = removed->next; //if the removed node was the head, we update the position of the new head
        if (current == this->tail_pos) this->tail_pos = removed->previous; //if the removed node was the tail, we update the position of the new tail
        auto *new_freeslot = new freeslots_node; //we save the position os the removed node as an unocupied position (for later use)
        new_freeslot->position = current;
        new_freeslot->next = this->free_slots;
        this->free_slots = new_freeslot;
        this->buffer[current] = NULL; //lastly we mark the position in the vector with null
        TElem e = removed->data;
        delete removed; //and free the memory
        return e;
    }
}

ListIterator IteratedList::search(TElem e) const{

    ListIterator it (*this);

    while (it.valid() && it.getCurrent() != e)
        it.next();

	return it;
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
    if (!pos.valid())
        throw std::exception();
    else
    {
        int index = pos.get_position();
        TElem old = this->buffer[index]->data;
        this->buffer[index]->data = e;
        return old;
    }
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    if (!pos.valid())
        throw std::exception();
    else
    {
        int current = this->buffer[pos.get_position()]->next;
        int previous = pos.get_position();
        auto* x = new node();
        x->data = e;
        int position = this->allocator();
        this->buffer[position] = x;
        if(previous == -1) // x is the new head
        {
            x->previous = -1;
            x->next = this->head_pos;
            this->buffer[this->head_pos]->previous = position;
            this->head_pos = position;
        }
        else if(current == -1) // x is the new tail
        {
            x->next = -1;
            x->previous = this->tail_pos;
            this->buffer[this->tail_pos]->next = position;
            this->tail_pos = position;
        }
        else
        {
            x->next = current;
            x->previous = previous;
            this->buffer[previous]->next = position;
            this->buffer[current]->previous = position;
        }
        this->no_of_elements++;
        pos.next();
    }
}

void IteratedList::addToBeginning(TElem e) {
    if (this->no_of_elements){
        auto* x = new node();
        x->data = e;
        int position = this->allocator();
        this->buffer[position] = x;
        x->next = this->head_pos;
        x->previous = -1;
        this->buffer[this->head_pos]->previous = position;
        this->head_pos = position;
        this->no_of_elements++;
    }
    else
    {
        auto* x = new node();
        x->data = e;
        this->buffer[this->buffer_last++] = x;
        x->next = -1;
        x->previous = -1;
        this->head_pos = 0;
        this->tail_pos = 0;
        this->no_of_elements = 1;
    }
}

void IteratedList::addToEnd(TElem e) {

    int position = this->allocator();

    if (this->no_of_elements){
        auto* x = new node();
        x->data = e;
        // int position = this->allocator();
        this->buffer[position] = x;
        x->next = -1;
        x->previous = this->tail_pos;
        this->buffer[this->tail_pos]->next = position;
        this->tail_pos = position;
        this->no_of_elements++;
    }
    else{
        auto* x = new node();
        x->data = e;
        this->buffer[position] = x;
        x->next = -1;
        x->previous = -1;
        this->head_pos = 0;
        this->tail_pos = 0;
        this->no_of_elements = 1;
    }
}

IteratedList::~IteratedList() {
	// todo
}

int IteratedList::allocator() {
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

void IteratedList::resize() {
    node ** new_buffer = new node*[2*this->capacity];
    for(int i =0; i<this->capacity; i++)
        new_buffer[i] = this->buffer[i];
    this->capacity*=2;
    node** old_buffer = this->buffer;
    this->buffer = new_buffer;
    delete[] old_buffer;
}
