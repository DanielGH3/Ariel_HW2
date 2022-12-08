all: libmy_mat.a
	gcc -Wall main.c libmy_mat.a -o connections
	
my_mat.o: my_mat.c
	gcc -Wall -c my_mat.c
	
libmy_mat.a: my_mat.o
	ar -rc libmy_mat.a my_mat.o
