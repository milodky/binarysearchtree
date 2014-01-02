TARGET := TreeTest
CC := g++
HDRS := TreeNode.h
SRCS := TreeNode.cpp Test.cpp
OBJS := $(SRCS:.cpp =.o)
.SUFFIXES: .cpp .o
.PHONY: run clean
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
$(OBJS): $(HDRS)

%.o: %.cpp
	$(CC) -c -Wall $<

.PHONY: run clean
run:
	make
	./$(TARGET) 3
clean:
	-rm *.o
	-rm $(TARGET)
