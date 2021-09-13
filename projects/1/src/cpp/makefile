RM = rm -f

all: compile link

compile:
	g++ -c problem2.cpp
	g++ -c problem7.cpp
	g++ -c junk.cpp

link:
	g++ -o problem2 problem2.o
	g++ -o problem7 problem7.o
	g++ -o junk junk.o

# run:
# 	./problem2

clean:
	${RM} *.o
