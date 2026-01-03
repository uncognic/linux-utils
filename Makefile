CC = cc
CFLAGS = -std=c17 -Wall -Wextra -O2 -Ilib

SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = build


SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
LIB_FILES = $(wildcard $(LIB_DIR)/*.c)

SRC_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/src_%.o,$(SRC_FILES))
LIB_OBJS = $(patsubst $(LIB_DIR)/%.c,$(OBJ_DIR)/lib_%.o,$(LIB_FILES))

BINS = $(patsubst $(SRC_DIR)/%.c,%,$(SRC_FILES))

all: $(BINS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/lib_%.o: $(LIB_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/src_%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

%: $(OBJ_DIR)/src_%.o $(LIB_OBJS)
	$(CC) $^ $(LDFLAGS) -o $@

clean:
	rm -rf $(OBJ_DIR) $(BINS)

.PHONY: all clean
