CC=g++
CFLAGS=-c -std=gnu++11 -Wall -pedantic
LDFLAGS=
SOURCES=Main.cpp #Add.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Math

all: $(SOURCES) $(EXECUTABLE)
#compile everything

clean:
	rm $(OBJECTS)
#remove .o files

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
#compile a single file
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
#what command to compile

#make all
#make clean
#make (name).cpp