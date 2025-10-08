CC = clang
CFLAGS = -Wall -O2 -arch arm64 -target arm64-apple-macos
LDFLAGS = -arch arm64 -target arm64-apple-macos
INCLUDES = -I../../../HeaderFiles -I../../../SharedFiles
SRC_DIR = ../../../SourceFiles
TEST_SRC_DIR = ../../../UnitTestFiles/SourceFiles
SHARED_SRC_DIR = ../../../SharedFiles
OBJ_DIR = ./obj
BIN_DIR = ../../../BuildFiles/macOS/arm64

SOURCES = $(SRC_DIR)/CEcoLab1.c $(TEST_SRC_DIR)/EcoLab1.c $(SHARED_SRC_DIR)/IsEqualUGUID.c
OBJECTS = $(OBJ_DIR)/CEcoLab1.o $(OBJ_DIR)/EcoLab1.o $(OBJ_DIR)/IsEqualUGUID.o
EXEC = $(BIN_DIR)/EcoLab1UnitTest

all: $(EXEC)

$(EXEC): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SHARED_SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean