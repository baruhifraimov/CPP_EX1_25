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
#
#--leak-check=full: "each individual leak will be shown in detail"
#--show-leak-kinds=all: Show all of "definite, indirect, possible, 
#				reachable" leak kinds in the "full" report.
#--track-origins=yes: Favor useful output over speed. This tracks 
#			the origins of uninitialized values, which could be very useful 
#			for memory errors. Consider turning off if Valgrind is unacceptably slow.
#
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./Main

.PHONY: clean valgrind

clean:
	rm -rf $(OBJDIR) Main *.o