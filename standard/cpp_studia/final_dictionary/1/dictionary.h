#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>

template <typename T, typename Y>
struct DictionaryItem
{
    T first;
    Y second;
    DictionaryItem<T, Y> *next = nullptr;

    DictionaryItem(T f, Y s, DictionaryItem<T, Y> *newNext = nullptr)
        : first(f), second(s), next(newNext) {}
};

template <typename T, typename Y>
class Dictionary
{
public:
    friend std::ostream &operator<<(std::ostream &os, const Dictionary<T, Y> &dict)
    {
        DictionaryItem<T, Y> *current = dict.pHead;
        os << "{ ";
        while (current)
        {
            os << "(" << current->first << ", " << current->second << ")";
            current = current->next;
            if (current)
            {
                os << ", ";
            }
        }
        os << " }";
        return os;
    }

    Dictionary &operator=(const Dictionary<T, Y> &otherDict)
    {
        if (otherDict.pHead == pHead || !otherDict.pHead)
            return *this;

        DictionaryItem<T, Y> curr = new DictionaryItem<T, Y>(otherDict.pHead->first, otherDict.pHead->second);
        DictionaryItem<T, Y> externalCurr = otherDict.pHead->next;

        while (curr)
        {
            curr->next = new DictionaryItem<T, Y>(externalCurr.first, externalCurr.second);

            curr = curr->next;
            externalCurr = externalCurr->next;
        }

        return *this;
    }

    DictionaryItem<T, Y> *pHead = nullptr;

private:
};

#endif // DICTIONARY_H
