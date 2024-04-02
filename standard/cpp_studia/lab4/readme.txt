EOOP-LAB103-LAB104-24/L
Instructors: Zbigniew Szymański (LAB103), Rajmund Kożuszek (LAB104)

Today your task is the implementation of:
  - the copy constructor performing DEEP copy of the list,
  - the assignment operator which first frees memory occupied by current list and next copies all elements from the other list,
  - the += (concatenation) operator which appends copy of all elements of the other list at the end of the current list.
  
Note that in the sllist.h file there is private method copy_elements declared. You probably should start with considering how this method should operate and use it to avoid code duplication.
Again, it makes sense to let tests lead your implementation:
eliminate all the compilation, and then testing errors before moving "line elimination comment" further down main function.
Remember that memory must be deallocated.

As usual, you have chance to get maximum grade if you complete
your task before 4pm. You should submit only sllist.cpp file
(which means that you cannot change class definitions).
