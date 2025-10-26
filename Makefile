CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -I./include -I./example/include
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_EXAMPLE_DIR = example/src
SOURCES += $(wildcard $(SRC_EXAMPLE_DIR)/*.cpp)
OUT_DIR = bin
TARGET = $(OUT_DIR)/camera_app

all: $(OUT_DIR) $(TARGET)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(EXAMPLE_INCLUDE) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(OUT_DIR)

rebuild: clean all

.PHONY: all clean