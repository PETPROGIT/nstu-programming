CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -Idb/include -Idata_structures/include

TARGET = bin/lab_1
BUILD  = build

SRCS = main.cpp \
       $(wildcard db/src/*.cpp) \
       $(wildcard data_structures/src/*.cpp)

OBJS = $(SRCS:%.cpp=$(BUILD)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD) $(TARGET)