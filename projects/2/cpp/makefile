
RM = rm -f
EXEC      = main
SRC_FILES = *.cpp
CXX = g++
CC = $(CXX)
DEBUG_LEVEL     = -g
EXTRA_CCFLAGS   = -Wall
CXXFLAGS        = $(DEBUG_LEVEL) $(EXTRA_CCFLAGS)
CCFLAGS         = $(CXXFLAGS)
LDLIBS          = armadillo
O_FILES         = $(SRC_FILES:%.cpp=%.o)
INCLUDE_DIR     = include
OPTIMIZATION_LEVEL    = 3

all: compile link

compile:
	$(CC) -c $(CCFLAGS) $(SRC_FILES) -std=c++11 -I$(INCLUDE_DIR) 

link:
	# $(CC) -o $(EXEC) *.o -O$(OPTIMIZATION_LEVEL) -l$(LDLIBS)  
	$(CC) -o main main.o utils.o -O$(OPTIMIZATION_LEVEL) -l$(LDLIBS)  
	$(CC) -o problem3 problem3.o utils.o project2.o -O$(OPTIMIZATION_LEVEL) -l$(LDLIBS)  
	$(CC) -o problem4 problem4.o utils.o project2.o -O$(OPTIMIZATION_LEVEL) -l$(LDLIBS)  
                          
clean:
	${RM} $(O_FILES) core

vclean: clean
	$(RM) $(EXEC) a.out
