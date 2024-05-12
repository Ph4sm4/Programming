#include "sllist.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool check_list_content(const sllist &lst, const string &expected)
{
    stringstream ss;
    ss << lst;

    if (ss.str() != expected)
    {
        cerr << "Invalid stream content: " << ss.str() << '\n';
        cerr << "              Expected: " << expected << '\n';
        return false;
    }
    return true;
}

int main()
{

    { // default field values in slnode
        char name_buffer[] = "name";
        sllist::slnode just_name(name_buffer);
        strcpy(name_buffer, "else");

        if (strcmp(just_name.get_value(), "name") != 0)
            cerr << "Incorrect value in 'just_name' object.\n";
        if (just_name.get_count() != 0)
            cerr << "Incorrect count in 'just_name' object.\n";
        if (just_name.get_next() != nullptr)
            cerr << "Incorrect next in 'just_name' object.\n";
    }

    { // operator ++ and += tests
        sllist::slnode value_count("value", 5);

        if (strcmp(value_count.get_value(), "value") != 0)
            cerr << "Incorrect value in 'value_count' object.\n";
        if (value_count.get_count() != 5)
            cerr << "Incorrect count in 'value_count' object.\n";
        if (value_count.get_next() != nullptr)
            cerr << "Incorrect next in 'value_count' object.\n";

        if (value_count++ != 5)
            cerr << "Incorrect value returned by 'value_count++'.\n";
        if (value_count.get_count() != 6)
            cerr << "Incorrect count in 'value_count' object after ++.\n";

        if ((value_count += 14) != 20)
            cerr << "Incorrect value returned by 'value_count+='.\n";
        if (value_count.get_count() != 20)
            cerr << "Incorrect count in 'value_count' object after +=.\n";
    }

    { // operator << test
        sllist::slnode val_cnt("value", 5);

        stringstream ss;
        ss << val_cnt;
        if (ss.str() != "[value 5]")
            cerr << "Incorrect string output to stream by '<< val_cnt'.\n";
    }

    { // empty list tests
        sllist empty;
        if (!empty.empty())
            cerr << "Incorrect value of is_empty() for 'empty' object.\n";
        if (empty.size() != 0)
            cerr << "Incorrect value of size() for 'empty' object.\n";
        if (empty.get_first() != nullptr)
            cerr << "Incorrect value of get_first() for 'empty' object.\n";
    }

    { // one-element list
        sllist one;
        one.add_pair("Beagle", 4);
        if (one.empty())
            cerr << "Incorrect value of is_empty() for 'one' object.\n";
        if (one.size() != 1)
            cerr << "Incorrect value of size() for 'one' object.\n";
        if (one.get_first() == nullptr)
            cerr << "Incorrect value of get_first() for 'one' object.\n";

        sllist::slnode const *pelm = one.get_first();
        if (pelm != nullptr)
        {
            if (strcmp(pelm->get_value(), "Beagle") != 0)
                cerr << "Incorrect value in the first node in 'one' list.\n";
            if (pelm->get_count() != 4)
                cerr << "Incorrect count in the first node in 'one' list.\n";
            if (pelm->get_next() != nullptr)
                cerr << "Incorrect next pointer in the first node in 'one' list.\n";
        }
    }

    { // checking << operator
        sllist one;

        stringstream ss;
        ss << one;
        if (ss.str() != "{}")
            cerr << "Incorrect string output to stream by '<< one' before add_pair.\n";

        one.add_pair("Beagle", 4);
        ss.seekp(0, ios_base::beg);
        ss << one;
        if (ss.str() != "{[Beagle 4] }")
            cerr << "Incorrect string output to stream by '<< one' after add_pair.\n";
    }

    { // add pair at the beginning
        sllist two;
        two.add_pair("Beagle", 4);
        two.add_pair("Aardvaark", 1);
        check_list_content(two, "{[Aardvaark 1] [Beagle 4] }");
    }

    { // add pair at the end
        sllist two;
        two.add_pair("Beagle", 4);
        two.add_pair("Voyage", 7);
        check_list_content(two, "{[Beagle 4] [Voyage 7] }");
    }

    { // add the same value twice
        sllist lst;
        lst.add_pair("Beagle", 4);
        lst.add_pair("Aardvaark", 1);
        lst.add_pair("Voyage", 7);
        lst.add_pair("Beagle", 2);
        check_list_content(lst, "{[Aardvaark 1] [Beagle 6] [Voyage 7] }");
    }

    { // add pair (with default count) in the middle
        sllist lst;
        lst.add_pair("Beagle", 4);
        lst.add_pair("Aardvaark", 1);
        lst.add_pair("Voyage", 7);
        lst.add_pair("Galapagos");
        check_list_content(lst, "{[Aardvaark 1] [Beagle 4] [Galapagos 0] [Voyage 7] }");
    }

    { // use [] operator to insert elements
        sllist lst;
        lst["Beagle"] = 4;
        lst["Aardvaark"] = 1;
        lst["Voyage"] += 7;
        lst["Galapagos"]++;
        check_list_content(lst, "{[Aardvaark 1] [Beagle 4] [Galapagos 1] [Voyage 7] }");
    }

    { // check copy ctor
        sllist lst;
        lst["Beagle"] = 4;
        lst["Aardvaark"] = 1;
        lst["Voyage"] += 7;
        lst["Galapagos"]++;

        sllist snd = lst;
        check_list_content(snd, "{[Aardvaark 1] [Beagle 4] [Galapagos 1] [Voyage 7] }");
    }

    { // use [] operator to access elements in the list
        sllist lst;
        lst["Beagle"] = 4;
        lst["Aardvaark"] = 1;
        lst["Voyage"] += 7;
        lst["Galapagos"]++;

        // note that const forces compiler to use const version of [] operator
        const sllist snd = lst;
        check_list_content(snd, "{[Aardvaark 1] [Beagle 4] [Galapagos 1] [Voyage 7] }");

        if (snd["Beagle"] != 4)
            cerr << "Incorrect count returned by [] for 'Beagle'.\n";
        if (snd["Aardvaark"] != 1)
            cerr << "Incorrect count returned by [] for 'Aardvaark'.\n";
        if (snd["Voyage"] != 7)
            cerr << "Incorrect count returned by [] for 'Voyage'.\n";
        if (snd["Galapagos"] != 1)
            cerr << "Incorrect count returned by [] for 'Galapagos'.\n";
        if (snd["Plymouth"] != 0)
            cerr << "Incorrect count returned by [] for 'Plymouth'.\n";
    }

    { // check = operator
        sllist snd;
        sllist lst;
        lst["Beagle"] = 4;
        lst["Aardvaark"] = 1;
        lst["Voyage"] += 7;
        lst["Galapagos"]++;
        snd = lst;
        check_list_content(snd, "{[Aardvaark 1] [Beagle 4] [Galapagos 1] [Voyage 7] }");
    }

    { // check auto assignment
        sllist lst;
        lst["Beagle"] = 4;
        lst["Aardvaark"] = 1;
        lst["Voyage"] += 7;
        lst["Galapagos"]++;
        lst = lst;
        check_list_content(lst, "{[Aardvaark 1] [Beagle 4] [Galapagos 1] [Voyage 7] }");
    }

    { // check += operator
        sllist lst;
        lst["Galapagos"] += 1;
        lst["Beagle"] += 4;

        sllist snd;
        snd["Aardvaark"]++;
        snd["Voyage"] = 7;
        sllist tmp(snd);

        snd += lst;
        check_list_content(snd, "{[Aardvaark 1] [Beagle 4] [Galapagos 1] [Voyage 7] }");
        lst += tmp;
        check_list_content(lst, "{[Aardvaark 1] [Beagle 4] [Galapagos 1] [Voyage 7] }");
    }

    { // check auto +=
        sllist lst;
        lst["two"] = 1;
        lst["four"] = 2;
        lst["six"] = 3;
        lst["eight"] = 4;
        lst += lst;
        check_list_content(lst, "{[eight 8] [four 4] [six 6] [two 2] }");
    }
    /* first line of test elimination region


    last line of test elimination region */

    cerr << "End of tests." << endl;
    return 0;
}
