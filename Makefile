CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

BUILD_DIR = build
BUILD_UNSAFE_DIR = $(BUILD_DIR)/unsafe
BUILD_SAFE_DIR = $(BUILD_DIR)/safe
BUILD_CORE_DIR = $(BUILD_DIR)/core

# safe mode
all-safe: clean-safe build-safe run-safe
run-safe: $(BUILD_SAFE_DIR)/banking-safe.x
	./$(BUILD_SAFE_DIR)/banking-safe.x
build-safe: safe.o core.o
	$(CXX) $(CXXFLAGS) $(BUILD_SAFE_DIR)/*.o $(BUILD_CORE_DIR)/*.o -o $(BUILD_SAFE_DIR)/banking-safe.x
safe.o:
	$(CXX) $(CXXFLAGS) -c main-safe.cpp -o $(BUILD_SAFE_DIR)/main-safe.o
	$(CXX) $(CXXFLAGS) -c safe/safe-bank-statistics.cpp -o $(BUILD_SAFE_DIR)/safe-bank-statistics.o
	$(CXX) $(CXXFLAGS) -c safe/safe-bank-account.cpp -o $(BUILD_SAFE_DIR)/safe-bank-account.o
clean-safe:
	rm -f $(BUILD_SAFE_DIR)/*.o $(BUILD_SAFE_DIR)/*.x  $(BUILD_SAFE_DIR)/*.log


# unsafe mode
all-unsafe: clean-unsafe build-unsafe run-unsafe
run-unsafe: $(BUILD_UNSAFE_DIR)/banking-unsafe.x
	./$(BUILD_UNSAFE_DIR)/banking-unsafe.x
build-unsafe: unsafe.o core.o
	$(CXX) $(CXXFLAGS) $(BUILD_UNSAFE_DIR)/*.o $(BUILD_CORE_DIR)/*.o -o $(BUILD_UNSAFE_DIR)/banking-unsafe.x
unsafe.o:
	$(CXX) $(CXXFLAGS) -c main-unsafe.cpp -o $(BUILD_UNSAFE_DIR)/main-unsafe.o
	$(CXX) $(CXXFLAGS) -c unsafe/unsafe-bank-statistics.cpp -o $(BUILD_UNSAFE_DIR)/unsafe-bank-statistics.o
	$(CXX) $(CXXFLAGS) -c unsafe/unsafe-bank-account.cpp -o $(BUILD_UNSAFE_DIR)/unsafe-bank-account.o
clean-unsafe:
	rm -f $(BUILD_UNSAFE_DIR)/*.o $(BUILD_UNSAFE_DIR)/*.x $(BUILD_UNSAFE_DIR)/*.log

# general
core.o: clean-core
	$(CXX) $(CXXFLAGS) -c core/logger.cpp -o $(BUILD_CORE_DIR)/logger.o
clean-core:
	rm -f $(BUILD_CORE_DIR)/*.o
clean:
	rm -f build/**/*.x build/**/*.o build/**/*.log
