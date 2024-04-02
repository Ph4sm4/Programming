#include "sllist.h"
#include <iostream>
using namespace std;

sllist::slnode::slnode(int val, slnode *nxt)
    : value(val), next(nxt)
{
}

sllist::sllist(const sllist &src)
{
    copy_elements(src);
}

void sllist::slnode::set_next(slnode *new_next)
{
    this->next = new_next;
}

int sllist::slnode::get_val() const
{
    return this->value;
}

int &sllist::slnode::get_val()
{
    return this->value;
}

sllist::slnode *sllist::slnode::get_next() const
{
    return next;
}

bool sllist::empty() const
{
    return pHead == nullptr;
}

int sllist::size() const
{
    int count = 0;
    for (const slnode *pcur = pHead; pcur != nullptr; pcur = pcur->get_next())
        ++count;
    return count;
}

sllist::slnode *sllist::get_first() const
{
    return pHead;
}

sllist::slnode *&sllist::find_ble(int val)
{
    if (pHead == nullptr || pHead->get_val() >= val)
        return pHead;

    slnode *curr = pHead;
    while (curr->get_next() != nullptr && curr->get_next()->get_val() < val)
    {
        curr = curr->next;
    }
    return curr->next;
}

sllist::slnode *sllist::insert(int val)
{
    slnode *&prev = find_ble(val);
    prev = new slnode(val, prev);
    return prev;
}

sllist::~sllist()
{
    sllist::slnode *curr = pHead;

    while (curr)
    {
        sllist::slnode *nextElem = curr->get_next();

        delete curr;

        curr = nextElem;
    }
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
    pHead = nullptr;
}

sllist::slnode *sllist::copy_elements(const sllist &src)
{
    sllist::slnode *outerHead = src.get_first();
    if (!outerHead)
        return nullptr;

    pHead = new sllist::slnode(outerHead->get_val(), nullptr);
    sllist::slnode *newCurr = pHead;
    sllist::slnode *curr = outerHead;

    while (curr)
    {
        newCurr->value = curr->get_val();
        newCurr->set_next(curr->get_next());

        curr = curr->get_next();
        newCurr = newCurr->get_next();
    }

    return pHead;
}

sllist &sllist::operator=(const sllist &src)
{
    copy_elements(src);

    return *this;
}

sllist &sllist::operator+=(const sllist &src)
{
    if (src.empty())
        return *this;

    auto lastElem = pHead;
    while (lastElem)
    {
        if (lastElem->get_next())
            lastElem = lastElem->get_next();
        else
            break;
    }

    auto srcCurr = src.get_first();

    int initialSize = src.size();

    for (int i = 0; i < initialSize; i++)
    {
        const auto elem = new sllist::slnode(srcCurr->get_val(), nullptr);
        lastElem->set_next(elem);

        lastElem = lastElem->get_next();
        srcCurr = srcCurr->get_next();
    }

    return *this;
}

void sllist::push_front(int val)
{
    if (empty())
    {
        pHead = new sllist::slnode(val, nullptr);
        return;
    }
    sllist::slnode *oldPhead = new sllist::slnode(pHead->get_val(), pHead->get_next());
    sllist::slnode *newElem = new sllist::slnode(val, oldPhead);

    pHead = newElem;
}

int sllist::pop_front()
{
    if (empty())
        return 0;

    int val = pHead->get_val();
    sllist::slnode *nextPhead = pHead->get_next();

    delete pHead;

    pHead = nextPhead;

    return val;
}

void print_list(const sllist &lst)
{
    sllist::slnode *curr = lst.get_first();
    cout << "[";
    int ind = 1;
    while (curr)
    {
        cout << curr->get_val();
        if (ind < lst.size())
        {
            cout << ", ";
        }
        ind++;
        curr = curr->get_next();
    }

    cout << "]" << endl;
}