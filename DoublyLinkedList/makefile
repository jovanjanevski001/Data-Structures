output: main.o
	gcc -o $@ $^
%.o: %.c
	gcc -c -o $@ $<

clean:
	rm *.o *.exe