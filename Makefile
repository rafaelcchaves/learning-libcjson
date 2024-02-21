SRC_DIR = src
OBJ_DIR = bin
CFLAGS = -Wall -Wpedantic
LIBS = -lcjson
CC = gcc
TARGETS = create_data.c parse_data.c

all: $(TARGETS)
	echo $^

%.c: $(OBJ_DIR)
	$(CC) $(SRC_DIR)/$@ $(CFLAGS) -o $(OBJ_DIR)/$*.o  $(LIBS)
    
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
