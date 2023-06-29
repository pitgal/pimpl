BUILD_DIR = build
SRC_DIR = src
SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")
TARGET  = $(shell basename $(PWD))

OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
CXXFLAGS += -std=c++17

default: $(TARGET)

debug: CXXFLAGS += -DDEBUG -g
debug: default

.SECONDEXPANSION:

$(OBJECTS) : $$(patsubst $(BUILD_DIR)/%.o,$(SRC_DIR)/%.cpp,$$@)
	mkdir -p $(@D)
	$(CXX) -c -o $@ $(CXXFLAGS) $<

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $(CXXFLAGS) $^

run:
	./$(TARGET)

clean: 
	rm -f $(TARGET)
	rm -rf $(BUILD_DIR)

.PHONY: default