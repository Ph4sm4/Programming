#pragma once
#include <iostream>

class sllist
{
public:
    class slnode
    {
    public:
        const char *get_value() const;
        unsigned int get_count() const;
        slnode *get_next() const;

        slnode(const char *name, unsigned int count = 0, slnode *nxt = nullptr);
        // constructor of the slnode
        ~slnode();
        // destructor - releases memory allocated for value

        unsigned int operator++(int);
        // increases count member by one; returns old count value

        unsigned int operator+=(unsigned int cnt);
        // increases count member by cnt; returns new count value

    private:
        void set_next(slnode *new_next);
        // sets the new value of the next member

        unsigned int count = 0;
        char *value = nullptr;
        slnode *next = nullptr;

        friend class sllist;
    };

    sllist() = default;
    // constructor - creates empty list
    // because pHead is already initialized we have nothing to do

    sllist(const sllist &src);
    // copy constructor

    ~sllist();
    // destructor - frees (with delete) all the nodes

    sllist &operator=(const sllist &src);
    // assignment operator - makes deep copy of the list

    sllist &operator+=(const sllist &right);
    // updates current object adding to it (value, count) pairs
    // from right object

    bool empty() const;
    // returns true if the list is empty, i.e. contains no elements

    unsigned int size() const;
    // returns number of elements in the list

    const slnode *get_first() const;
    // returns pointer to the first element of the list

    void clear();
    // removes all elements from the list

    bool exists(const char *name) const;
    // returns true if there exists node with value equal to name
    // false otherwise

    const slnode *add_pair(const char *val, unsigned int cnt = 0);
    // if node with value val exists in the list adds cnt to count member of this element
    // if such node does not exist add_pair inserts element
    // in lexicographical order and sets count member to cnt
    // returns pointer to node updated or created

    unsigned int &operator[](const char *val);
    // operates as add_pair (with cnt = 0) but returns reference to
    // count member of the node with value val

    unsigned int operator[](const char *val) const;
    // returns count member of node with value val
    // or 0 if such node does not exists

private:
    slnode *pHead = nullptr;

    slnode *&find_ble(const char *val);
    // returns the reference to the pointer (either pHead or next
    // member of the slnode object) pointing to the list element
    // with the value greater then or equal to val
    // referenced pointer will have nullptr value if no such element
    // (i.e. element with greater than or equal value) exists
};

std::ostream &operator<<(std::ostream &os, const sllist::slnode &node);
std::ostream &operator<<(std::ostream &os, const sllist &list);