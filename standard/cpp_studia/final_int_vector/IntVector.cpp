#include "IntVector.h"
#include <stdexcept>
#include <iostream>

int IntVector::operator[](int ind)
{
    if (ind < 0 || ind >= size())
        throw std::runtime_error("IntVector: Index out of bounds");

    return this->at(ind);
}

int IntVector::at(int ind) const
{
    int index = 0;
    Node *curr = pHead;
    while (curr)
    {
        if (index == ind)
            return curr->val;

        curr = curr->next;
        index++;
    }

    return -1;
}

int IntVector::size() const
{
    int size = 0;
    Node *curr = pHead;
    while (curr)
    {
        size++;
        curr = curr->next;
    }

    return size;
}

int StringIntVector::operator[](std::string s)
{
    int len = s.length();

    if (len < 0 || len >= size())
        throw std::runtime_error("IntVector: Index out of bounds");

    return this->at(len);
}