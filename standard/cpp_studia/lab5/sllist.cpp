#include "sllist.h"
#include <cstring>
#include <iostream>

using namespace std;

std::ostream &operator<<(std::ostream &os, const sllist &list)
{

    // Note that I removed the identifier of the second parameter to avoid
    // compiler warning. You'll need it to iterateo over the nodes in list.

    os << '{';
    sllist::slnode *curr = (sllist::slnode *)list.get_first();
    while (curr)
    {
        os << "[" << curr->get_value() << " " << curr->get_count() << "] ";

        curr = curr->get_next();
    }

    // here you should send to os all slnodes in the lst
    return os << "}";
}

std::ostream &operator<<(std::ostream &os, const sllist::slnode &node)
{
    os << '[';
    os << node.get_value() << " " << node.get_count();

    // here you should send to os all slnodes in the lst
    return os << "]";
}

sllist::slnode *&sllist::find_ble(const char *val)
{
    if (pHead == nullptr || strcmp(pHead->get_value(), val) >= 0)
        return pHead;

    sllist::slnode *curr = pHead;
    while (curr->get_next() != nullptr && strcmp(curr->get_next()->get_value(), val) < 0)
    {
        curr = curr->get_next();
    }
    return curr->next;
}

sllist::slnode::slnode(const char *name, unsigned int count, sllist::slnode *nxt)
{
    this->value = new char[strlen(name) + 1];
    strcpy(this->value, name);
    this->count = count;
    this->next = nxt;
}

sllist::slnode::~slnode()
{
    delete[] this->value;
}

unsigned int sllist::slnode::operator++(int)
{
    return this->count++;
}

unsigned int sllist::slnode::operator+=(unsigned int cnt)
{
    this->count += cnt;
    return this->count;
}

void sllist::slnode::set_next(sllist::slnode *new_next)
{
    this->next = new_next;
}

const char *sllist::slnode::get_value() const
{
    return this->value;
}

unsigned int sllist::slnode::get_count() const
{
    return this->count;
}

sllist::slnode *sllist::slnode::get_next() const
{
    return next;
}

sllist::sllist(const sllist &src)
{
    if (src.empty())
        return;

    auto srcCurr = src.get_first();

    int initialSize = src.size();

    for (int i = 0; i < initialSize; i++)
    {
        this->add_pair(srcCurr->get_value(), srcCurr->get_count());

        srcCurr = srcCurr->get_next();
    }
}

bool sllist::empty() const
{
    return pHead == nullptr;
}

unsigned int sllist::size() const
{
    int count = 0;
    for (const slnode *pcur = pHead; pcur != nullptr; pcur = pcur->get_next())
        ++count;
    return count;
}

const sllist::slnode *sllist::get_first() const
{
    return pHead;
}

sllist::~sllist()
{
    clear();
}

void sllist::clear()
{
    sllist::slnode *curr = pHead;

    while (curr)
    {
        sllist::slnode *nextElem = curr->get_next();

        delete curr;

        curr = nextElem;
    }
}

sllist &sllist::operator=(const sllist &src)
{
    sllist::slnode *outerHead = (sllist::slnode *)src.get_first();
    if (!outerHead)
        return *this;

    sllist::slnode *newCurr = pHead;
    sllist::slnode *curr = outerHead;
    sllist::slnode *prev = nullptr;

    while (curr)
    {
        newCurr = new sllist::slnode(curr->get_value(), curr->get_count(), nullptr);
        if (!pHead)
            pHead = newCurr;
        if (prev)
            prev->set_next(newCurr);

        curr = curr->get_next();

        prev = newCurr;
        newCurr = newCurr->get_next();
    }

    return *this;
}

sllist &sllist::operator+=(const sllist &src)
{
    if (src.empty())
        return *this;

    auto srcCurr = src.get_first();

    int initialSize = src.size();

    for (int i = 0; i < initialSize; i++)
    {
        this->add_pair(srcCurr->get_value(), srcCurr->get_count());

        srcCurr = srcCurr->get_next();
    }

    return *this;
}

bool sllist::exists(const char *name) const
{
    auto curr = pHead;
    while (curr)
    {
        if (!strcmp(name, curr->get_value()))
            return true;
    }

    return false;
}

const sllist::slnode *sllist::add_pair(const char *val, unsigned int cnt)
{
    // if exists
    auto curr = pHead;
    while (curr)
    {
        if (!strcmp(val, curr->get_value()))
        {
            (*curr) += cnt;
            return curr;
        }
        curr = curr->get_next();
    }

    // does not exist

    slnode *&prev = find_ble(val);
    prev = new slnode(val, cnt, prev);

    return prev;
}

sllist::slnode *findElem(sllist list, const char *val)
{
    auto curr = (sllist::slnode *)list.get_first();
    while (curr)
    {
        if (!strcmp(val, curr->get_value()))
            return curr;

        curr = curr->get_next();
    }

    return nullptr;
}

unsigned int &sllist::operator[](const char *val)
{
    auto elem = (sllist::slnode *)add_pair(val);

    return elem->count;
}

unsigned int sllist::operator[](const char *val) const
{
    auto elem = findElem(*this, val);
    return !elem ? 0 : elem->count;
}