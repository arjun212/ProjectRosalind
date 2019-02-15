# Declaration of variables
CC = g++
CC_FLAGS = -w -I../utils
 


# File names
EXEC = main
HEADER = ../utils/utils.h
SOURCES = $(wildcard *.cpp ../utils/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(SORUCE_DIR_FLAGS) -o $(EXEC)
 
# To obtain object files
%.o: %.cpp $(HEADER)
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
