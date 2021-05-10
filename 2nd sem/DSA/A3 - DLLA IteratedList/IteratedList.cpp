
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList()
// theta(MAX_CAP)
{
    this->buffer = new DLLANode*[10];
    this->capacity = 10;
    this->first_empty = nullptr;
    this->_size = 0;
    this->head = -1;
    this->tail = -1;
    this->buffer_last = 0;
}

int IteratedList::size() const {
	return this->_size;
}

bool IteratedList::isEmpty() const {
	return (this->_size == 0);
}

ListIterator IteratedList::first() const {
    ListIterator it(*this);
    return it;
}

TElem IteratedList::getElement(ListIterator pos) const {
    return pos.getCurrent();
}

TElem IteratedList::remove(ListIterator& pos) {
	int position = pos.get_position();

    if(position < 0 or position >= this->_size)
        throw std::exception();
    else
    {
        int curr = this->head;
        for (int i = 0; i < position; i++ )
            curr = this->buffer[curr]->next;

        // this->buffer[curr]->info;
        this->_size--;
        auto *removed = this->buffer[curr];
        if(removed->prev != -1) //if the removed node wasn't the head, we have te reset the previous's next
            this->buffer[removed->prev]->next = removed->next;
        if(removed->next != -1) //if the removed node wasn't the tail, we have to reset the next's previous
            this->buffer[removed->next]->prev = removed->prev;

        if (curr == this->head) this->head = removed->next; //if the removed node was the head, we update the position of the new head
        if (curr == this->tail) this->tail = removed->prev; //if the removed node was the tail, we update the position of the new tail
        auto *new_freeslot = new freeSlotsNode; //we save the position os the removed node as an unoccupied position (for later use)
        new_freeslot->pos = curr;
        new_freeslot->next = this->first_empty;
        this->first_empty = new_freeslot;
        this->buffer[curr] = nullptr; //lastly we mark the position in the vector with null
        TElem e = removed->info;
        delete removed; //and free the memory
        return e;
    }
}

ListIterator IteratedList::search(TElem e) const{
    ListIterator it(*this);
    while (it.valid())
    {
        if (it.getCurrent() == e)
            return it;

        it.next();
    }
    return it;
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
    int position = pos.get_position();

    if(position < 0 or position >= this->_size)
        throw std::exception();
    else
    {
        int curr = this->head;
        for (int i = 0; i < position; i++)
            curr = this->buffer[curr]->next;

        TElem old = this->buffer[curr]->info;
        this->buffer[curr]->info = e;
        return old;
    }
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    if(this->_size){
        auto* x = new DLLANode();
        x->info=e;
        int position = this->allocate();
        this->buffer[position]=x;
        x->next = -1;
        x->prev = this->tail;
        this->buffer[this->tail]->next = position;
        this->tail = position;
        this->_size++;
    }
    else
    {
        auto* x = new DLLANode();
        x->info=e;
        this->buffer[this->buffer_last++]=x;
        x->next = -1;
        x->prev = -1;
        this->head=0;
        this->tail=0;
        this->_size=1;
    }
}

void IteratedList::addToEnd(TElem e) {
    if(this->_size){
        auto* x = new DLLANode();
        x->info = e;
        int position = this->allocate();
        this->buffer[position]=x;
        x->next = -1;
        x->prev = this->tail;
        this->buffer[this->tail]->next = position;
        this->tail = position;
        this->_size++;
    }
    else{
        auto* x = new DLLANode();
        x->info=e;
        this->buffer[this->buffer_last++]=x;
        x->next = -1;
        x->prev = -1;
        this->head = 0;
        this->tail = 0;
        this->_size = 1;
    }
}

IteratedList::~IteratedList() {
	//TODO - Implementation
}

void IteratedList::addToBeginning(TElem e) {

}

int IteratedList::allocate() {
    int position;
    if (this->first_empty){
        position = first_empty->pos;
        freeSlotsNode* old = first_empty;
        first_empty = first_empty->next;
        delete old;
    }
    else{
        if (this->buffer_last >= this->capacity)
            this->resize();
        position = this->buffer_last;
        this->buffer_last++;
    }
    return position;
}

void IteratedList::resize() {
    auto ** new_buffer = new DLLANode* [2*this->capacity];

    for (int i =0; i < this->capacity; i++)
        new_buffer[i] = this->buffer[i];
    this->capacity*=2;
    DLLANode** old_buffer = this->buffer;
    this->buffer = new_buffer;
    delete[] old_buffer;
}
