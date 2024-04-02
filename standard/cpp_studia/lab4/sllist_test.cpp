#include <iostream>
#include "sllist.h"
#include <vector>
using namespace std;

void verify_list(const sllist &lst, const vector<int> &right_content)
{
    if ((size_t)lst.size() != right_content.size())
        cerr << "Error in verified list size()\n";

    const sllist::slnode *ptr_node = lst.get_first();
    for (size_t idx = 0; idx < right_content.size(); idx++)
        if (ptr_node == nullptr)
            cerr << "List shorter than reference container @" << idx << " entry.\n";
        else
        {
            if (ptr_node->get_val() != right_content[idx])
                cerr << "Invalid list value  @" << idx << " entry.\n";
            ptr_node = ptr_node->get_next();
        }
}

int main()
{
    // one-element tests
    cout << "Testing one-element copy ctor and assignment\n";
    {
        sllist lst;
        lst.push_front(17);

        sllist snd(lst);
        verify_list(snd, {17});
    }

    {
        sllist snd;
        sllist lst;
        lst.push_front(33);

        snd = lst;
        verify_list(snd, {33});
    }
    // ONE point mark

    // multi-element list test
    cout << "Testing multi-element copy ctor and assignment\n";
    {
        sllist lst;
        lst.push_front(987);
        lst.push_front(85796);
        lst.push_front(-435);
        lst.push_front(19);
        lst.push_front(1);

        sllist snd(lst);
        verify_list(snd, {1, 19, -435, 85796, 987});

        sllist third;
        third = lst;
        verify_list(third, {1, 19, -435, 85796, 987});
    }

    cout << "Testing auto-assignment (a = a)\n";
    {
        sllist lst;
        lst.push_front(256);
        lst.push_front(16);
        lst.push_front(1);

        lst = lst;
        verify_list(lst, {1, 16, 256});
    }

    // TWO point mark

    cout << "Testing += operator (concatenation of lists)\n";
    {
        sllist lst;
        lst.push_front(9);
        lst.push_front(3);

        sllist snd;
        snd.push_front(81);
        snd.push_front(27);

        lst += snd;
        verify_list(lst, {3, 9, 27, 81});
    }

    cout << "Testing auto += operator (a += a)\n";
    {
        sllist lst;
        lst.push_front(44);
        lst.push_front(33);

        lst += lst;
        verify_list(lst, {33, 44, 33, 44});
    }

    // THREE point mark

    /* first line of test elimination region
    last line of test elimination region */

    cerr << "End of tests." << endl;
    return 0;
}
