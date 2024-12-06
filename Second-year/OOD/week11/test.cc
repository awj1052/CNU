#include <sstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <deque>

#include "gtest/gtest.h"
#include "sort.h"

class SortTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

template <typename T, bool B>
class Ordering {
 public:
    int operator()(const T& x, const T& y) {
        return B ? (x > y) : (x < y);
    }
};

template <typename T>
std::string my_string(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template <typename T, typename N>
std::string SortAndResult(T* container) {
    std::string res = "";
    Sort<T, N>(container->begin(), container->end());
    for (auto n : *container) {
        res += my_string(n) + " ";
    }
    return res;
}

TEST_F(SortTest, ArrayTest1) {
    std::array<std::string, 5> arr = {"HH", "BB", "ss", "QQ", "gg"};
    std::string res = SortAndResult<std::array<std::string, 5>,
                                    Ordering<std::string, true>>(&arr);
    EXPECT_EQ(res, "BB HH QQ gg ss ");
}

TEST_F(SortTest, ArrayTest2) {
    std::array<std::string, 5> arr = {"HH", "BB", "ss", "QQ", "gg"};
    std::string res = SortAndResult<std::array<std::string, 5>,
                                    Ordering<std::string, false>>(&arr);
    EXPECT_EQ(res, "ss gg QQ HH BB ");
}

TEST_F(SortTest, ArrayTest3) {
    std::array<float, 5> arr = {0, 3.14f, 2.718f, -1.2f, -0.9f};
    std::string res = SortAndResult<std::array<float, 5>,
                                    Ordering<float, true>>(&arr);
    EXPECT_EQ(res, "-1.2 -0.9 0 2.718 3.14 ");
}

TEST_F(SortTest, ArrayTest4) {
    std::array<float, 5> arr = {0, 3.14f, 2.718f, -1.2f, -0.9f};
    std::string res = SortAndResult<std::array<float, 5>,
                                    Ordering<float, false>>(&arr);
    EXPECT_EQ(res, "3.14 2.718 0 -0.9 -1.2 ");
}

TEST_F(SortTest, VectorTest1) {
    std::vector<float> vec = {0, 3.14f, 2.718f, -1.2f, -0.9f};
    std::string res = SortAndResult<std::vector<float>,
                                    Ordering<float, true>>(&vec);
    EXPECT_EQ(res, "-1.2 -0.9 0 2.718 3.14 ");
}

TEST_F(SortTest, VectorTest2) {
    std::vector<float> vec = {0, 3.14f, 2.718f, -1.2f, -0.9f};
    std::string res = SortAndResult<std::vector<float>,
                                    Ordering<float, false>>(&vec);
    EXPECT_EQ(res, "3.14 2.718 0 -0.9 -1.2 ");
}

TEST_F(SortTest, VectorTest3) {
    std::vector<std::string> vec = {"HH", "BB", "ss", "QQ", "gg"};
    std::string res = SortAndResult<std::vector<std::string>,
                                    Ordering<std::string, true>>(&vec);
    EXPECT_EQ(res, "BB HH QQ gg ss ");
}

TEST_F(SortTest, VectorTest4) {
    std::vector<std::string> vec = {"HH", "BB", "ss", "QQ", "gg"};
    std::string res = SortAndResult<std::vector<std::string>,
                                    Ordering<std::string, false>>(&vec);
    EXPECT_EQ(res, "ss gg QQ HH BB ");
}

TEST_F(SortTest, ListTest1) {
    std::list<int> lst = {1, 3, 5, 2, 6, 8, 4, 0};
    std::string res = SortAndResult<std::list<int>,
                                    Ordering<int, true>>(&lst);
    EXPECT_EQ(res, "0 1 2 3 4 5 6 8 ");
}

TEST_F(SortTest, ListTest2) {
    std::list<int> lst = {1, 3, 5, 2, 6, 8, 4, 0};
    std::string res = SortAndResult<std::list<int>,
                                    Ordering<int, false>>(&lst);
    EXPECT_EQ(res, "8 6 5 4 3 2 1 0 ");
}

TEST_F(SortTest, ListTest3) {
    std::list<std::string> lst = {"A", "B", "C", "D", "Yee"};
    std::string res = SortAndResult<std::list<std::string>,
                                    Ordering<std::string, true>>(&lst);
    EXPECT_EQ(res, "A B C D Yee ");
}

TEST_F(SortTest, ListTest4) {
    std::list<std::string> lst = {"A", "B", "C", "D", "Yee"};
    std::string res = SortAndResult<std::list<std::string>,
                                    Ordering<std::string, false>>(&lst);
    EXPECT_EQ(res, "Yee D C B A ");
}

TEST_F(SortTest, DequeTest1) {
    std::deque<std::string> deq = {"A", "B", "C", "D", "Yee"};
    std::string res = SortAndResult<std::deque<std::string>,
                                    Ordering<std::string, true>>(&deq);
    EXPECT_EQ(res, "A B C D Yee ");
}

TEST_F(SortTest, DequeTest2) {
    std::deque<std::string> deq = {"A", "B", "C", "D", "Yee"};
    std::string res = SortAndResult<std::deque<std::string>,
                                    Ordering<std::string, false>>(&deq);
    EXPECT_EQ(res, "Yee D C B A ");
}

TEST_F(SortTest, DequeTest3) {
    std::deque<int> deq = {1, 3, 5, 2, 6, 8, 4, 0};
    std::string res = SortAndResult<std::deque<int>,
                                    Ordering<int, true>>(&deq);
    EXPECT_EQ(res, "0 1 2 3 4 5 6 8 ");
}

TEST_F(SortTest, DequeTest4) {
    std::deque<int> deq = {1, 3, 5, 2, 6, 8, 4, 0};
    std::string res = SortAndResult<std::deque<int>,
                                    Ordering<int, false>>(&deq);
    EXPECT_EQ(res, "8 6 5 4 3 2 1 0 ");
}
