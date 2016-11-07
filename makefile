#Compiler
CC=g++ 
CFLAGS=-Wall -Werror -ansi -pedantic

#Name of executable
TARGET=./bin/rshell

#Source and object dir
OBJDIR=bin
SRCDIR=src

#Files and directories
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

#Targets
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(SOURCES) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
	rm -rf $(OBJDIR)
