GTEST_DIR = /home/pi/school/Second-year/OOD/googletest/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all : hw6

hw6: hw6.cc int_node.o string_node.o node.o tree_util.o
	$(CC) --std=c++17 $^ -o $@

tree_util.o : tree_util.cc
	$(CC) --std=c++17 -c $^ -o $@

int_node.o : int_node.cc
	$(CC) --std=c++17 -c $^ -o $@

string_node.o : string_node.cc
	$(CC) --std=c++17 -c $^ -o $@

node.o : node.cc
	$(CC) --std=c++17 -c $^ -o $@

test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

test: test.o int_node.o string_node.o node.o tree_util.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -g -fsanitize=address --std=c++17 $^ -o $@

clean:
	 rm -f gtest.a gtest_main.a *.o hw6 test

gtest-all.o: $(GTEST_SRCS_) 
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean


