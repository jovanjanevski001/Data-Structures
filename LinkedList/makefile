CC = gcc
DIRS = . ./src
INCDIR = ./inc

DEPFLAGS = -MMD
CFLAGS = -g -Wall -Wextra $(foreach dir, $(INCDIR), -I $(dir)) $(DEPFLAGS)

CFILES = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJECTS = $(patsubst %.c, %.o, $(CFILES))
DEPFILES = $(patsubst %.c, %.d, $(CFILES))

ifeq ($(OS),Windows_NT)
    OUTPUT = output.exe
    RUN_CMD = .\$(OUTPUT)
    CLEAN_FILES = $(subst /,\,$(OUTPUT) $(OBJECTS) $(DEPFILES))
    CLEAN_CMD = -@del /Q /F $(CLEAN_FILES) 2>nul
else
    OUTPUT = output
    RUN_CMD = ./$(OUTPUT)
    CLEAN_FILES = $(OUTPUT) output_asan $(OBJECTS) $(DEPFILES)
    CLEAN_CMD = @rm -rf $(CLEAN_FILES)
endif

.PHONY: all test asan clean

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Build, then run the test suite (non-zero exit if any check fails)
test: all
	$(RUN_CMD)

# Rebuild everything with AddressSanitizer (leaks, use-after-free, overflows).
# Needs Linux, macOS or WSL; MinGW on Windows does not support it.
ifeq ($(OS),Windows_NT)
asan:
	@echo asan is not supported with MinGW. Run "make asan" from WSL.
else
asan:
	$(CC) -g -Wall -Wextra -fsanitize=address $(foreach dir, $(INCDIR), -I $(dir)) -o output_asan $(CFILES)
	./output_asan
endif

clean:
	$(CLEAN_CMD)

-include $(DEPFILES)