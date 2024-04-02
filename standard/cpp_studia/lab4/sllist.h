#pragma once

class sllist
{
public:
    class slnode
    {
    public:
        slnode* get_next() const;
        int get_val() const;
        int& get_val();

    private:
        slnode(int val, slnode* nxt);
            // constructor of the slnode

        void set_next(slnode* new_next);
            // sets the new value of the next member

        int value;
        slnode *next;

        friend class sllist;
    };

    sllist() = default;
        // constructor - creates empty list

    sllist(const sllist& src);
        // copy constructor - copies all elements of the src list

    ~sllist();
        // destructor - frees (with delete) all the nodes

    sllist& operator=(const sllist& src);
        // assignment operator
        // frees all elements of current list and copies all elements of the src list

    sllist& operator+=(const sllist& src);
        // appends all elements of the src list at the end of the current list

    bool empty() const;
        // returns true if the list is empty, i.e. contains no elements

    int size() const;
        // returns number of elements in the list

    slnode* get_first() const;
        // returns pointer to the first element of the list

    void push_front(int val);
        // adds element val in the beginning of the list

	int pop_front();
        // removes the first element of the list
        // returns value stored in this first (deleted) element
        // or 0 if the list is empty

	void clear();
		// removes all elements from the list

	slnode* insert(int val);
		// inserts the new element (set to val)
		// BEFORE the element of greater than or equal value
		// or at the end of the list if no such element exists
        // returns pointer to the newly created element of the list

private:
    slnode* pHead = nullptr;

    slnode*& find_ble(int val);
        // returns the reference to the pointer (either pHead or next
        // member of the slnode object) pointing to the list element
        // with the value greater then or equal to val
        // referenced pointer will have nullptr value if no such element
        // (i.e. element with greater than or equal value) exists

    slnode* copy_elements(const sllist& src);
        // creates the copy of all nodes of the src list
        // preserving order of the elements;
        // returns pointer to the first copied node
};

void print_list(const sllist& lst);
  // prints all values stored in the list

