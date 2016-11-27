TARGET := test

CC := g++
CFLAGS := -g -pthread -std=c++11 -Iinc -lglut -lGL -lGLU -lfreeimage

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst %cpp,%o,$(SRCS))  

all: $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $(TARGET)
clean:  
	rm -rf $(TARGET) *.o $(OBJS) 
%.o:%.cpp  
	$(CC) $(CFLAGS) -c $< -o $@ 
