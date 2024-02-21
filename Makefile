SRC_DIR = src
OBJ_DIR = bin
CFLAGS = -Wall -Wpedantic
LIBS = -lcjson
CC = gcc
TARGETS = $(wildcard $(SRC_DIR)/*.c) 

all: $(TARGETS)
	echo $^

$(SRC_DIR)/%.c: $(OBJ_DIR)
	$(CC) $(SRC_DIR)/$*.c $(CFLAGS) -o $(OBJ_DIR)/$*.o  $(LIBS)
    
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
