
CC = gcc
OBJS = main.o linked_list.o

output: $(OBJS)
	$(CC) $(OBJS) -o output

main.o: main.c
	$(CC) -c main.c

linked_list.o: linked_list.c linked_list.h
	$(CC) -c linked_list.c
#default:
#	gcc -c linked_list.c -o linked_list.o
#	ar rcs libmylinked_list.a linked_list.o
#	gcc main.c -L. -lmylinked_list -o main
clean:
	rm -f *.a *.o *.exe