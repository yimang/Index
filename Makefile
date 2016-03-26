p8.out : main.o pager.o indexpager.o
	g++ -ansi -Wall -g -o p8.out main.o pager.o indexpager.o

main.o : main.cpp pager.h indexpager.h
	g++ -ansi -Wall -g -c main.cpp
	
pager.o : pager.cpp pager.h
	g++ -ansi -Wall -g -c pager.cpp

indexpager.o : indexpager.cpp indexpager.h pager.h
	g++ -ansi -Wall -g -c indexpager.cpp
	
clean :
	rm -f p8.out main.o pager.o indexpager.o