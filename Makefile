BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/objs
SRC_DIR := src

CC = g++
CPPFLAGS = -std=c++17 -Wall -g3
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

_OBJS = main.o Cell.o Grid.o
SRC_OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

app: $(SRC_OBJS)
	$(CC) $(SRC_OBJS) -o $@ $(CPPFLAGS) $(SFML_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o app
