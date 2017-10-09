assignment_0 : main.o commands.o utils.o
	gcc -o assignment main.o commands.o utils.o

main.o : main.c ../include/utils.h ../include/commands.h
	gcc -c main.c

commands.o : commands.c ../include/commands.h
	gcc -c commands.c

utils.o : utils.c ../include/utils.h
	gcc -c utils.c

clena :
	rm *.o assignment_0
