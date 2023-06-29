SRC_DIR = src
BUILD = build
_DEBUG = debug
_RELEASE = release
SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")
PROGRAM_NAME = $(shell basename $(PWD))
CXXFLAGS += -std=c++17 -Wall -Wextra

DEBUG ?= 1
ifeq ($(DEBUG),1)
    CXXFLAGS += -DDEBUG -g
	TARGET = $(_DEBUG)
else
    CFLAGS += -DNDEBUG
	TARGET = $(_RELEASE)
endif

BUILD_DIR = $(BUILD)/$(TARGET)
PROGRAM = $(BUILD_DIR)/$(PROGRAM_NAME)

OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

$(PROGRAM_NAME): $(PROGRAM) | $(shell rm -f $(PROGRAM_NAME))
	cp $(PROGRAM) $(PROGRAM_NAME)

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $@ $(CXXFLAGS) $^

${BUILD_DIR}:
	mkdir -p $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | ${BUILD_DIR}
	$(CXX) -c -o $@ $(CXXFLAGS) $<

run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)

clean:
	rm -f $(PROGRAM_NAME)
	rm -rf $(BUILD)

rebuild: clean $(PROGRAM_NAME)

.PHONY: run clean rebuild
