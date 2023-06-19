CC	   = g++
CFLAGS = --std=c++2a -xc++
SOURCE = src/*.cpp
HEADER = ./include
TARGET = prog
ENTRY  = main.cpp

all:
	$(CC) $(CFLAGS) $(ENTRY) $(SOURCE) -o $(TARGET) -I$(HEADER)

run:
	@./$(TARGET)
