CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

BUILD_DIR = build
BUILD_UNSAFE_DIR = $(BUILD_DIR)/unsafe
BUILD_SAFE_DIR = $(BUILD_DIR)/safe

# safe mode
all-safe: clean-safe build-safe run-safe
run-safe: $(BUILD_UNSAFE_DIR)/banking-safe.x
	./$(BUILD_UNSAFE_DIR)/banking-safe.x
build-safe: safe-bank-statistics.o safe-bank-account.o main-safe.o
	$(CXX) $(CXXFLAGS) $(BUILD_SAFE_DIR)/*.o -o $(BUILD_UNSAFE_DIR)/banking-safe.x
main-safe.o:
	$(CXX) $(CXXFLAGS) -c main-safe.cpp -o $(BUILD_SAFE_DIR)/main-safe.o
safe-bank-statistics.o:
	$(CXX) $(CXXFLAGS) -c safe/safe-bank-statistics.cpp -o $(BUILD_SAFE_DIR)/safe-bank-statistics.o
safe-bank-account.o:
	$(CXX) $(CXXFLAGS) -c safe/safe-bank-account.cpp -o $(BUILD_SAFE_DIR)/safe-bank-account.o
clean-safe:
	rm -f $(BUILD_SAFE_DIR)/*.o $(BUILD_SAFE_DIR)/*.x


# unsafe mode
all-unsafe: clean-unsafe build-unsafe run-unsafe
run-unsafe: $(BUILD_UNSAFE_DIR)/banking-unsafe.x
	./$(BUILD_UNSAFE_DIR)/banking-unsafe.x
build-unsafe: unsafe-bank-statistics.o unsafe-bank-account.o main-unsafe.o
	$(CXX) $(CXXFLAGS) $(BUILD_UNSAFE_DIR)/*.o -o $(BUILD_UNSAFE_DIR)/banking-unsafe.x
main-unsafe.o:
	$(CXX) $(CXXFLAGS) -c main-unsafe.cpp -o $(BUILD_UNSAFE_DIR)/main-unsafe.o
unsafe-bank-statistics.o:
	$(CXX) $(CXXFLAGS) -c unsafe/unsafe-bank-statistics.cpp -o $(BUILD_UNSAFE_DIR)/unsafe-bank-statistics.o
unsafe-bank-account.o:
	$(CXX) $(CXXFLAGS) -c unsafe/unsafe-bank-account.cpp -o $(BUILD_UNSAFE_DIR)/unsafe-bank-account.o
clean-unsafe:
	rm -f $(BUILD_UNSAFE_DIR)/*.o $(BUILD_UNSAFE_DIR)/*.x

# general
clean:
	rm -f build/**/*.x build/**/*.o
