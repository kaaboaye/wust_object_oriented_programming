SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
CPPFLAGS := -std=c++17 -Weverything

a.out: $(OBJ_FILES)
	clang -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	clang $(CPPFLAGS) -c -o $@ $<