EOOP-LAB103-LAB104-24/L
Instructors: Zbigniew Szymański (LAB103), Rajmund Kożuszek (LAB104)

In the last laboratory assignment you have to assemble all the elements from the previous tasks in one class definition.
You'll still implement singly-linked list, but this time you have to insure uniqueness of values stored in value member of list nodes. You'll also have to implement operators used to change count member of the slnode objects. 
In the sllist class you'll implement two indexing operators []. Note that operation of const and non-const version of the operator differs significantly: one can modify the list and the other cannot.
There are several new "technicalities" in this assignment:
- use of stringstream objects to verify operation of << operators (no reading of the console required!) and checking the content of the list in 'textual' form,
- implementation of stream output operator << for slnode and sllist,
- use of const_cast type conversion template; this conversion is defined specifically to remove constness.

The usage scenario in the assignment may be following: 
we want to use add_pair() method in implementation of indexing operator [] to find/create the node with proper value. But the value returned by add_pair() is const slnode pointer. When we try to return reference to the count member compiler will (rightly) complain. To cast away constness of the pointer (with identifier pnode) we write:
	const_cast<slnode *>(pnode)

Again, it makes sense to let tests lead your implementation:
eliminate all the compilation, and then testing errors before moving "line elimination comment" further down the main function.
Remember that memory must be deallocated.

As usual, you have chance to get maximum grade if you complete
your task before 4pm. You should submit only sllist.cpp file
(which means that you cannot change class definitions).
