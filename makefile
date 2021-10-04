CC=g++

liste: liste.o test_list.o
liste.o: liste.cc liste.h
test_list.o: test_list.ccp liste.h

clean:
	rm -rf *.o *.~ liste

