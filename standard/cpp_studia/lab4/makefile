WFlags = -Wall -Wextra -pedantic

sllist_test: sllist_test.o sllist.o
	g++ $(WFlags) -g sllist_test.o sllist.o -o sllist_test

sllist_test.o: sllist_test.cpp sllist.h
	g++ $(WFlags) -g -c sllist_test.cpp -o sllist_test.o

sllist.o: sllist.cpp sllist.h
	g++ $(WFlags) -g -c sllist.cpp -o sllist.o

clean:
	rm sllist_test *.o
