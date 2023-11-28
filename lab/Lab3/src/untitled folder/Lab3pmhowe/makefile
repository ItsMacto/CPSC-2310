# config variables
CC=gcc
CFLAGS=-Wall -g 
LFLAGS=-lm 
TARGET=out 
 
# generate source and object lists also just string variables
C_SRCS := \
	$(wildcard *.c) \
	$(wildcard src/*.c) \
	$(wildcard src/**/*.c) 

HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h) 

# creates object files list from sources and place them in a 'bin' directory.
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# default target
all: build
	@echo “All Done!”
 
# Link all built objects 
build: $(OBJS) 
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# builds object files from source files and ensures the 'bin' directory exists
bin/%.o: %.c $(HDRS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

bin/%.o: src/%.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# removes the final executable and the 'bin' directory containing all object files
clean:
		rm -f $(TARGET)
		rm -rf bin

# builds the project (if needed) and then runs it
run: build
	./$(TARGET) input2.txt output.txt

# Prints the found sources, headers, and target object files to the command line
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"