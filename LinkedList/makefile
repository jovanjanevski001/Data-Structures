OUTPUT = output
CC = gcc
DIRS = . ./src
INCDIR = ./inc

DEPFLAGS = -MP -MD
CFLAGS = -g $(foreach dir, $(INCDIR), -I$(dir)) $(DEPFLAGS)

CFILES = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJECTS = $(patsubst %.c, %.o, $(CFILES))
DEPFILES = $(patsubst %.c, %.d, $(CFILES))


$(OUTPUT): $(OBJECTS)
	$(CC) -o $@ $^ 
	
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	rm -rf $(OUTPUT) $(OBJECTS) $(DEPFILES)

-include $(DEPFILES)