#include <iostream>
using namespace std;

template <typename Key, typename Info>
class SList
{
private:
    struct Node
    {
        Node(const Key &key, const Info &info, Node *next) : key(key), info(info), next(next) {}
        Node *next;

        Key key;
        Info info;
    }

    Node *head;

public:
    bool insertIfCloseToEachOther(const Key &keyInsertAfter, const Key &key, const Info &info)
    {
        bool isInserted;

        performInsertion(keyInsertAfter, head, nullptr, key, info, isInserted);
        return isInserted;
    }

    bool performInsertion(const Key &keyInsertAfter, Node &*curr, Node *prev, const Key &key, const Info &info, bool &outIsInserted)
    {
        if (outIsInserted)
            return true;

        if (!curr)
            return false;

        if (!prev || (prev && curr->key != prev->key) || curr->key != keyInsertAfter)
        {
            performInsertion(keyInsertAfter, curr->next, curr, key, info, outIsInserted);
        }
        else
        {
            Node *newNode = new Node(key, info, curr->next);
            curr->next = newNode;
            return true;
        }
    }
}

int
main()
{

    return 0;
}