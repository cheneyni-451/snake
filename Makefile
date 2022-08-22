BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/objs
SRC_DIR := src

CC = g++
CPPFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

_OBJS = main.o Cell.o Grid.o
SRC_OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

app: $(SRC_OBJS)
	$(CC) $^ -o $@ $(CPPFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o app
