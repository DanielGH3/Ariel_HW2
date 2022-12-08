all:
	gcc -Wall -c my_mat.c
	ar -rc libmy_mat.a my_mat.o
	gcc -Wall main.c libmy_mat.a -o connections.exe
