CXX=g++
CC=gcc
INCLUDE=-I../include
CFLAGS=-std=c++14 -w
.PONHY: clean install uninstall

../bin/libhiberlite.a:$(foreach n,$(wildcard *.cpp),../temp/$(n).o) ../temp/sqlite3.c.o
	ar rcsv ../bin/libhiberlite.a ../temp/*.cpp.o
	ar rcsv ../bin/libsqlite3.a ../temp/sqlite3.c.o

../temp/%.cpp.o:%.cpp
	$(CXX) $(INCLUDE) $(CFLAGS) -c $^ -o $@
../temp/sqlite3.c.o:sqlite3.c
	$(CC) $(INCLUDE) -c $^ -o $@

clean:
	rm ../temp/* -rf
	rm ../bin/* -rf
install:uninstall ../bin/libhiberlite.a
	@echo "	Install hiberlite"
	cp ../include/* /usr/include -rf
	cp ../bin/libhiberlite.a /usr/lib/libhiberlite.a
	cp ../bin/libsqlite3.a /usr/lib/libsqlite3.a
	@echo "	Ok"

uninstall:
	@echo "	Remove hiberlite"
	rm -rf /usr/include/hiberlite 
	rm -f /usr/include/sqlite3.h
	rm -f /usr/lib/libhiberlite.a
	rm -f /usr/lib/libsqlite3.a
	@echo "	Ok"