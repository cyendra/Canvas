
CC=g++
OBJS=obj/TestSuite.o
TARGET=test/suite
CFLAGS=-Iinclude -Wall -std=c++11
RM=rm -rf


$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

$(OBJS): obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) $(OBJS)

