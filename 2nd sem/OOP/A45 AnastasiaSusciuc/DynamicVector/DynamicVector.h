//
// Created by susci on 3/20/2021.
//

#ifndef OOP_DYNAMICVECTOR_H
#define OOP_DYNAMICVECTOR_H
#pragma once

#include <stdexcept>
#include "../Domain/tutorial.h"

typedef Tutorial TElem;


template <typename TElem>

class DynamicVector{

private:
    TElem* elements_list;
    int size_vector;
    int capacity_vector;

public:
    explicit DynamicVector(int capacity = 5);

    ~DynamicVector();
    void resize_dynamic_vector();
    int search_element(const TElem& element);
    void append(TElem element);
    void remove(const TElem& element);
    void update(const TElem& old_element, const TElem& new_element);
    TElem& operator[](int position) const;
    int size() const;
    int capacity();
    DynamicVector& operator=(const DynamicVector& vector);
};


template<typename TElem>
DynamicVector<TElem>::DynamicVector(int capacity) {
    capacity_vector = capacity;
    size_vector = 0;
    elements_list = new TElem[capacity];
}

template<typename TElem>
DynamicVector<TElem>::~DynamicVector() {
    delete[] elements_list;
}

template<typename TElem>
void DynamicVector<TElem>::resize_dynamic_vector() {

    auto* new_list = new TElem[capacity_vector*2];
    for (int i = 0; i < size_vector; i++)
        new_list[i] = elements_list[i];

    capacity_vector *= 2;
    delete[] elements_list;
    elements_list = new_list;
}

template<typename TElem>
int DynamicVector<TElem>::search_element(const TElem &element) {
    for (int i = 0; i < size_vector; i++) {
        if (elements_list[i] == element)
            return i;
    }
    return -1;
}

template<typename TElem>
void DynamicVector<TElem>::append(TElem element) {
    if (size_vector == capacity_vector)
        resize_dynamic_vector();
    elements_list[size_vector++] = element;
}

template<typename TElem>
void DynamicVector<TElem>::remove(const TElem &element) {

    int position = search_element(element);
    if (position != -1) {
        for (int i = position; i < size_vector - 1; ++i) {
            elements_list[i] = elements_list[i + 1];
        }
        --size_vector;
    }
}

template<typename TElem>
void DynamicVector<TElem>::update(const TElem &old_element, const TElem &new_element) {
    int position = search_element(old_element);
    if (position != -1) {
        elements_list[position] = new_element;
    }
}

template<typename TElem>
TElem &DynamicVector<TElem>::operator[](int position) const{
    if (position < 0 || position >= size_vector)
        throw std::runtime_error("Invalid position");
    return elements_list[position];
}

template<typename TElem>
inline int DynamicVector<TElem>::size() const{
    return size_vector;
}

template<typename TElem>
inline int DynamicVector<TElem>::capacity() {
    return capacity_vector;
}

template<typename TElem>
DynamicVector<TElem>& DynamicVector<TElem>::operator=(const DynamicVector& vectorUsed){
    if (this != &vectorUsed) {
        if (capacity_vector < vectorUsed.size_vector) {
            delete[] elements_list;
            elements_list = new TElem[vectorUsed.capacityOfVector];
        }
        size_vector = vectorUsed.size_vector;
        capacity_vector = vectorUsed.capacityOfVector;
        for (int i = 0; i < size_vector; ++i)
            elements_list[i] = vectorUsed.elementsList[i];
    }
    return *this;
}

#endif //OOP_DYNAMICVECTOR_H
