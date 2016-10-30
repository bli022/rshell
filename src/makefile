#Compiler
CC=g++
CFLAGS= -Wall -Werror -ansi -pedantic

#Name of executable
TARGET=rshell

#Source and object dir
OBJDIR=bin
SRCDIR=src

#Files and directories
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

#Targets
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $^

$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
