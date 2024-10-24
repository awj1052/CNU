GTEST_DIR = /home/pi/school/Second-year/OOD/googletest/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all : hw7

hw7: hw7.cc int_node.o string_node.o node.o tree_util.o
	$(CC) --std=c++17 $^ -o $@

%.o: %.cc
	$(CC) --std=c++17 -c $< -o $@

test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

test: test.o int_node.o string_node.o node.o tree_util.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -g -fsanitize=address --std=c++17 $^ -o $@

clean:
	rm -f gtest.a gtest_main.a *.o hw7 test

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

check:
	cpplint --filter=-legal/copyright,-build/header_guard,-build/include_subdir,-build/include_order *.cc *.h

.PHONY: all clean check


