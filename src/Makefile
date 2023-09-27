BUILD_DIR = build
VIEW_DIR = view
MODEL_DIR = model
CALCULATOR_EXE = calculator
TEST_DIR = tests
TEST_EXECUTABLE = test
TEST_SRC = test.cc
CXX = g++
CFLAGS = -Werror -Wextra -Wall
LIBS =
OS = $(shell uname -s)
MACOS = Darwin

ifeq ($(OS), $(MACOS))
CALCULATOR_EXE = calculator.app
# else
# LIBS += -lsubunit -lrt -lm -lpthread
endif

.PHONY: all install dvi uninstall gcov_report test clean valgrind autoformat dist

all: install

dvi:
	open dvi.md

install:
	mkdir -p $(BUILD_DIR)
	cd $(VIEW_DIR) && qmake && make
	mv $(VIEW_DIR)/$(CALCULATOR_EXE) $(BUILD_DIR)

uninstall: clean
	rm -rf $(BUILD_DIR)

calculator.o:
	$(CXX) -c $(MODEL_DIR)/calculator.cc -o $(TEST_DIR)/calculator.o

credit.o:
	$(CXX) -c $(MODEL_DIR)/credit.cc -o $(TEST_DIR)/credit.o

tests: calculator.o credit.o
	cd $(TEST_DIR) && $(CXX) $(TEST_SRC) credit.o calculator.o -lgtest -o $(TEST_EXECUTABLE)
	$(TEST_DIR)/$(TEST_EXECUTABLE)

clean_tests:
	rm -rf $(TEST_DIR)/*.o $(TEST_DIR)/$(TEST_EXECUTABLE)

clean: clean_tests
	cd $(VIEW_DIR) && qmake && make clean
	rm -rf $(VIEW_DIR)/.qmake.stash $(VIEW_DIR)/Makefile
	

autoformat:
	find . -type f -name "*.cc" -o -name "*.h" | xargs clang-format -style=Google -i

dist:
	mkdir -p source
	cp -r Makefile view model controller tests dvi.md main.cc source
	tar -cf source.tar source
	rm -rf source
