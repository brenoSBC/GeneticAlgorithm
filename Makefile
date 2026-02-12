CC = g++
CFLAGS = -Iinclude

SRC_DIR = src
BIN_DIR = bin

SRC = $(SRC_DIR)/*.cpp
OUT = $(BIN_DIR)/genetic

all: $(OUT)

$(OUT): $(SRC) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)
