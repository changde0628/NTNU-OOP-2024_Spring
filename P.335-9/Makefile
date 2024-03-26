CXX = g++
CXXFLAGS = -std=c++14 -Wall
TARGET = main
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

TEST_FILES = $(wildcard pattern/*.in)
TOTAL_TESTS = $(words $(TEST_FILES))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test:
	@$(eval PASSED_TESTS=0)
	@echo "====== Testing Begins ======"
	@for file in $(TEST_FILES); do \
		echo "\n🔍 Testing Case: $$file"; \
		./$(TARGET) < $$file > $${file%.in}.result; \
		if diff -u $${file%.in}.out $${file%.in}.result > /dev/null; then \
			echo "✅ Test: Pass"; \
			PASSED_TESTS=$$((PASSED_TESTS + 1)); \
		else \
			echo "❌ Test: Fail"; \
		fi; \
	done; \
	echo "\n====== Test Summary ======"; \
	echo "📊 Total Passed: $$PASSED_TESTS / $(TOTAL_TESTS)"; \
	echo "=========================="; \
	if [ "$$PASSED_TESTS" -eq "$(TOTAL_TESTS)" ]; then \
		cat art.txt; \
	fi

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_FILES:.in=.result)

.PHONY: all clean test
