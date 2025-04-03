CC = clang++
CCFLAGS = -Wall -std=c++17 -ggdb
SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj


#compile the main program
Main: $(OBJDIR)/main.o $(OBJDIR)/Graph.o $(OBJDIR)/Algorithms.o $(OBJDIR)/DataStructures.o 
	$(CC) $(CCFLAGS) -o $@ $^

#compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	mkdir -p $(OBJDIR)
	$(CC) $(CCFLAGS) -I$(INCDIR) -c $< -o $@

#compile only the main file
$(OBJDIR)/main.o: $(SRCDIR)/main/main.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CCFLAGS) -I$(INCDIR) -c $< -o $@


test:
	@echo "Test target not implemented yet."

#make sure to run 'ulimit -n 1024' before runing valgrind, thank you
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./Main

.PHONY: clean valgrid

clean:
	rm -rf $(OBJDIR) Main *.o