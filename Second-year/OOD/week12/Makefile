GTEST_DIR = /home/pi/school/Second-year/OOD/googletest/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
            $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

HW = hw12

SRCS = $(filter-out $(HW).cc, $(wildcard *.cc))
OBJS = $(SRCS:.cc=.o)

.PHONY: all clean check setup run

all : $(HW)

$(HW): $(HW).cc $(filter-out test.o, $(OBJS))
	$(CC) --std=c++17 $^ -o $@

%.o: %.cc
	$(CC) --std=c++17 -c $< -o $@

test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

test: $(OBJS) gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

clean:
	rm -f gtest.a gtest_main.a *.o $(HW) test $(HW).zip

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

run:
	@$(MAKE) --no-print-directory check || { echo "\033[31m코드 스타일이 잘못됨\033[0m"; exit 1; }
	@$(MAKE) --no-print-directory all || { echo "\033[31m$(HW) 빌드 중 오류 발생\033[0m"; exit 1; }
	@$(MAKE) --no-print-directory test || { echo "\033[31mtest 빌드 중 오류 발생\033[0m"; exit 1; }
	@./$(HW) || { echo "\033[31m$(HW) 실행 중 오류 발생\033[0m"; exit 1; }
	@./test || { echo "\033[31mtest 실행 중 오류 발생\033[0m"; exit 1; }
	@# @$(MAKE) --no-print-directory clean
	@if [ -f $(HW).zip ]; then \
		rm $(HW).zip; \
	fi
	@zip -r -q $(HW).zip *.cc *.h Makefile || { echo "\033[32m아마도 zip이 안깔려있어서 그런건데 'sudo apt install zip'으로 설치해주세요\033[0m"; exit 1; }
	@echo "\033[32m성공했습니다! $(HW).zip을 이름 바꿔서 제출하세요.\033[0m"
