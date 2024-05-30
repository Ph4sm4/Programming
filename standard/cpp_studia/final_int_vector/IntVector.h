#include <string>

struct Node
{
    int val;
    Node *next;
    Node *prev;

    Node(int v, Node *n = nullptr, Node *p = nullptr) : val(v), next(n), prev(p) {}
};

class Abstract
{
public:
    virtual void x() = 0;
};

class IntVector : public Abstract
{
public:
    virtual void x() override {}

    void push_back(int val);
    void push_front(int val);
    void insert(int ind, int val);
    void pop_front();
    void pop_back();
    void clear();
    int at(int ind) const;
    int size() const;

    int operator[](int ind);

    Node *pHead = nullptr;

private:
};

class StringIntVector : public IntVector
{
public:
    int operator[](std::string s);
};