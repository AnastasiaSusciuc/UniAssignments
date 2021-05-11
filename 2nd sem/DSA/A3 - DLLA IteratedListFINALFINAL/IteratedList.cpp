#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList()
// theta(1)
{
    this->buffer = new node*[10];
    this->capacity = 10;
    this->free_slots = nullptr;
    this->no_of_elements = 0;
    this->head_pos = -1;
    this->tail_pos = -1;
    this->buffer_last = 0;
}

int IteratedList::size() const
// theta(1)
{
    return no_of_elements;
}

bool IteratedList::isEmpty() const
// theta(1)
{
    return (this->no_of_elements==0);
}

ListIterator IteratedList::first() const
// theta(1)
{
    ListIterator iterator(*this);
	return iterator;
}

TElem IteratedList::getElement(ListIterator pos) const
// theta(1)
{
    if(!pos.valid())
        throw std::exception();
    else
    {
        int index = pos.get_position();
        return this->buffer[index]->data;
    }
}

TElem IteratedList::remove(ListIterator& pos)
// theta(1)
{
    if(!pos.valid())
        throw std::exception();
    else
    {
        int current = pos.get_position();
        pos.next();
        this->no_of_elements--;
        auto *removed = this->buffer[current];
        if(removed->previous != -1)  // if the removed node wasn't the head, we have te reset the previous' next
            this->buffer[removed->previous]->next = removed->next;

        if(removed->next != -1) // if the removed node wasn't the tail, we have to reset the next's previous
            this->buffer[removed->next]->previous = removed->previous;

        if (current == this->head_pos) this->head_pos = removed->next; // if the removed node was the head, we update the position of the new head

        if (current == this->tail_pos) this->tail_pos = removed->previous; // if the removed node was the tail, we update the position of the new tail

        auto *new_freeslot = new freeslots_node; // we save the position of the removed node as an unoccupied position (for later use)

        new_freeslot->position = current;
        new_freeslot->next = this->free_slots;

        this->free_slots = new_freeslot;
        this->buffer[current] = nullptr; // lastly we mark the position in the vector with null

        TElem e = removed->data;
        delete removed; // and free the memory
        return e;
    }
}

ListIterator IteratedList::search(TElem e) const
// best case: theta(1)
// worst case: theta(number_elements)
// total complexity: O(number_elements)
{
    ListIterator it (*this);

    while (it.valid() && it.getCurrent() != e)
        it.next();

	return it;
}

TElem IteratedList::setElement(ListIterator pos, TElem e)
// theta(1)
{
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

void IteratedList::addToPosition(ListIterator& pos, TElem e)
// best case: theta(1)
// worst case: theta(capacity)
// average: O(1) amortized
// total complexity: O(number_elements)
{
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

void IteratedList::addToBeginning(TElem e)
// best case: theta(1)
// worst case: theta(capacity)
// average: O(1) amortized
// total complexity: O(number_elements)
{
    if (this->no_of_elements)
    {
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

void IteratedList::addToEnd(TElem e)
// best case: theta(1)
// worst case: theta(capacity)
// average: theta(1) amortized
// total complexity: O(number_elements)
{
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

IteratedList::~IteratedList() = default;

int IteratedList::allocator()
// best case: theta(1)
// worst case:  theta(capacity) - when resize is necessary
// total complexity: O(1) amortized
{
    int position;
    if(this->free_slots){
        position = free_slots->position;
        freeslots_node* old = free_slots;
        free_slots = free_slots->next;
        delete old;
    }
    else
    {
        if(this->buffer_last>=this->capacity)
            this->resize();
        position = this->buffer_last;
        this->buffer_last++;
    }
    return position;
}

void IteratedList::resize()
// theta(capacity)
{
    node** new_buffer = new node* [2*this->capacity];
    for(int i =0; i < this->capacity; i++)
        new_buffer[i] = this->buffer[i];

    this->capacity*=2;
    node** old_buffer = this->buffer;
    this->buffer = new_buffer;
    delete[] old_buffer;
}

void IteratedList::removeBetween(ListIterator &start, ListIterator &end)
// best case: theta(1) - when iterators are not valid
// worst case: theta(number_elements) - when all elements need to be removed
// total complexity: O(number_elements)
{
    if(!start.valid() || !end.valid())
        throw std::exception();
    else
    {
        int finish = end.get_position();

        while (start.valid() && start.get_position() != finish)
            this->remove(start);

        if (start.valid())
            this->remove(start);
    }
}
